import lime.graphics.opengl.GLProgram;
import lime.graphics.WebGL2RenderContext;
import lime.math.Matrix4;

class Shader {
	static public function setInt(gl:WebGL2RenderContext, program:GLProgram, name:String, value:Int) {
		gl.uniform1i(gl.getUniformLocation(program, name), value);
	}

	static public function setFloat(gl:WebGL2RenderContext, program:GLProgram, name:String, value:Float) {
		gl.uniform1f(gl.getUniformLocation(program, name), value);
	}

	static public function setMat4(gl:WebGL2RenderContext, program:GLProgram, name:String, value:Matrix4) {
		gl.uniformMatrix4fv(gl.getUniformLocation(program, name), false, value);
	}
}
