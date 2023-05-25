package;

import lime.math.Vector4;
import lime.app.Application;
import lime.graphics.RenderContext;
import lime.graphics.WebGL2RenderContext;
import lime.graphics.opengl.GLBuffer;
import lime.graphics.opengl.GLProgram;
import lime.math.Matrix4;
import lime.ui.KeyCode;
import lime.ui.KeyModifier;
import lime.utils.Float32Array;

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

	// Make sure you only do initialization once
	var initialized:Bool;

	public function new() {
		super();

		initialized = false;
	}

	function initialize(gl:WebGL2RenderContext):Void {
		deltaTime = 0.0;
		lastFrame = 0.0;

		Camera.init();

		cube = new SimpleCubeProgram(gl);
		lightCube = new LightProgram(gl);

		var vertices = [
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

		gl.enable(gl.DEPTH_TEST);

		// create the vbo
		vbo = gl.createBuffer();

		// bind and buffer the vertices data to the vbo
		gl.bindBuffer(gl.ARRAY_BUFFER, vbo);
		gl.bufferData(gl.ARRAY_BUFFER, verticesData, gl.STATIC_DRAW);

		gl.bindBuffer(gl.ARRAY_BUFFER, null);

		// position attribute
		gl.vertexAttribPointer(0, 3, gl.FLOAT, false, 5 * Float32Array.BYTES_PER_ELEMENT, 0);
		gl.enableVertexAttribArray(0);

		initialized = true;
	}

	public override function update(deltaTime:Int):Void {
		this.deltaTime = deltaTime * 1.0 / 1000.0;
		if (Camera.moveLeft || Camera.moveRight || Camera.moveForward || Camera.moveBackward) {
			Camera.moveCamera(this.deltaTime);
		}
	}

	public override function onKeyDown(key:KeyCode, modifier:KeyModifier):Void {
		switch (key) {
			case LEFT:
				Camera.moveLeft = true;
			case RIGHT:
				Camera.moveRight = true;
			case UP:
				Camera.moveForward = true;
			case DOWN:
				Camera.moveBackward = true;
			default:
		}
	}

	public override function onKeyUp(key:KeyCode, modifier:KeyModifier):Void {
		switch (key) {
			case LEFT:
				Camera.moveLeft = false;
			case RIGHT:
				Camera.moveRight = false;
			case UP:
				Camera.moveForward = false;
			case DOWN:
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
				var gl:WebGL2RenderContext = context.webgl2;

				if (!initialized) {
					initialize(gl);
				}

				// clear the screen
				gl.clearColor(0.0, 0.2, 0, 1);
				gl.clear(gl.COLOR_BUFFER_BIT | gl.DEPTH_BUFFER_BIT);

				cube.use();

				model = new Matrix4();
				model.identity();
				model.appendTranslation(1.0, 1.0, 1.0);

				view = new Matrix4();
				view.identity();
				view = MatrixUtils.createLookAtMatrix(Camera.pos, Camera.pos.add(Camera.front), new Vector4(0.0, 1.0, 0.0));

				proj = new Matrix4();
				proj.identity();
				MatrixUtils.createPerspective(proj, Camera.fov * Math.PI / 180, Application.current.window.width / Application.current.window.height, 0.1,
					100.0);

				// the cube
				cube.render({
					vbo: vbo,
					modelMatrix: model,
					viewMatrix: view,
					projectionMatrix: proj,
					cameraPosition: Camera.pos,
					vertexBufferData: verticesData,
					objectColor: [1.0, 0.5, 0.31, 1.0],
					lightColor: [1.0, 1.0, 1.0, 1.0],
				});

				model = new Matrix4();
				model.identity();
				model.appendTranslation(1.2, 1.0, 2.0);
				model.appendScale(0.2, 0.2, 0.2);

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
