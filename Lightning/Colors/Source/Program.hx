import lime.math.Vector4;
import OpenGLUtils.glCreateProgram;
import lime.graphics.opengl.GLProgram;
import lime.graphics.WebGL2RenderContext;
import lime.math.Matrix4;
import lime.graphics.opengl.GLTexture;
import lime.utils.Int32Array;
import lime.utils.Float32Array;
import lime.graphics.opengl.GLBuffer;
import haxe.ValueException;

typedef ProgramParameters = {
	/**
	 * Vertex buffer object
	 */
	var vbo:GLBuffer;

	/**
	 * The vertex buffer data. The attributes present for each vertex will be determined by the
	 * specific program. This is bound to the VAO in the program.
	 */
	var vertexBufferData:Float32Array;

	/**
	 * Element buffer object
	 */
	@:optional var ebo:GLBuffer;

	/**
	 * Number of indexes in the ibo to render.
	 */
	@:optional var numIndexes:Int;

	/**
	 * The index buffer data. Whether indexed drawing is required or not will be determined by the
	 * specific program. This is bound to the EBO in the program.
	 */
	@:optional var indexBufferData:Int32Array;

	/**
	 * An array of textures.
	 * FIXME ultimately this should be an array of TextureInfo objects so that we can follow
	 * a convention as to what textures are diffuse or specular or otherwise.
	 */
	@:optional var textures:Array<GLTexture>;

	/**
		The object color.
	**/
	@:optional var objectColor:Array<Float>;

	/**
		The light color.
	**/
	@:optional var lightColor:Array<Float>;

	/**
	 * The model matrix to apply to the model to place it properly oriented and position in the world.
	 */
	var modelMatrix:Matrix4;

	/**
	 * The projection matrix to use.
	 */
	var projectionMatrix:Matrix4;

	/**
		The view matrix to use
	**/
	var viewMatrix:Matrix4;

	/**
	 * The camera position.
	 * FIXME This should be a camera object
	 */
	var cameraPosition:Vector4;
}

/**
 * Base GL program class.
 */
abstract class Program {
	// Graphics contexts
	var _gl:WebGL2RenderContext;

	// GL variables
	public var _glProgram:GLProgram;

	/**
	 * Constructor
	 * @param gl A WebGL render context
	 */
	public function new(gl:WebGL2RenderContext) {
		_gl = gl;
	}

	/**
	 * Make this program the current one in the GL context.
	 */
	public function use():Void {
		_gl.useProgram(_glProgram);
	}

	/**
	 * Create a GLSL program compiling the supplied shader source and linking the program.
	 * @param vertexSource vertex shader source
	 * @param fragmentSource fragment shader source
	 */
	function createGLSLProgram(vertexSource:String, fragmentSource:String):Void {
		_glProgram = glCreateProgram(_gl, vertexSource, fragmentSource);
		if (_glProgram == null) {
			throw new ValueException('compilation failed, check accompanying errors');
		}
	}

	/**
	 * Render the object specified by the parameters.
	 * The exact data provided in the params parameter
	 * provides all the information required by the
	 * Program to render an object. All fields are
	 * optional but the program subclass may and 
	 * probably should implement checks.
	 * @param params the program data.
	 */
	public abstract function render(params:ProgramParameters):Void;
}
