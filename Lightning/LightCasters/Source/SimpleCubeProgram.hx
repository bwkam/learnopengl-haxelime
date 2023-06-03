import Program.ProgramParameters;
import lime.graphics.WebGLRenderContext;
import lime.graphics.opengl.GLUniformLocation;
import lime.utils.Float32Array;

typedef Material = {
	var shininess:Float;
}

typedef Light = {
	var direction:Array<Float>;
	var position:Array<Float>;

	var ambient:Array<Float>;
	var diffuse:Array<Float>;
	var specular:Array<Float>;
	var constant:Float;
	var linear:Float;
	var quadratic:Float;
	var cutOff:Float;
}

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
	private var _programViewPosUniform:GLUniformLocation;

	// material
	private var _programMaterialDiffuseUniform:GLUniformLocation;
	private var _programMaterialSpecularUniform:GLUniformLocation;
	private var _programMaterialShininessUniform:GLUniformLocation;

	// light
	private var _programLightAmbientUniform:GLUniformLocation;
	private var _programLightDiffuseUniform:GLUniformLocation;
	private var _programLightSpecularUniform:GLUniformLocation;

	private var _programLightDirectionUniform:GLUniformLocation;
	private var _programLightPositionUniform:GLUniformLocation;
	private var _programLightCutOffUniform:GLUniformLocation;

	private var _programLightConstantUniform:GLUniformLocation;
	private var _programLightLinearUniform:GLUniformLocation;
	private var _programLightQuadraticUniform:GLUniformLocation;

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
				layout (location = 2) in vec2 aTexCoords;	

out vec3 FragPos;
out vec3 Normal;
out vec2 TexCoords;

uniform mat4 model;
uniform mat4 view;
uniform mat4 proj;

void main()
{
    FragPos = vec3(model * vec4(aPos, 1.0));
    Normal = mat3(transpose(inverse(model))) * aNormal;  
    
    gl_Position = proj * view * vec4(FragPos, 1.0);
	TexCoords = aTexCoords;
}
";

		var fragmentSource = "#version 300 es
				precision mediump float;
out vec4 FragColor;

struct Material {
    sampler2D diffuse;
    sampler2D specular;    
    float shininess;
}; 

struct Light {
    vec3 position;  
    vec3 direction;
    float cutOff;
    float outerCutOff;
  
    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
	
    float constant;
    float linear;
    float quadratic;
};

in vec3 FragPos;  
in vec3 Normal;  
in vec2 TexCoords;
  
uniform vec3 viewPos;
uniform Material material;
uniform Light light;

void main()
{
    vec3 lightDir = normalize(light.position - FragPos);
    
    // check if lighting is inside the spotlight cone
    float theta = dot(lightDir, normalize(-light.direction)); 
    
    if(theta > light.cutOff) // remember that we're working with angles as cosines instead of degrees so a '>' is used.
    {    
        // ambient
        vec3 ambient = light.ambient * texture(material.diffuse, TexCoords).rgb;
        
        // diffuse 
        vec3 norm = normalize(Normal);
        float diff = max(dot(norm, lightDir), 0.0);
        vec3 diffuse = light.diffuse * diff * texture(material.diffuse, TexCoords).rgb;  
        
        // specular
        vec3 viewDir = normalize(viewPos - FragPos);
        vec3 reflectDir = reflect(-lightDir, norm);  
        float spec = pow(max(dot(viewDir, reflectDir), 0.0), material.shininess);
        vec3 specular = light.specular * spec * texture(material.specular, TexCoords).rgb;  
        
        // attenuation
        float distance    = length(light.position - FragPos);
        float attenuation = 1.0 / (light.constant + light.linear * distance + light.quadratic * (distance * distance));    

        // ambient  *= attenuation; // remove attenuation from ambient, as otherwise at large distances the light would be darker inside than outside the spotlight due the ambient term in the else branch
        diffuse   *= attenuation;
        specular *= attenuation;   
            
        vec3 result = ambient + diffuse + specular;
        FragColor = vec4(result, 1.0);
    }
    else 
    {
        // else, use ambient light so scene isn't completely dark outside the spotlight.
        FragColor = vec4(light.ambient * texture(material.diffuse, TexCoords).rgb, 1.0);
    }
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

		_programTextureAttribute = _gl.getAttribLocation(_glProgram, "aTexCoords");
		_gl.enableVertexAttribArray(_programTextureAttribute);

		// Transformation matrices
		_programModelUniform = _gl.getUniformLocation(_glProgram, "model");
		_programViewUniform = _gl.getUniformLocation(_glProgram, "view");
		_programProjectionUniform = _gl.getUniformLocation(_glProgram, "proj");

		// colors
		_programObjectColorUniform = _gl.getUniformLocation(_glProgram, "objectColor");
		_programLightColorUniform = _gl.getUniformLocation(_glProgram, "lightColor");

		// material
		_programMaterialDiffuseUniform = _gl.getUniformLocation(_glProgram, "material.diffuse");
		_programMaterialSpecularUniform = _gl.getUniformLocation(_glProgram, "material.specular");
		_programMaterialShininessUniform = _gl.getUniformLocation(_glProgram, "material.shininess");

		// light
		_programLightAmbientUniform = _gl.getUniformLocation(_glProgram, "light.ambient");
		_programLightDiffuseUniform = _gl.getUniformLocation(_glProgram, "light.diffuse");
		_programLightSpecularUniform = _gl.getUniformLocation(_glProgram, "light.specular");

		_programLightDirectionUniform = _gl.getUniformLocation(_glProgram, "light.direction");
		_programLightCutOffUniform = _gl.getUniformLocation(_glProgram, "light.cutoff");
		_programLightPositionUniform = _gl.getUniformLocation(_glProgram, "light.position");

		_programLightConstantUniform = _gl.getUniformLocation(_glProgram, "light.constant");
		_programLightLinearUniform = _gl.getUniformLocation(_glProgram, "light.linear");
		_programLightQuadraticUniform = _gl.getUniformLocation(_glProgram, "light.quadratic");

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
		// _gl.uniform3f(_programLightPosUniform, params.lightPos[0], params.lightPos[1], params.lightPos[2]);

		// material
		_gl.uniform1f(_programMaterialDiffuseUniform, 0);
		_gl.uniform1f(_programMaterialSpecularUniform, 1);

		_gl.uniform1f(_programMaterialShininessUniform, params.material.shininess);

		// light
		_gl.uniform3f(_programLightAmbientUniform, params.light.ambient[0], params.light.ambient[1], params.light.ambient[2]);
		_gl.uniform3f(_programLightDiffuseUniform, params.light.diffuse[0], params.light.diffuse[1], params.light.diffuse[2]);
		_gl.uniform3f(_programLightSpecularUniform, params.light.specular[0], params.light.specular[1], params.light.specular[2]);

		_gl.uniform1f(_programLightConstantUniform, params.light.constant);
		_gl.uniform1f(_programLightLinearUniform, params.light.linear);
		_gl.uniform1f(_programLightQuadraticUniform, params.light.quadratic);

		_gl.uniform3f(_programLightDirectionUniform, params.light.direction[0], params.light.direction[1], params.light.direction[2]);
		_gl.uniform3f(_programLightPositionUniform, params.light.position[0], params.light.position[1], params.light.position[2]);
		_gl.uniform1f(_programLightCutOffUniform, params.light.cutOff);

		// camera
		_gl.uniform3f(_programViewPosUniform, params.viewPos[0], params.viewPos[1], params.viewPos[2]);

		// Bind vertex buffer
		_gl.bindBuffer(_gl.ARRAY_BUFFER, params.vbo);

		// bind tex
		_gl.activeTexture(_gl.TEXTURE0);
		_gl.bindTexture(_gl.TEXTURE_2D, params.diffuseMap);

		// bind tex
		_gl.activeTexture(_gl.TEXTURE1);
		_gl.bindTexture(_gl.TEXTURE_2D, params.specularMap);

		// Set up attribute pointers
		var stride = 8 * Float32Array.BYTES_PER_ELEMENT;

		// vertices attrib pointer
		_gl.vertexAttribPointer(_programVertexAttribute, 3, _gl.FLOAT, false, stride, 0);
		_gl.enableVertexAttribArray(0);

		// normal vectors
		_gl.vertexAttribPointer(_programNormalVecAttribute, 3, _gl.FLOAT, false, stride, 3 * Float32Array.BYTES_PER_ELEMENT);
		_gl.enableVertexAttribArray(1);

		// tex coords
		_gl.vertexAttribPointer(_programTextureAttribute, 2, _gl.FLOAT, false, stride, 6 * Float32Array.BYTES_PER_ELEMENT);
		_gl.enableVertexAttribArray(2);

		// draw the fucking cube
		_gl.drawArrays(_gl.TRIANGLES, 0, 36);
	}
}
