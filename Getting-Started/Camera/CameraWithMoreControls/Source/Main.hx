package;

import lime.ui.MouseButton;
// import js.Browser;
// import js.html.DOMElement;
import lime.ui.MouseWheelMode;
import haxe.Timer;
import lime.app.Application;
import lime.graphics.Image;
import lime.graphics.RenderContext;
import lime.graphics.WebGL2RenderContext;
import lime.graphics.opengl.GLBuffer;
import lime.graphics.opengl.GLProgram;
import lime.graphics.opengl.GLShader;
import lime.graphics.opengl.GLTexture;
import lime.math.Matrix4;
import lime.math.Vector4;
import lime.ui.KeyCode;
import lime.ui.KeyModifier;
import lime.utils.Assets;
import lime.utils.Float32Array;

/**
 * A simple triangle demo after Learn OpenGL (ch 5) by Joey DeVries
 */
class Main extends Application {
	// Model data
	var vbo:GLBuffer;
	var ebo:GLBuffer;
	var texture:GLTexture;
	var texture2:GLTexture;
	var program:GLProgram;
	var image:Image;
	var image2:Image;
	var trans:Matrix4;
	var vec:Vector4;
	var model:Matrix4;
	var view:Matrix4;
	var proj:Matrix4;
	var transMat:Array<Int>;
	var cubePositions:Array<Array<Float>>;
	var cameraPos:Vector4;
	var cameraFront:Vector4;
	var cameraUp:Vector4;
	var deltaTime:Float;
	var currentFrame:Float;
	var lastFrame:Float;
	var firstMouse:Bool;
	var lastX:Float;
	var lastY:Float;
	var xOffset:Float;
	var yOffset:Float;
	var sensitivity:Float;
	var yaw:Float;
	var pitch:Float;
	var fov:Float;

	// Key press state flags
	var moveLeft:Bool = false;
	var moveRight:Bool = false;
	var moveForward:Bool = false;
	var moveBackward:Bool = false;

	// Make sure you only do initialization once
	var initialized:Bool;

	public function new() {
		super();

		initialized = false;
	}

	/**
	 * Create a GL shader.
	 * 
	 * @param gl the GL rendering context
	 * @param source GLSL source text
	 * @param type type of shader to compile, usually gl.VERTEX_SHADER or gl.FRAGMENT_SHADER
	 * @return GLShader
	 */
	function glCreateShader(gl:WebGL2RenderContext, source:String, type:Int):GLShader {
		var shader = gl.createShader(type);
		gl.shaderSource(shader, source);
		gl.compileShader(shader);

		if (gl.getShaderParameter(shader, gl.COMPILE_STATUS) == 0) {
			trace(gl.getShaderInfoLog(shader));
			return null;
		}

		return shader;
	}

	/**
	 * Create a GL program with vertex and fragment shaders.
	 * @param gl the GL rendering context
	 * @param vertexSource vertex shader GLSL source
	 * @param fragmentSource fragment shader GLSL source
	 * @return Null<GLProgram> the compiled and linked program or null if unsuccessful.
	 */
	function glCreateProgram(gl:WebGL2RenderContext, vertexSource:String, fragmentSource:String):Null<GLProgram> {
		var vs = glCreateShader(gl, vertexSource, gl.VERTEX_SHADER);
		var fs = glCreateShader(gl, fragmentSource, gl.FRAGMENT_SHADER);

		if (vs == null || fs == null) {
			return null;
		}

		var program = gl.createProgram();
		gl.attachShader(program, vs);
		gl.attachShader(program, fs);

		gl.deleteShader(vs);
		gl.deleteShader(fs);

		gl.linkProgram(program);

		if (gl.getProgramParameter(program, gl.LINK_STATUS) == 0) {
			trace(gl.getProgramInfoLog(program));
			trace("VALIDATE_STATUS: " + gl.getProgramParameter(program, gl.VALIDATE_STATUS));
			trace("ERROR: " + gl.getError());
			return null;
		}

		return program;
	}

	function initialize(gl:WebGL2RenderContext):Void {
		deltaTime = 0.0;
		lastFrame = 0.0;

		firstMouse = true;

		var vertices:Array<Float> = [
			-0.5, -0.5, -0.5, 0.0, 0.0,
			 0.5, -0.5, -0.5, 1.0, 0.0,
			 0.5,  0.5, -0.5, 1.0, 1.0,
			 0.5,  0.5, -0.5, 1.0, 1.0,
			-0.5,  0.5, -0.5, 0.0, 1.0,
			-0.5, -0.5, -0.5, 0.0, 0.0,

			-0.5, -0.5,  0.5, 0.0, 0.0,
			 0.5, -0.5,  0.5, 1.0, 0.0,
			 0.5,  0.5,  0.5, 1.0, 1.0,
			 0.5,  0.5,  0.5, 1.0, 1.0,
			-0.5,  0.5,  0.5, 0.0, 1.0,
			-0.5, -0.5,  0.5, 0.0, 0.0,

			-0.5,  0.5,  0.5, 1.0, 0.0,
			-0.5,  0.5, -0.5, 1.0, 1.0,
			-0.5, -0.5, -0.5, 0.0, 1.0,
			-0.5, -0.5, -0.5, 0.0, 1.0,
			-0.5, -0.5,  0.5, 0.0, 0.0,
			-0.5,  0.5,  0.5, 1.0, 0.0,

			 0.5,  0.5,  0.5, 1.0, 0.0,
			 0.5,  0.5, -0.5, 1.0, 1.0,
			 0.5, -0.5, -0.5, 0.0, 1.0,
			 0.5, -0.5, -0.5, 0.0, 1.0,
			 0.5, -0.5,  0.5, 0.0, 0.0,
			 0.5,  0.5,  0.5, 1.0, 0.0,

			-0.5, -0.5, -0.5, 0.0, 1.0,
			 0.5, -0.5, -0.5, 1.0, 1.0,
			 0.5, -0.5,  0.5, 1.0, 0.0,
			 0.5, -0.5,  0.5, 1.0, 0.0,
			-0.5, -0.5,  0.5, 0.0, 0.0,
			-0.5, -0.5, -0.5, 0.0, 1.0,

			-0.5,  0.5, -0.5, 0.0, 1.0,
			 0.5,  0.5, -0.5, 1.0, 1.0,
			 0.5,  0.5,  0.5, 1.0, 0.0,
			 0.5,  0.5,  0.5, 1.0, 0.0,
			-0.5,  0.5,  0.5, 0.0, 0.0,
			-0.5,  0.5, -0.5, 0.0, 1.0
		];

		var verticesData = new Float32Array(vertices);

		cubePositions = [
			[0.0, 0.0, -10.0], [2.0, 5.0, -15.0], [-1.5, -2.2, -2.5], [-3.8, -2.0, -12.3], [2.4, -0.4, -3.5], [-1.7, 3.0, -7.5], [1.3, -2.0, -2.5],
			[1.5, 2.0, -2.5], [1.5, 0.2, -1.5], [-1.3, 1.0, -1.5]];

		gl.enable(gl.DEPTH_TEST);

		// Vertex Shader
		var vs = "#version 300 es
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec2 aTexCoord; 
out vec2 TexCoord;
uniform mat4 model;
uniform mat4 view;
uniform mat4 proj;
void main()
{
	gl_Position =  proj * view * model * vec4(aPos, 1.0);
	TexCoord = aTexCoord;
}
";

		// Fragment Shader
		var fs = "#version 300 es
precision mediump float;
out vec4 FragColor;
in vec2 TexCoord;
uniform sampler2D texture1;
uniform sampler2D texture2;
void main() 
{
    FragColor = mix(texture(texture1, TexCoord), texture(texture2, TexCoord), 0.2);
}
";

		cameraPos = new Vector4(0.0, 0.0, 10.0, 1.0);
		cameraFront = new Vector4(0.0, 0.0, -1.0, 1.0);
		cameraUp = new Vector4(0.0, 1.0, 0.0, 1.0);

		// create a program with vertex and fragment shaders
		program = glCreateProgram(gl, vs, fs);

		lastX = Application.current.window.width / 2;
		lastY = Application.current.window.height / 2;

		pitch = 0.0;
		yaw = -90.0;
		fov = 45.0;

		// create the vbo
		vbo = gl.createBuffer();

		// bind and buffer the vertices data to the vbo
		gl.bindBuffer(gl.ARRAY_BUFFER, vbo);
		gl.bufferData(gl.ARRAY_BUFFER, verticesData, gl.STATIC_DRAW);

		gl.bindBuffer(gl.ARRAY_BUFFER, null);

		// position attribute
		gl.vertexAttribPointer(0, 3, gl.FLOAT, false, 5 * Float32Array.BYTES_PER_ELEMENT, 0);
		gl.enableVertexAttribArray(0);

		if (image == null && preloader.complete) {
			image = Assets.getImage("assets/container.jpg");

			// create the texture
			texture = gl.createTexture();
			gl.activeTexture(gl.TEXTURE0);
			gl.bindTexture(gl.TEXTURE_2D, texture);

			// config mimap and other options
			gl.texParameteri(gl.TEXTURE_2D, gl.TEXTURE_WRAP_S, gl.REPEAT);
			gl.texParameteri(gl.TEXTURE_2D, gl.TEXTURE_WRAP_T, gl.REPEAT);

			gl.texParameteri(gl.TEXTURE_2D, gl.TEXTURE_MIN_FILTER, gl.LINEAR_MIPMAP_LINEAR);
			gl.texParameteri(gl.TEXTURE_2D, gl.TEXTURE_MAG_FILTER, gl.LINEAR);
			gl.texImage2D(gl.TEXTURE_2D, 0, gl.RGB, image.width, image.height, 0, gl.RGB, gl.UNSIGNED_BYTE, image.src);

			gl.generateMipmap(gl.TEXTURE_2D);
		}

		if (image2 == null && preloader.complete) {
			image2 = Assets.getImage("assets/awesomeface.png");

			// create the texture
			texture2 = gl.createTexture();
			gl.activeTexture(gl.TEXTURE0);
			gl.bindTexture(gl.TEXTURE_2D, texture2);

			// config mimap and other options
			gl.texParameteri(gl.TEXTURE_2D, gl.TEXTURE_WRAP_S, gl.REPEAT);
			gl.texParameteri(gl.TEXTURE_2D, gl.TEXTURE_WRAP_T, gl.REPEAT);

			gl.texParameteri(gl.TEXTURE_2D, gl.TEXTURE_MIN_FILTER, gl.LINEAR_MIPMAP_LINEAR);
			gl.texParameteri(gl.TEXTURE_2D, gl.TEXTURE_MAG_FILTER, gl.LINEAR);
			gl.texImage2D(gl.TEXTURE_2D, 0, gl.RGBA, image2.width, image2.height, 0, gl.RGBA, gl.UNSIGNED_BYTE, image2.src);

			gl.generateMipmap(gl.TEXTURE_2D);

			initialized = true;
		}

		gl.useProgram(program);

		gl.uniform1i(gl.getUniformLocation(program, "texture1"), 0);
		gl.uniform1i(gl.getUniformLocation(program, "texture2"), 1);
	}

	function createPerspectiveZO(mat:Matrix4, fovy:Float, aspect:Float, zNear:Float, zFar:Float):Void {
		if (Math.abs(aspect - (Math.pow(2, -23))) > 0.0) {
			var top = Math.tan(fovy) * zNear;
			var bottom = -top;
			var right = top * aspect;
			var left = -right;

			mat[0] = 2.0 * zNear / (right - left);
			mat[5] = 2.0 * zNear / (top - bottom);
			mat[8] = (right + left) / (right - left);
			mat[9] = (top + bottom) / (top - bottom);
			mat[10] = -(zFar + zNear) / (zFar - zNear);
			mat[11] = -1.0;
			mat[14] = -2 * zFar * zNear / (zFar - zNear);
		}
	}

	/**
	 * createLookAtMatrix is an alternative to Matrix4.pointAt(). I could not
	 * figure out how to pass the correct parameters to pointAt() whereas this function
	 * works with what you already have.
	 * 
	 * @param cameraPos 
	 * @param target 
	 * @param up 
	 * @return Matrix4
	 */
	function createLookAtMatrix(cameraPos:Vector4, target:Vector4, up:Vector4):Matrix4 {
		var cameraDir = cameraPos.subtract(target);
		cameraDir.normalize();
		var cameraRight = up.crossProduct(cameraDir);
		cameraRight.normalize();
		var cameraUp = cameraDir.crossProduct(cameraRight);
		cameraUp.normalize();
		var cameraMat = new Matrix4();

		cameraMat[0] = cameraRight.x;
		cameraMat[1] = cameraUp.x;
		cameraMat[2] = cameraDir.x;
		cameraMat[3] = 0.0;
		cameraMat[4] = cameraRight.y;
		cameraMat[5] = cameraUp.y;
		cameraMat[6] = cameraDir.y;
		cameraMat[7] = 0.0;
		cameraMat[8] = cameraRight.z;
		cameraMat[9] = cameraUp.z;
		cameraMat[10] = cameraDir.z;
		cameraMat[11] = 0.0;
		cameraMat[12] = -cameraPos.x;
		cameraMat[13] = -cameraPos.y;
		cameraMat[14] = -cameraPos.z;
		cameraMat[15] = 1.0;

		return cameraMat;
	}

	function moveCamera():Void {
		var camSpeed = 10 * deltaTime;
		if (moveForward) {
			var tgt = cameraFront.clone();
			tgt.normalize();
			tgt.scaleBy(camSpeed);
			cameraPos = cameraPos.add(tgt);
		}
		if (moveBackward) {
			var tgt = cameraFront.clone();
			tgt.normalize();
			tgt.scaleBy(camSpeed);
			cameraPos = cameraPos.subtract(tgt);
		}
		if (moveLeft) {
			var m = cameraFront.crossProduct(cameraUp);
			m.normalize();
			m.scaleBy(camSpeed);
			cameraPos = cameraPos.subtract(m);
		}
		if (moveRight) {
			var m = cameraFront.crossProduct(cameraUp);
			m.normalize();
			m.scaleBy(camSpeed);
			cameraPos = cameraPos.add(m);
		}
	}

	public override function update(deltaTime:Int):Void {
		this.deltaTime = deltaTime * 1.0 / 1000.0;
		if (moveLeft || moveRight || moveForward || moveBackward) {
			moveCamera();
		}
	}

	/**
	 * onKeyDown converts the key press to a state because the event is only sent on the press.
	 * If you hold it down there won't be more events, so you need to create a state flag
	 * to cope with long holds. The onKeyUp() method resets the flag.
	 * 
	 * FYI - I cut and pasted this from the lime sample and it used the arrow keys so you'll
	 *       need to update this if you want WASD.
	 * 
	 * @param key 
	 * @param modifier 
	 */
	public override function onKeyDown(key:KeyCode, modifier:KeyModifier):Void {
		switch (key) {
			case LEFT:
				moveLeft = true;
			case RIGHT:
				moveRight = true;
			case UP:
				moveForward = true;
			case DOWN:
				moveBackward = true;
			default:
		}
	}

	public override function onKeyUp(key:KeyCode, modifier:KeyModifier):Void {
		switch (key) {
			case LEFT:
				moveLeft = false;
			case RIGHT:
				moveRight = false;
			case UP:
				moveForward = false;
			case DOWN:
				moveBackward = false;
			default:
		};
	}

	// public override function onMouseDown(x:Float, y:Float, button:MouseButton) {
	// 	var limeElement:DOMElement = js.Browser.document.getElementById("content");
	// 	limeElement.requestPointerLock();
	// }

	public override function onMouseMove(x:Float, y:Float) {
		trace("hi");

		if (firstMouse) {
			lastX = x;
			lastY = y;
			firstMouse = false;
		}
		sensitivity = 0.1;
		xOffset = x - lastX;
		yOffset = lastY - y;
		lastX = x;
		lastY = y;
		xOffset *= sensitivity;
		yOffset *= sensitivity;
		yaw += xOffset;
		pitch += yOffset;
		if (pitch > 89.0)
			pitch = 89.0;
		if (pitch < -89.0)
			pitch = -89.0;
		var direction:Vector4 = new Vector4();
		direction.x = Math.cos(yaw * Math.PI / 180) * Math.cos(pitch * Math.PI / 180);
		direction.y = Math.sin(pitch * Math.PI / 180);
		direction.z = Math.sin(yaw * Math.PI / 180) * Math.cos(pitch * Math.PI / 180);
		direction.normalize();
		cameraFront = direction;
	}

	public override function onMouseWheel(deltaX:Float, deltaY:Float, deltaMode:MouseWheelMode) {
		fov -= deltaY;
		if (fov > 45.0) {
			fov = 45.0;
		}
		if (fov < 1.0) {
			fov = 1.0;
		}
	}

	public override function render(context:RenderContext):Void {
		switch (context.type) {
			case OPENGL, OPENGLES, WEBGL:
				var gl:WebGL2RenderContext = context.webgl2;

				if (!initialized) {
					initialize(gl);
				}

				gl.clearColor(0.75, 1, 0, 1);
				gl.clear(gl.COLOR_BUFFER_BIT | gl.DEPTH_BUFFER_BIT);

				currentFrame = Timer.stamp();
				// deltaTime = currentFrame - lastFrame;
				lastFrame = currentFrame;

				gl.useProgram(program);

				gl.bindBuffer(gl.ARRAY_BUFFER, vbo);

				// position attribute
				gl.vertexAttribPointer(0, 3, gl.FLOAT, false, 5 * Float32Array.BYTES_PER_ELEMENT, 0);
				gl.enableVertexAttribArray(0);

				// texture coord attribute
				gl.vertexAttribPointer(1, 2, gl.FLOAT, false, 5 * Float32Array.BYTES_PER_ELEMENT, 3 * Float32Array.BYTES_PER_ELEMENT);
				gl.enableVertexAttribArray(1);

				// bind the textures
				gl.activeTexture(gl.TEXTURE0);
				gl.bindTexture(gl.TEXTURE_2D, texture);

				gl.activeTexture(gl.TEXTURE1);
				gl.bindTexture(gl.TEXTURE_2D, texture2);

				view = new Matrix4();
				view.identity();
				// I replaced this with my own lookat function. I think Lime's is ok but I could not figured out
				// what parameters to pass it.
				// view.pointAt(new Vector4(0.0, 0.0, 0.0), cameraPos.add(cameraFront), new Vector4(0.0, 1.0, 0.0));
				view = createLookAtMatrix(cameraPos, cameraPos.add(cameraFront), new Vector4(0.0, 1.0, 0.0));

				proj = new Matrix4();
				proj.identity();
				createPerspectiveZO(proj, fov * Math.PI / 180, Application.current.window.width / Application.current.window.height, 0.1, 100.0);

				gl.uniformMatrix4fv(gl.getUniformLocation(program, "view"), false, view);
				gl.uniformMatrix4fv(gl.getUniformLocation(program, "proj"), false, proj);

				// start drawing
				for (i in 0...cubePositions.length) {
					var angle = 20.0 * i;
					var model = new Matrix4();
					model.identity();
					model.appendTranslation(cubePositions[i][0], cubePositions[i][1], cubePositions[i][2]);
					model.appendRotation(angle, new Vector4(1.0, 0.3, 0.5, 1.0));
					gl.uniformMatrix4fv(gl.getUniformLocation(program, "model"), false, model);
					gl.drawArrays(gl.TRIANGLES, 0, 36);
				}

			default:
		}
	}
}

