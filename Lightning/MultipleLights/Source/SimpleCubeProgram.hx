import Program.ProgramParameters;
import lime.graphics.WebGLRenderContext;
import lime.graphics.opengl.GLUniformLocation;
import lime.utils.Float32Array;

typedef Material = {
	var shininess:Float;
}

typedef Light = {
	var dirLight:DirLight;
	var pointLights:Array<PointLight>;
	var spotLight:SpotLight;
}

typedef DirLight = {
	var direction:Array<Float>;
	var ambient:Array<Float>;
	var diffuse:Array<Float>;
	var specular:Array<Float>;
}

typedef PointLight = {
	var ambient:Array<Float>;
	var diffuse:Array<Float>;
	var specular:Array<Float>;

	var constant:Float;
	var linear:Float;
	var quadratic:Float;
	var position:Array<Float>;
}

typedef SpotLight = {
	> DirLight,
	> PointLight,
	var cutOff:Float;
	var outerCutOff:Float;
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

	/* light */
	// dir light
	private var _programDirLightDirectionUniform:GLUniformLocation;
	private var _programDirLightAmbientUniform:GLUniformLocation;
	private var _programDirLightDiffuseUniform:GLUniformLocation;
	private var _programDirLightSpecularUniform:GLUniformLocation;

	// spotlight
	private var _programSpotLightPositionUniform:GLUniformLocation;
	private var _programSpotLightDirectionUniform:GLUniformLocation;
	private var _programSpotLightAmbientUniform:GLUniformLocation;
	private var _programSpotLightDiffuseUniform:GLUniformLocation;
	private var _programSpotLightSpecularUniform:GLUniformLocation;
	private var _programSpotLightConstantUniform:GLUniformLocation;
	private var _programSpotLightLinearUniform:GLUniformLocation;
	private var _programSpotLightQuadraticUniform:GLUniformLocation;
	private var _programSpotLightCutOffUniform:GLUniformLocation;
	private var _programSpotLightOuterCutOffUniform:GLUniformLocation;

	// vertex attributes
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

struct DirLight {
    vec3 direction;
	
    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
};

struct PointLight {
    vec3 position;
    
    float constant;
    float linear;
    float quadratic;
	
    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
};

struct SpotLight {
    vec3 position;
    vec3 direction;
    float cutOff;
    float outerCutOff;
  
    float constant;
    float linear;
    float quadratic;
  
    vec3 ambient;
    vec3 diffuse;
    vec3 specular;       
};

#define NR_POINT_LIGHTS 4

in vec3 FragPos;
in vec3 Normal;
in vec2 TexCoords;

uniform vec3 viewPos;
uniform DirLight dirLight;
uniform PointLight pointLights[NR_POINT_LIGHTS];
uniform SpotLight spotLight;
uniform Material material;

// function prototypes
vec3 CalcDirLight(DirLight light, vec3 normal, vec3 viewDir);
vec3 CalcPointLight(PointLight light, vec3 normal, vec3 fragPos, vec3 viewDir);
vec3 CalcSpotLight(SpotLight light, vec3 normal, vec3 fragPos, vec3 viewDir);

void main()
{    
    // properties
    vec3 norm = normalize(Normal);
    vec3 viewDir = normalize(viewPos - FragPos);
    
    // == =====================================================
    // Our lighting is set up in 3 phases: directional, point lights and an optional flashlight
    // For each phase, a calculate function is defined that calculates the corresponding color
    // per lamp. In the main() function we take all the calculated colors and sum them up for
    // this fragment's final color.
    // == =====================================================
    // phase 1: directional lighting
    vec3 result = CalcDirLight(dirLight, norm, viewDir);
    // phase 2: point lights
    for(int i = 0; i < NR_POINT_LIGHTS; i++)
        result += CalcPointLight(pointLights[i], norm, FragPos, viewDir);    
    // phase 3: spot light
    result += CalcSpotLight(spotLight, norm, FragPos, viewDir);    
    
    FragColor = vec4(result, 1.0);
}

// calculates the color when using a directional light.
vec3 CalcDirLight(DirLight light, vec3 normal, vec3 viewDir)
{
    vec3 lightDir = normalize(-light.direction);
    // diffuse shading
    float diff = max(dot(normal, lightDir), 0.0);
    // specular shading
    vec3 reflectDir = reflect(-lightDir, normal);
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), material.shininess);
    // combine results
    vec3 ambient = light.ambient * vec3(texture(material.diffuse, TexCoords));
    vec3 diffuse = light.diffuse * diff * vec3(texture(material.diffuse, TexCoords));
    vec3 specular = light.specular * spec * vec3(texture(material.specular, TexCoords));
    return (ambient + diffuse + specular);
}

// calculates the color when using a point light.
vec3 CalcPointLight(PointLight light, vec3 normal, vec3 fragPos, vec3 viewDir)
{
    vec3 lightDir = normalize(light.position - fragPos);
    // diffuse shading
    float diff = max(dot(normal, lightDir), 0.0);
    // specular shading
    vec3 reflectDir = reflect(-lightDir, normal);
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), material.shininess);
    // attenuation
    float distance = length(light.position - fragPos);
    float attenuation = 1.0 / (light.constant + light.linear * distance + light.quadratic * (distance * distance));    
    // combine results
    vec3 ambient = light.ambient * vec3(texture(material.diffuse, TexCoords));
    vec3 diffuse = light.diffuse * diff * vec3(texture(material.diffuse, TexCoords));
    vec3 specular = light.specular * spec * vec3(texture(material.specular, TexCoords));
    ambient *= attenuation;
    diffuse *= attenuation;
    specular *= attenuation;
    return (ambient + diffuse + specular);
}

// calculates the color when using a spot light.
vec3 CalcSpotLight(SpotLight light, vec3 normal, vec3 fragPos, vec3 viewDir)
{
    vec3 lightDir = normalize(light.position - fragPos);
    // diffuse shading
    float diff = max(dot(normal, lightDir), 0.0);
    // specular shading
    vec3 reflectDir = reflect(-lightDir, normal);
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), material.shininess);
    // attenuation
    float distance = length(light.position - fragPos);
    float attenuation = 1.0 / (light.constant + light.linear * distance + light.quadratic * (distance * distance));    
    // spotlight intensity
    float theta = dot(lightDir, normalize(-light.direction)); 
    float epsilon = light.cutOff - light.outerCutOff;
    float intensity = clamp((theta - light.outerCutOff) / epsilon, 0.0, 1.0);
    // combine results
    vec3 ambient = light.ambient * vec3(texture(material.diffuse, TexCoords));
    vec3 diffuse = light.diffuse * diff * vec3(texture(material.diffuse, TexCoords));
    vec3 specular = light.specular * spec * vec3(texture(material.specular, TexCoords));
    ambient *= attenuation * intensity;
    diffuse *= attenuation * intensity;
    specular *= attenuation * intensity;
    return (ambient + diffuse + specular);
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
		_programDirLightDirectionUniform = _gl.getUniformLocation(_glProgram, "dirLight.direction");
		_programDirLightAmbientUniform = _gl.getUniformLocation(_glProgram, "dirLight.ambient");
		_programDirLightDiffuseUniform = _gl.getUniformLocation(_glProgram, "dirLight.diffuse");
		_programDirLightSpecularUniform = _gl.getUniformLocation(_glProgram, "dirLight.direction");

		_programSpotLightPositionUniform = _gl.getUniformLocation(_glProgram, "spotLight.position");
		_programSpotLightDirectionUniform = _gl.getUniformLocation(_glProgram, "spotLight.direction");
		_programSpotLightAmbientUniform = _gl.getUniformLocation(_glProgram, "spotLight.ambient");
		_programSpotLightDiffuseUniform = _gl.getUniformLocation(_glProgram, "spotLight.diffuse");
		_programSpotLightSpecularUniform = _gl.getUniformLocation(_glProgram, "spotLight.specular");
		_programSpotLightConstantUniform = _gl.getUniformLocation(_glProgram, "spotLight.constant");
		_programSpotLightLinearUniform = _gl.getUniformLocation(_glProgram, "spotLight.linear");
		_programSpotLightQuadraticUniform = _gl.getUniformLocation(_glProgram, "spotLight.quadratic");
		_programSpotLightCutOffUniform = _gl.getUniformLocation(_glProgram, "spotLight.cutOff");
		_programSpotLightOuterCutOffUniform = _gl.getUniformLocation(_glProgram, "spotLight.outerCutOff");

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

		// material
		_gl.uniform1f(_programMaterialDiffuseUniform, 0);
		_gl.uniform1f(_programMaterialSpecularUniform, 1);

		_gl.uniform1f(_programMaterialShininessUniform, params.material.shininess);

		// directional light
		_gl.uniform3f(_programDirLightDirectionUniform, params.light.dirLight.direction[0], params.light.dirLight.direction[1],
			params.light.dirLight.direction[2]);
		_gl.uniform3f(_programDirLightAmbientUniform, params.light.dirLight.ambient[0], params.light.dirLight.ambient[1], params.light.dirLight.ambient[2]);
		_gl.uniform3f(_programDirLightDiffuseUniform, params.light.dirLight.diffuse[0], params.light.dirLight.diffuse[1], params.light.dirLight.diffuse[2]);
		_gl.uniform3f(_programDirLightSpecularUniform, params.light.dirLight.specular[0], params.light.dirLight.specular[1],
			params.light.dirLight.specular[2]);

		// point lights
		for (i in 0...4) {
			for (prop in ['ambient', 'position', 'specular', 'diffuse', 'constant', 'linear', 'quadratic']) {
				switch prop {
					case 'ambient':
						_gl.uniform3f(_gl.getUniformLocation(_glProgram, 'pointLights[$i].${prop}'), params.light.pointLights[i].ambient[0],
							params.light.pointLights[i].ambient[1], params.light.pointLights[i].ambient[2]);
					case 'position':
						_gl.uniform3f(_gl.getUniformLocation(_glProgram, 'pointLights[$i].${prop}'), params.light.pointLights[i].position[0],
							params.light.pointLights[i].position[1], params.light.pointLights[i].position[2]);
					case 'specular':
						_gl.uniform3f(_gl.getUniformLocation(_glProgram, 'pointLights[$i].${prop}'), params.light.pointLights[i].specular[0],
							params.light.pointLights[i].specular[1], params.light.pointLights[i].specular[2]);
					case 'diffuse':
						_gl.uniform3f(_gl.getUniformLocation(_glProgram, 'pointLights[$i].${prop}'), params.light.pointLights[i].diffuse[0],
							params.light.pointLights[i].diffuse[1], params.light.pointLights[i].diffuse[2]);
					case 'constant':
						_gl.uniform1f(_gl.getUniformLocation(_glProgram, 'pointLights[$i].${prop}'), params.light.pointLights[i].constant);
					case 'linear':
						_gl.uniform1f(_gl.getUniformLocation(_glProgram, 'pointLights[$i].${prop}'), params.light.pointLights[i].linear);
					case 'quadratic':
						_gl.uniform1f(_gl.getUniformLocation(_glProgram, 'pointLights[$i].${prop}'), params.light.pointLights[i].quadratic);
				}
			}
		}

		// spotlight
		_gl.uniform3f(_programSpotLightPositionUniform, params.light.spotLight.position[0], params.light.spotLight.position[1],
			params.light.spotLight.position[2]);

		_gl.uniform3f(_programSpotLightDirectionUniform, params.light.spotLight.direction[0], params.light.spotLight.direction[1],
			params.light.spotLight.direction[2]);
		_gl.uniform3f(_programSpotLightAmbientUniform, params.light.spotLight.ambient[0], params.light.spotLight.ambient[1],
			params.light.spotLight.ambient[2]);
		_gl.uniform3f(_programSpotLightDiffuseUniform, params.light.spotLight.diffuse[0], params.light.spotLight.diffuse[1],
			params.light.spotLight.diffuse[2]);
		_gl.uniform3f(_programSpotLightSpecularUniform, params.light.spotLight.specular[0], params.light.spotLight.specular[1],
			params.light.spotLight.specular[2]);

		_gl.uniform1f(_programSpotLightConstantUniform, params.light.spotLight.constant);
		_gl.uniform1f(_programSpotLightLinearUniform, params.light.spotLight.linear);
		_gl.uniform1f(_programSpotLightQuadraticUniform, params.light.spotLight.quadratic);

		_gl.uniform1f(_programSpotLightCutOffUniform, params.light.spotLight.cutOff);
		_gl.uniform1f(_programSpotLightOuterCutOffUniform, params.light.spotLight.outerCutOff);

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
