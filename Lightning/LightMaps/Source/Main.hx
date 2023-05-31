package;

import lime.utils.Assets;
import OpenGLUtils.glTextureFromImageRepeat;
import lime.graphics.Image;
import lime.graphics.opengl.GLTexture;
import OpenGLUtils.glTextureFromImage;
import haxe.Timer;
import lime.math.Vector4;
import lime.app.Application;
import lime.graphics.RenderContext;
import lime.graphics.WebGLRenderContext;
import lime.graphics.opengl.GLBuffer;
import lime.graphics.opengl.GLProgram;
import lime.math.Matrix4;
import lime.ui.KeyCode;
import lime.ui.KeyModifier;
import lime.utils.Float32Array;

using Lambda;

class Main extends Application {
	// Model data
	var vbo:GLBuffer;
	var program:GLProgram;
	var model:Matrix4;
	var view:Matrix4;
	var proj:Matrix4;
	var deltaTime:Float;
	var currentFrame:Float;
	var lastFrame:Float;
	var verticesData:Float32Array;
	var cube:SimpleCubeProgram;
	var lightCube:LightProgram;
	var cubes:Array<SimpleCubeProgram>;
	var image:Image;
	var image2:Image;
	var texture:GLTexture;
	var texture2:GLTexture;

	// Make sure you only do initialization once
	var initialized:Bool;

	// just for neovim
	static function main() {}

	public function new() {
		super();

		initialized = false;
	}

	function initialize(gl:WebGLRenderContext):Void {
		deltaTime = 0.0;
		lastFrame = 0.0;

		Camera.init();

		Application.current.window.mouseLock = true;

		cube = new SimpleCubeProgram(gl);
		lightCube = new LightProgram(gl);

		var vertices = [
			-0.5, -0.5, -0.5,  0.0,  0.0, -1.0, 0.0, 0.0,
			 0.5, -0.5, -0.5,  0.0,  0.0, -1.0, 1.0, 0.0,
			 0.5,  0.5, -0.5,  0.0,  0.0, -1.0, 1.0, 1.0,
			 0.5,  0.5, -0.5,  0.0,  0.0, -1.0, 1.0, 1.0,
			-0.5,  0.5, -0.5,  0.0,  0.0, -1.0, 0.0, 1.0,
			-0.5, -0.5, -0.5,  0.0,  0.0, -1.0, 0.0, 0.0,

			-0.5, -0.5,  0.5,  0.0,  0.0,  1.0, 0.0, 0.0,
			 0.5, -0.5,  0.5,  0.0,  0.0,  1.0, 1.0, 0.0,
			 0.5,  0.5,  0.5,  0.0,  0.0,  1.0, 1.0, 1.0,
			 0.5,  0.5,  0.5,  0.0,  0.0,  1.0, 1.0, 1.0,
			-0.5,  0.5,  0.5,  0.0,  0.0,  1.0, 0.0, 1.0,
			-0.5, -0.5,  0.5,  0.0,  0.0,  1.0, 0.0, 0.0,

			-0.5,  0.5,  0.5, -1.0,  0.0,  0.0, 1.0, 0.0,
			-0.5,  0.5, -0.5, -1.0,  0.0,  0.0, 1.0, 1.0,
			-0.5, -0.5, -0.5, -1.0,  0.0,  0.0, 0.0, 1.0,
			-0.5, -0.5, -0.5, -1.0,  0.0,  0.0, 0.0, 1.0,
			-0.5, -0.5,  0.5, -1.0,  0.0,  0.0, 0.0, 0.0,
			-0.5,  0.5,  0.5, -1.0,  0.0,  0.0, 1.0, 0.0,

			 0.5,  0.5,  0.5,  1.0,  0.0,  0.0, 1.0, 0.0,
			 0.5,  0.5, -0.5,  1.0,  0.0,  0.0, 1.0, 1.0,
			 0.5, -0.5, -0.5,  1.0,  0.0,  0.0, 0.0, 1.0,
			 0.5, -0.5, -0.5,  1.0,  0.0,  0.0, 0.0, 1.0,
			 0.5, -0.5,  0.5,  1.0,  0.0,  0.0, 0.0, 0.0,
			 0.5,  0.5,  0.5,  1.0,  0.0,  0.0, 1.0, 0.0,

			-0.5, -0.5, -0.5,  0.0, -1.0,  0.0, 0.0, 1.0,
			 0.5, -0.5, -0.5,  0.0, -1.0,  0.0, 1.0, 1.0,
			 0.5, -0.5,  0.5,  0.0, -1.0,  0.0, 1.0, 0.0,
			 0.5, -0.5,  0.5,  0.0, -1.0,  0.0, 1.0, 0.0,
			-0.5, -0.5,  0.5,  0.0, -1.0,  0.0, 0.0, 0.0,
			-0.5, -0.5, -0.5,  0.0, -1.0,  0.0, 0.0, 1.0,

			-0.5,  0.5, -0.5,  0.0,  1.0,  0.0, 0.0, 1.0,
			 0.5,  0.5, -0.5,  0.0,  1.0,  0.0, 1.0, 1.0,
			 0.5,  0.5,  0.5,  0.0,  1.0,  0.0, 1.0, 0.0,
			 0.5,  0.5,  0.5,  0.0,  1.0,  0.0, 1.0, 0.0,
			-0.5,  0.5,  0.5,  0.0,  1.0,  0.0, 0.0, 0.0,
			-0.5,  0.5, -0.5,  0.0,  1.0,  0.0, 0.0, 1.0
		];

		var verticesData = new Float32Array(vertices);

		gl.enable(gl.DEPTH_TEST);

		// create the vbo
		vbo = gl.createBuffer();

		// bind and buffer the vertices data to the vbo
		gl.bindBuffer(gl.ARRAY_BUFFER, vbo);
		gl.bufferData(gl.ARRAY_BUFFER, verticesData, gl.STATIC_DRAW);
		gl.bindBuffer(gl.ARRAY_BUFFER, null);

		if (image == null && preloader.complete) {
			image = Assets.getImage("assets/container2.png");

			// create the texture
			texture = gl.createTexture();
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
			image2 = Assets.getImage("assets/specular.png");

			// create the texture
			texture2 = gl.createTexture();
			gl.bindTexture(gl.TEXTURE_2D, texture2);

			// config mimap and other options
			gl.texParameteri(gl.TEXTURE_2D, gl.TEXTURE_WRAP_S, gl.REPEAT);
			gl.texParameteri(gl.TEXTURE_2D, gl.TEXTURE_WRAP_T, gl.REPEAT);

			gl.texParameteri(gl.TEXTURE_2D, gl.TEXTURE_MIN_FILTER, gl.LINEAR_MIPMAP_LINEAR);
			gl.texParameteri(gl.TEXTURE_2D, gl.TEXTURE_MAG_FILTER, gl.LINEAR);
			gl.texImage2D(gl.TEXTURE_2D, 0, gl.RGB, image.width, image.height, 0, gl.RGB, gl.UNSIGNED_BYTE, image.src);

			gl.generateMipmap(gl.TEXTURE_2D);

			initialized = true;
		}
	}

	public override function update(deltaTime:Int):Void {
		this.deltaTime = deltaTime * 1.0 / 1000.0;
		if (Camera.moveLeft || Camera.moveRight || Camera.moveForward || Camera.moveBackward) {
			Camera.moveCamera(this.deltaTime);
		}
	}

	public override function onKeyDown(key:KeyCode, modifier:KeyModifier):Void {
		switch (key) {
			case LEFT | A:
				Camera.moveLeft = true;
			case RIGHT | D:
				Camera.moveRight = true;
			case UP | W:
				Camera.moveForward = true;
			case DOWN | S:
				Camera.moveBackward = true;
			default:
		}
	}

	public override function onKeyUp(key:KeyCode, modifier:KeyModifier):Void {
		switch (key) {
			case LEFT | A:
				Camera.moveLeft = false;
			case RIGHT | D:
				Camera.moveRight = false;
			case UP | W:
				Camera.moveForward = false;
			case DOWN | S:
				Camera.moveBackward = false;
			default:
		};
	}

	public override function onMouseMove(x:Float, y:Float) {
		Camera.onMouseMove(x, y);
	}

	public override function render(context:RenderContext):Void {
		switch (context.type) {
			case OPENGL, OPENGLES, WEBGL:
				var gl:WebGLRenderContext = context.webgl;

				if (!initialized) {
					initialize(gl);
				}

				// clear the screen
				gl.clearColor(0.0, 0.0, 0.0, 1);
				gl.clear(gl.COLOR_BUFFER_BIT | gl.DEPTH_BUFFER_BIT);

				cube.use();

				model = new Matrix4();
				model.identity();
				model.appendTranslation(1.0, 1.0, 1.0);
				model.appendScale(4.0, 4.0, 4.0);

				view = new Matrix4();
				view.identity();
				view = MatrixUtils.createLookAtMatrix(Camera.pos, Camera.pos.add(Camera.front), new Vector4(0.0, 1.0, 0.0));

				proj = new Matrix4();
				proj.identity();
				MatrixUtils.createPerspective(proj, Camera.fov * Math.PI / 180, Application.current.window.width / Application.current.window.height, 0.1,
					100.0);

				var lightX = Math.sin(Timer.stamp()) * 2.0;
				var lightZ = Math.cos(Timer.stamp()) * 1.5;

				var lightPos = [lightX, 10.0, lightZ];

				// the cube
				cube.render({
					vbo: vbo,
					modelMatrix: model,
					viewMatrix: view,
					projectionMatrix: proj,
					cameraPosition: Camera.pos,
					vertexBufferData: verticesData,
					objectColor: [1.0, 0.5, 0.31],
					lightColor: [1.0, 1.0, 1.0],
					lightPos: [for (i in lightPos) i],
					viewPos: MatrixUtils.vecToArray(Camera.pos),
					material: {
						specular: [0.5, 0.5, 0.5],
						shininess: 64.0
					},
					light: {
						ambient: [0.2, 0.2, 0.2],
						diffuse: [0.5, 0.5, 0.5],
						specular: [1.0, 1.0, 1.0]
					},
					diffuseMap: texture,
				});

				model = new Matrix4();
				model.identity();
				model.appendTranslation(lightPos[0], lightPos[1], lightPos[2]);
				model.appendScale(0.6, 0.6, 0.6);

				lightCube.use();

				// light cube
				lightCube.render({
					vbo: vbo,
					modelMatrix: model,
					viewMatrix: view,
					projectionMatrix: proj,
					cameraPosition: Camera.pos,
					vertexBufferData: verticesData,
				});

			default:
		}
	}
}