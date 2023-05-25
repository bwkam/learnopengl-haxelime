import lime.graphics.opengl.GLProgram;
import lime.graphics.WebGLRenderContext;
import lime.math.Matrix4;

class Shader {
	static public function setInt(gl:WebGLRenderContext, program:GLProgram, name:String, value:Int) {
		gl.uniform1i(gl.getUniformLocation(program, name), value);
	}

	static public function setFloat(gl:WebGLRenderContext, program:GLProgram, name:String, value:Float) {
		gl.uniform1f(gl.getUniformLocation(program, name), value);
	}

	static public function setMat4(gl:WebGLRenderContext, program:GLProgram, name:String, value:Matrix4) {
		gl.uniformMatrix4fv(gl.getUniformLocation(program, name), false, value);
	}
}
