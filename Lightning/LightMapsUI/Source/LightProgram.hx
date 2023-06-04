import Program.ProgramParameters;
import lime.graphics.WebGLRenderContext;
import lime.graphics.opengl.GLUniformLocation;
import lime.utils.Float32Array;

class LightProgram extends Program {
	// Shader source
	var _vertexSource:String;
	var _fragmentSource:String;

	// GL variables
	private var _programViewUniform:GLUniformLocation;
	private var _programProjectionUniform:GLUniformLocation;
	private var _programModelUniform:GLUniformLocation;

	private var _programTextureAttribute:Int;
	private var _programVertexAttribute:Int;

	/**
	 * Constructor
	 * @param gl An WebGL render context
	 */
	public function new(gl:WebGLRenderContext):Void {
		var vertexSource = "#version 300 es

				layout (location = 0) in vec3 aPos;
                 
				uniform mat4 model;
				uniform mat4 view;
				uniform mat4 proj;

                void main()
				{
					gl_Position =  proj * view * model * vec4(aPos, 1.0);
                   
				}
";

		var fragmentSource = "#version 300 es
				precision mediump float;

                out vec4 FragColor;

				void main() 
				{
					FragColor = vec4(1.0);
				}
";

		super(gl);
		createGLSLProgram(vertexSource, fragmentSource);
		getShaderVarLocations();
	}

	/**
	 * Get all the GLSL variables locations and store
	 * them in member variables, so they can be bound to
	 * values during render().
	 */
	public function getShaderVarLocations():Void {
		// Get references to GLSL attributes
		_programVertexAttribute = _gl.getAttribLocation(_glProgram, "aPos");
		_gl.enableVertexAttribArray(_programVertexAttribute);

		// Transformation matrices
		_programModelUniform = _gl.getUniformLocation(_glProgram, "model");
		_programViewUniform = _gl.getUniformLocation(_glProgram, "view");
		_programProjectionUniform = _gl.getUniformLocation(_glProgram, "proj");
	}

	/**
	 * Draw with the specified parameters.
	 * @param params the program parameters
	 * 	the following ProgramParameters fields are required
	 * 		- vbo
	 * 		- ibo
	 * 		- textures
	 * 			- 0 the model texture
	 * 		- modelMatrix
	 * 		- projectionMatrix
	 *		- cameraPosition
	 * 		- ui
	 */
	public function render(params:ProgramParameters):Void {
		// Add view and pass in to shader
		_gl.uniformMatrix4fv(_programViewUniform, false, params.viewMatrix);
		// Add projection and pass in to shader
		_gl.uniformMatrix4fv(_programProjectionUniform, false, params.projectionMatrix);
		// Add model matrix and pass in to shader
		_gl.uniformMatrix4fv(_programModelUniform, false, params.modelMatrix);

		// Bind vertex buffer
		_gl.bindBuffer(_gl.ARRAY_BUFFER, params.vbo);

		// Set up attribute pointers
		var stride = 8 * Float32Array.BYTES_PER_ELEMENT;

		// vertices attrib pointer
		_gl.vertexAttribPointer(_programVertexAttribute, 3, _gl.FLOAT, false, stride, 0);
		_gl.enableVertexAttribArray(0);

		// draw the fucking cube
		_gl.drawArrays(_gl.TRIANGLES, 0, 36);
		_gl.bindBuffer(_gl.ARRAY_BUFFER, null);
	}
}
