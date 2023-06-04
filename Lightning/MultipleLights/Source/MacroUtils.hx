import haxe.macro.Context;
import haxe.macro.Expr;
import lime.graphics.opengl.GLUniformLocation;

class MacroUtils {
	macro public function buildShader():Array<Field> {
		var fields = Context.getBuildFields();
		final n_spotLights = 4;

		// PHASE 1

		// so here's what we want to do
		// first, we run through the shader code
		// if we find a struct, we simply parse it build a haxe typedef out of it

		// PHASE 2

		// run through the shader, if we find a uniform
		// call the appropriate gl.uniform* call depending on the type
		// if we find a vec* uniform,
		// call `uniform**(getLoc(program, vec_name), params.$vec_name)`
		// else if we find a struct uniform
		// for (field in struct.fields) {
		// call `uniform**(getLoc(program, $struct_name.$field_name), params.$struct_name.$field_name)`
		// }
		// else if we find an array of structs
		// for (struct_index in struct.members) {
		// for (field in struct.fields) {
		// call `uniform**(getLoc(program, $struct_name[$struct_index].$field_name), params.$struct_name[$struct_index].$field_name)`
		// }
		// }

		return fields;
	}
}

enum ESpotLightField {
	Position;
	Ambient;
	Diffuse;
	Specular;
	Constant;
	Linear;
	Quadratic;
}
