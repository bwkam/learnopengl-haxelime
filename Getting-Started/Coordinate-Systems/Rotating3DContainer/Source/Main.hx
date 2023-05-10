package;

import haxe.Timer;
import lime.math.Vector4;
import lime.math.Matrix4;
import lime.graphics.Image;
import lime.graphics.opengl.GLTexture;
import lime.utils.Assets;
import lime.app.Application;
import lime.graphics.RenderContext;
import lime.graphics.WebGL2RenderContext;
import lime.graphics.opengl.GLBuffer;
import lime.graphics.opengl.GLProgram;
import lime.graphics.opengl.GLShader;
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

		vec = new Vector4(1.0, 0.0, 0.0, 1.0);

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

		// create a program with vertex and fragment shaders
		program = glCreateProgram(gl, vs, fs);

		// create the vbo
		vbo = gl.createBuffer();

		// bind and buffer the vertices data to the vbo
		gl.bindBuffer(gl.ARRAY_BUFFER, vbo);
		gl.bufferData(gl.ARRAY_BUFFER, verticesData, gl.STATIC_DRAW);

		gl.bindBuffer(gl.ARRAY_BUFFER, null);

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
			var top = fovy * zNear;
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

	public override function render(context:RenderContext):Void {
		switch (context.type) {
			case OPENGL, OPENGLES, WEBGL:
				var gl:WebGL2RenderContext = context.webgl;

				if (!initialized) {
					initialize(gl);
				}

				gl.clearColor(0.75, 1, 0, 1);
				gl.clear(gl.COLOR_BUFFER_BIT | gl.DEPTH_BUFFER_BIT);

				gl.useProgram(program);

				gl.bindBuffer(gl.ARRAY_BUFFER, vbo);
				gl.bindBuffer(gl.ELEMENT_ARRAY_BUFFER, ebo);

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

				model = new Matrix4();
				model.identity();
				model.appendRotation(Timer.stamp() * -55.0, new Vector4(1.0, 0.0, 0.0, 1.0));

				view = new Matrix4();
				view.identity();
				view.appendTranslation(0.0, 0.0, -3.0);

				proj = new Matrix4();
				proj.identity();
				createPerspectiveZO(proj, 45.0 * js.lib.Math.PI / 180, Application.current.window.width / Application.current.window.height, 0.1, 100.0);

				gl.uniformMatrix4fv(gl.getUniformLocation(program, "model"), false, model);
				gl.uniformMatrix4fv(gl.getUniformLocation(program, "view"), false, view);
				gl.uniformMatrix4fv(gl.getUniformLocation(program, "proj"), false, proj);

				// start drawing
				gl.drawArrays(gl.TRIANGLES, 0, 36);

			default:
		}
	}
}

