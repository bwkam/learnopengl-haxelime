package;

import peote.ui.interactive.UIArea;
import peote.text.Font;
import peote.ui.interactive.UITextLine;
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
import peote.ui.PeoteUIDisplay;
import peote.view.PeoteView;
import peote.view.Color;
import peote.ui.interactive.UISlider;
import peote.ui.style.*;
import peote.ui.config.*;
import peote.ui.event.*;
import lime.ui.Window;

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
	var cubePositions:Array<Array<Float>>;
	var gl:WebGLRenderContext;
	var initialized:Bool = false;

	public static var peoteView:PeoteView;
	private static var uiDisplay:PeoteUIDisplay;
	private static var someWindow:Window;
	private static var lightAmbient:Float;
	private static var lightDiffuse:Float;
	private static var lightSpecular:Float;
	private static var materialAmbient:Float;
	private static var materialSpecular:Float;

	// just for neovim
	static function main() {}

	override function onPreloadComplete() {
		// if we call init from here then all assets are loaded
		// so you you don't need to check for preloader.complete etc
		switch (window.context.type) {
			case OPENGL, OPENGLES, WEBGL:
				gl = window.context.webgl;
				initialize(gl);
			default:
				trace('needs gl');
		}
	}

	function initialize(gl:WebGLRenderContext):Void {
		deltaTime = 0.0;
		lastFrame = 0.0;
		Camera.init();
		// todo - add this back
		// Application.current.window.mouseLock = true;
		cube = new SimpleCubeProgram(gl);
		lightCube = new LightProgram(gl);

		cubePositions = [
			[0.0, 0.0, 0.0], [2.0, 5.0, -15.0], [-1.5, -2.2, -2.5], [-3.8, -2.0, -12.3], [2.4, -0.4, -3.5], [-1.7, 3.0, -7.5], [1.3, -2.0, -2.5],
			[1.5, 2.0, -2.5], [1.5, 0.2, -1.5], [-1.3, 1.0, -1.5]];

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

		image2 = Assets.getImage("assets/specular.png");
		// create the texture
		texture2 = gl.createTexture();
		gl.bindTexture(gl.TEXTURE_2D, texture2);
		// config mimap and other options
		gl.texParameteri(gl.TEXTURE_2D, gl.TEXTURE_WRAP_S, gl.REPEAT);
		gl.texParameteri(gl.TEXTURE_2D, gl.TEXTURE_WRAP_T, gl.REPEAT);
		gl.texParameteri(gl.TEXTURE_2D, gl.TEXTURE_MIN_FILTER, gl.LINEAR_MIPMAP_LINEAR);
		gl.texParameteri(gl.TEXTURE_2D, gl.TEXTURE_MAG_FILTER, gl.LINEAR);
		gl.texImage2D(gl.TEXTURE_2D, 0, gl.RGB, image2.width, image2.height, 0, gl.RGB, gl.UNSIGNED_BYTE, image2.src);
		gl.generateMipmap(gl.TEXTURE_2D);

		initUI();
		initialized = true;
	}

	public function initUI() {
		var sliderHeight = 20;
		var leftGap = 10;
		var rightGap = 10;
		var size = 200 - leftGap - rightGap;
		var gapText = 40;
		var mGapText = 60;
		var gap = 32;
		var yPos = 0;
		peoteView = new PeoteView(window, false);
		uiDisplay = new PeoteUIDisplay(0, 0, window.width, window.height);
		peoteView.addDisplay(uiDisplay);
		var boxStyle = new BoxStyle(0x041144ff);
		var roundBorderStyle = new RoundBorderStyle(Color.GREY2);
		var fontStyle = new FontStyleTiled();
		fontStyle.color = Color.GREY6;
		var sliderConfig:SliderConfig = {
			backgroundStyle: roundBorderStyle.copy(Color.GREY2),
			draggerStyle: roundBorderStyle.copy(Color.GREY3, Color.GREY2, 0.5),
			draggerSize: 16,
			draggSpace: 1,
		};
		var area = new UIArea(window.width - 200, 0, 200, window.height, roundBorderStyle);
		uiDisplay.add(area);
		// this looks complicate but need if you zoom the peoteView or UIDisplay
		area.setDragArea(Std.int(-uiDisplay.xOffset / uiDisplay.xz), Std.int(-uiDisplay.yOffset / uiDisplay.yz), Std.int(uiDisplay.width / uiDisplay.xz),
			Std.int(uiDisplay.height / uiDisplay.yz));
		var lightAmbientSlider = new UISlider(leftGap, yPos += gapText, size, sliderHeight, sliderConfig);
		lightAmbientSlider.onMouseWheel = (s:UISlider, e:WheelEvent) -> s.setWheelDelta(e.deltaY);
		lightAmbientSlider.onChange = (s:UISlider, value:Float, percent:Float) -> lightAmbient = value;
		area.add(lightAmbientSlider);

		var lightDiffuseSlider = new UISlider(leftGap, yPos += gapText, size, sliderHeight, sliderConfig);
		lightDiffuseSlider.onMouseWheel = (s:UISlider, e:WheelEvent) -> s.setWheelDelta(e.deltaY);
		lightDiffuseSlider.onChange = (s:UISlider, value:Float, percent:Float) -> lightDiffuse = value;
		area.add(lightDiffuseSlider);

		var lightSpecularSlider = new UISlider(leftGap, yPos += gapText, size, sliderHeight, sliderConfig);
		lightSpecularSlider.onMouseWheel = (s:UISlider, e:WheelEvent) -> s.setWheelDelta(e.deltaY);
		lightSpecularSlider.onChange = (s:UISlider, value:Float, percent:Float) -> lightSpecular = value;
		area.add(lightSpecularSlider);

		PeoteUIDisplay.registerEvents(window);
	}

	public override function update(deltaTime:Int):Void {
		// don't call update unless ready
		if (!initialized) {
			return;
		}
		this.deltaTime = deltaTime * 1.0 / 1000.0;
		if (Camera.moveLeft || Camera.moveRight || Camera.moveForward || Camera.moveBackward) {
			Camera.moveCamera(this.deltaTime);
		}
	}

	public override function onKeyDown(key:KeyCode, modifier:KeyModifier):Void {
		switch (key) {
			case ESCAPE:
				window.close();
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

	@:access(peote.view.PeoteView)
	public override function render(context:RenderContext):Void {
		// don't do render unless ready
		if (!initialized) {
			return;
		}

		// ---- PEOTE-VIEW and -UI ----
		gl.viewport(0, 0, window.width, window.height);
		gl.scissor(0, 0, window.width, window.height);
		gl.enable(gl.SCISSOR_TEST);
		// ----------------------------

		// clear the screen
		gl.clearColor(0.0, 0.0, 0.0, 0.0);
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
		MatrixUtils.createPerspective(proj, Camera.fov * Math.PI / 180, Application.current.window.width / Application.current.window.height, 0.1, 100.0);

		var lightPos = [1.0, 1.0, 1.0];

		for (i in 0...10) {
			var angle = 20.0 * i;
			var model = new Matrix4();
			model.identity();
			model.appendTranslation(cubePositions[i][0], cubePositions[i][1], cubePositions[i][2]);
			model.appendRotation(angle, new Vector4(1.0, 0.3, 0.5, 1.0));
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
				viewPos: MatrixUtils.vecToArray(Camera.pos),
				material: {
					shininess: 64.0
				},
				light: {
					direction: MatrixUtils.vecToArray(Camera.pos),
					position: MatrixUtils.vecToArray(Camera.front),
					cutOff: Math.cos(12.5 * Math.PI / 180),
					ambient: [lightAmbient, lightAmbient, lightAmbient],
					diffuse: [lightDiffuse, lightDiffuse, lightDiffuse],
					specular: [lightSpecular, lightSpecular, lightSpecular],
					constant: 1.0,
					linear: 0.09,
					quadratic: 0.032,
				},
				diffuseMap: texture,
				specularMap: texture2,
			});
		}

		// model = new Matrix4();
		// model.identity();
		// model.appendTranslation(lightPos[0], lightPos[1], lightPos[2]);
		// model.appendScale(0.6, 0.6, 0.6);

		// lightCube.use();

		// // light cube
		// lightCube.render({
		// 	vbo: vbo,
		// 	modelMatrix: model,
		// 	viewMatrix: view,
		// 	projectionMatrix: proj,
		// 	cameraPosition: Camera.pos,
		// 	vertexBufferData: verticesData,
		// });

		// render ui
		peoteView.renderPart();
	}
}
