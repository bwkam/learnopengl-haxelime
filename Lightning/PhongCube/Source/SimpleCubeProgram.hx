import Program.ProgramParameters;
import lime.graphics.WebGLRenderContext;
import lime.graphics.opengl.GLUniformLocation;
import lime.utils.Float32Array;

class SimpleCubeProgram extends Program {
	// Shader source
	var _vertexSource:String;
	var _fragmentSource:String;

	// GL variables
	private var _programViewUniform:GLUniformLocation;
	private var _programProjectionUniform:GLUniformLocation;
	private var _programModelUniform:GLUniformLocation;
	private var _programObjectColorUniform:GLUniformLocation;
	private var _programLightColorUniform:GLUniformLocation;
	private var _programLightPosUniform:GLUniformLocation;
	private var _programViewPosUniform:GLUniformLocation;

	private var _programTextureAttribute:Int;
	private var _programVertexAttribute:Int;
	private var _programNormalVecAttribute:Int;

	/**
	 * Constructor
	 * @param gl An WebGL render context
	 */
	public function new(gl:WebGLRenderContext):Void {
		var vertexSource = "#version 300 es
				layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aNormal;

out vec3 FragPos;
out vec3 Normal;

uniform mat4 model;
uniform mat4 view;
uniform mat4 proj;

void main()
{
    FragPos = vec3(model * vec4(aPos, 1.0));
    Normal = mat3(transpose(inverse(model))) * aNormal;  
    
    gl_Position = proj * view * vec4(FragPos, 1.0);
}
";

		var fragmentSource = "#version 300 es
				precision mediump float;

				out vec4 FragColor;

in vec3 Normal;  
in vec3 FragPos;  
  
uniform vec3 lightPos; 
uniform vec3 viewPos; 
uniform vec3 lightColor;
uniform vec3 objectColor;

void main()
{
    // ambient
    float ambientStrength = 0.01;
    vec3 ambient = ambientStrength * lightColor;
  	
    // diffuse 
    vec3 norm = normalize(Normal);
    vec3 lightDir = normalize(lightPos - FragPos);
    float diff = max(dot(norm, lightDir), 0.0);
    vec3 diffuse = diff * lightColor;
    
    // specular
    float specularStrength = 0.5;
    vec3 viewDir = normalize(viewPos - FragPos);
    vec3 reflectDir = reflect(-lightDir, norm);  
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), 32.0);
    vec3 specular = specularStrength * spec * lightColor;  
        
    vec3 result = (ambient + diffuse + specular) * objectColor;
    FragColor = vec4(result, 1.0);
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

		_programNormalVecAttribute = _gl.getAttribLocation(_glProgram, "aNormal");
		_gl.enableVertexAttribArray(_programNormalVecAttribute);

		// Transformation matrices
		_programModelUniform = _gl.getUniformLocation(_glProgram, "model");
		_programViewUniform = _gl.getUniformLocation(_glProgram, "view");
		_programProjectionUniform = _gl.getUniformLocation(_glProgram, "proj");

		// colors
		_programObjectColorUniform = _gl.getUniformLocation(_glProgram, "objectColor");
		_programLightColorUniform = _gl.getUniformLocation(_glProgram, "lightColor");

		// lightning
		_programLightPosUniform = _gl.getUniformLocation(_glProgram, "lightPos");

		// camera pos
		_programViewPosUniform = _gl.getUniformLocation(_glProgram, "viewPos");
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

		// Add color vecs and pass in to shader
		_gl.uniform3f(_programObjectColorUniform, params.objectColor[0], params.objectColor[1], params.objectColor[2]);
		_gl.uniform3f(_programLightColorUniform, params.lightColor[0], params.lightColor[1], params.lightColor[2]);

		// lightning
		_gl.uniform3f(_programLightPosUniform, params.lightPos[0], params.lightPos[1], params.lightPos[2]);

		// camera
		_gl.uniform3f(_programViewPosUniform, params.viewPos[0], params.viewPos[1], params.viewPos[2]);

		// Bind vertex buffer
		_gl.bindBuffer(_gl.ARRAY_BUFFER, params.vbo);

		// Set up attribute pointers
		var stride = 6 * Float32Array.BYTES_PER_ELEMENT;

		// vertices attrib pointer
		_gl.vertexAttribPointer(_programVertexAttribute, 3, _gl.FLOAT, false, stride, 0);
		_gl.enableVertexAttribArray(0);

		// normal vectors
		_gl.vertexAttribPointer(_programNormalVecAttribute, 3, _gl.FLOAT, false, stride, 3 * Float32Array.BYTES_PER_ELEMENT);
		_gl.enableVertexAttribArray(1);

		// draw the fucking cube
		_gl.drawArrays(_gl.TRIANGLES, 0, 36);
	}
}
