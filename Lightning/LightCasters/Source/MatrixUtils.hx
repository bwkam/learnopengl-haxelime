import lime.math.Matrix4;
import lime.math.Vector4;

class MatrixUtils {
	public static function createLookAtMatrix(cameraPos:Vector4, target:Vector4, up:Vector4):Matrix4 {
		var cameraDir = cameraPos.subtract(target);
		cameraDir.normalize();
		var cameraRight = up.crossProduct(cameraDir);
		cameraRight.normalize();
		var cameraUp = cameraDir.crossProduct(cameraRight);
		cameraUp.normalize();
		var cameraMat = new Matrix4();

		cameraMat[0] = cameraRight.x;
		cameraMat[1] = cameraUp.x;
		cameraMat[2] = cameraDir.x;
		cameraMat[3] = 0.0;
		cameraMat[4] = cameraRight.y;
		cameraMat[5] = cameraUp.y;
		cameraMat[6] = cameraDir.y;
		cameraMat[7] = 0.0;
		cameraMat[8] = cameraRight.z;
		cameraMat[9] = cameraUp.z;
		cameraMat[10] = cameraDir.z;
		cameraMat[11] = 0.0;
		cameraMat[12] = -cameraPos.x;
		cameraMat[13] = -cameraPos.y;
		cameraMat[14] = -cameraPos.z;
		cameraMat[15] = 1.0;

		return cameraMat;
	}

	public static function createPerspective(mat:Matrix4, fovy:Float, aspect:Float, zNear:Float, zFar:Float):Void {
		if (Math.abs(aspect - (Math.pow(2, -23))) > 0.0) {
			var top = Math.tan(fovy) * zNear;
			var bottom = -top;
			var right = top * aspect;
			var left = -right;

			mat[0] = 2.0 * zNear / (right - left);
			mat[5] = 2.0 * zNear / (top - bottom);
			mat[8] = (right + left) / (right - left);
			mat[9] = (top + bottom) / (top - bottom);
			mat[10] = -(zFar + zNear) / (zFar - zNear);
			mat[11] = -1.0;
			mat[14] = -2 * zFar * zNear / (zFar - zNear);
		}
	}

	public static function vecToArray(vec:Vector4) {
		return [vec.x, vec.y, vec.z];
	}
}
