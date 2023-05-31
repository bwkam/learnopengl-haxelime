package;

import lime.ui.Window;
import lime.app.Application;
import lime.graphics.RenderContext;
import lime.graphics.WebGL2RenderContext;
import lime.graphics.opengl.GLBuffer;
import lime.graphics.opengl.GLProgram;
import lime.graphics.opengl.GLShader;
import lime.utils.Float32Array;

// ---- PEOTE-VIEW and -UI ----
import peote.view.PeoteView;
import peote.view.Color;
import peote.ui.PeoteUIDisplay;
import peote.ui.interactive.UISlider;
import peote.ui.style.*;
import peote.ui.config.*;


/**
 * A simple triangle demo after Learn OpenGL (ch 5) by Joey DeVries
 * ( + slider by peote-ui: https://github.com/maitag/peote-ui )
 */
class Main extends Application {

	
	// --------------------------------------------------- 
	// ----------- PEOTE-VIEW and -UI -------------------- 
	// --------------------------------------------------- 
	
	var peoteView:PeoteView;
	var uiDisplay:PeoteUIDisplay;
	
	var sliderValue:Float = 1.0;
	
	override function onWindowCreate():Void
	{
		switch (window.context.type)
		{
			case WEBGL, OPENGL, OPENGLES:
				try initUI(window)
				catch (_) trace(haxe.CallStack.toString(haxe.CallStack.exceptionStack()), _);
			default: throw("Sorry, only works with OpenGL.");
		}
	}

	public function initUI(window:Window)
	{
		peoteView = new PeoteView(window, false);
		
		uiDisplay = new PeoteUIDisplay(0, 0, window.width, window.height);
		peoteView.addDisplay(uiDisplay);
		
		var roundBorderStyle:RoundBorderStyle = {
			color: Color.GREY2,
			borderColor: Color.GREY4,
			borderSize: 3.0,
			borderRadius: 20.0
		}
		
		var sliderConfig:SliderConfig = {
			backgroundStyle: roundBorderStyle,
			draggerStyle: roundBorderStyle.copy(Color.YELLOW),
			
			//vertical:true,
			//reverse:true,
			
			//draggerSpace:{left:15, right:15},
			//backgroundSpace:{left:50},

			//backgroundLengthPercent:0.9,
			backgroundSizePercent:0.3,
			
			draggerLength:50,
			draggerLengthPercent:0.1,
			
			draggerSize:20,
			draggerSizePercent:0.75,
			
			//draggerOffset:0,
			draggerOffsetPercent:0.5,
			
			draggSpaceStart:40,
			draggSpaceEnd:20,
		};
		
		var vSlider = new UISlider(10, 10, 60, 500, sliderConfig);
		vSlider.value = sliderValue;
		uiDisplay.add(vSlider);
		
		vSlider.onChange = function(uiSlider:UISlider, value:Float, percent:Float) {
			//trace( 'vSlider value:$value, percent:$percent' );
			sliderValue = value;
		}
				
		PeoteUIDisplay.registerEvents(window);			
	}	
	
	
	
	// --------------------------------------------------- 
	// --------------------------------------------------- 
	// --------------------------------------------------- 
	
	
	
	// Model data
	var vbo:GLBuffer;
	var program:GLProgram;

	// Make sure you only do initialization once
	var initialized:Bool;

	public function new () {
		
		super ();
		
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
	function glCreateShader(gl:WebGL2RenderContext, source:String, type:Int):GLShader
	{
		var shader = gl.createShader(type);
		gl.shaderSource(shader, source);
		gl.compileShader(shader);
	
		if (gl.getShaderParameter(shader, gl.COMPILE_STATUS) == 0)
		{
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
	function glCreateProgram(gl:WebGL2RenderContext, vertexSource:String, fragmentSource:String):Null<GLProgram>
	{
		var vs = glCreateShader(gl, vertexSource, gl.VERTEX_SHADER);
		var fs = glCreateShader(gl, fragmentSource, gl.FRAGMENT_SHADER);
	
		if (vs == null || fs == null)
		{
			return null;
		}
	
		var program = gl.createProgram();
		gl.attachShader(program, vs);
		gl.attachShader(program, fs);
	
		gl.deleteShader(vs);
		gl.deleteShader(fs);
	
		gl.linkProgram(program);
	
		if (gl.getProgramParameter(program, gl.LINK_STATUS) == 0)
		{
			trace(gl.getProgramInfoLog(program));
			trace("VALIDATE_STATUS: " + gl.getProgramParameter(program, gl.VALIDATE_STATUS));
			trace("ERROR: " + gl.getError());
			return null;
		}
	
		return program;
	}
	
	function initialize(gl:WebGL2RenderContext): Void {
		// Vertex Shader
		var vs = "#version 300 es
layout (location = 0) in vec3 aPos;

void main()
{
	gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);
}
";

	// Fragment Shader
	var fs = "#version 300 es
precision mediump float;

out vec4 FragColor;

void main() 
{
    FragColor = vec4(1.0, 0.5, 0.2, 1.0);
}
";

		program = glCreateProgram(gl, vs, fs);
		
		// Vertices
		var vertices = [-0.5, -0.5, 0.0,
		                 0.5, -0.5, 0.0,
						 0.0, 0.5, 0.0];
		var vertexData = new Float32Array(vertices);
		vbo = gl.createBuffer();
		gl.bindBuffer(gl.ARRAY_BUFFER, vbo);
		gl.bufferData(gl.ARRAY_BUFFER, vertexData, gl.STATIC_DRAW);
		gl.bindBuffer(gl.ARRAY_BUFFER, null);

		initialized = true;
	}

	public override function render (context:RenderContext):Void {
		
		switch (context.type) {
			
			case OPENGL, OPENGLES, WEBGL:
				
				var gl:WebGL2RenderContext = context.webgl2;

				
				if (!initialized) {
					initialize(gl);
				}
				
				// ---- PEOTE-VIEW and -UI ----
				gl.viewport(0, 0, window.width, window.height);
				gl.scissor(0, 0, window.width, window.height);
				gl.enable(gl.SCISSOR_TEST);	
				// ----------------------------
				
				gl.clearColor (0.75 * sliderValue, 1, 0, 1);
				gl.clear (gl.COLOR_BUFFER_BIT | gl.DEPTH_BUFFER_BIT | gl.STENCIL_BUFFER_BIT);

				gl.useProgram(program);

				// Bind vertex buffer
				gl.bindBuffer(gl.ARRAY_BUFFER, vbo);
				gl.vertexAttribPointer(0, 3, gl.FLOAT, false, 3 * Float32Array.BYTES_PER_ELEMENT, 0);
				gl.enableVertexAttribArray(0);

				gl.drawArrays(gl.TRIANGLES, 0, 3);				
				
				// better also cleaning up after the triangle:
				gl.bindBuffer(gl.ARRAY_BUFFER, null);
				gl.useProgram (null);
				
				
				// ---- PEOTE-VIEW and -UI ----
				if (peoteView != null) peoteView.renderPart();
				
			default:
		}
	}
	
	// ---- PEOTE-VIEW and -UI ----
	public override function onWindowResize(w:Int, h:Int) {
		peoteView.resize(w, h);		
	}
}
