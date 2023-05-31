import lime.app.Application;
import lime.math.Vector4;

class Camera {
	public static var moveLeft:Bool = false;
	public static var moveRight:Bool = false;
	public static var moveForward:Bool = false;
	public static var moveBackward:Bool = false;

	public static var speed:Int;

	public static var firstMouse:Bool = true;
	public static var lastX:Float;
	public static var lastY:Float;
	public static var xOffset:Float;
	public static var yOffset:Float;
	public static var sensitivity:Float;
	public static var yaw:Float = -90.0;
	public static var pitch:Float = 0.0;
	public static var fov:Float = 45.0;

	public static var pos:Vector4;
	public static var front:Vector4;
	public static var up:Vector4;

	public static function init() {
		lastX = Application.current.window.width / 2;
		lastY = Application.current.window.height / 2;
		speed = 10;
		pos = new Vector4(0.0, 0.0, 10.0, 1.0);
		front = new Vector4(0.0, 0.0, -1.0, 1.0);
		up = new Vector4(0.0, 1.0, 0.0, 1.0);
	}

	public static function moveCamera(delta:Float):Void {
		var camSpeed = 10 * delta;
		if (moveForward) {
			var tgt = front.clone();
			tgt.normalize();
			tgt.scaleBy(camSpeed);
			pos = pos.add(tgt);
		}
		if (moveBackward) {
			var tgt = front.clone();
			tgt.normalize();
			tgt.scaleBy(camSpeed);
			pos = pos.subtract(tgt);
		}
		if (moveLeft) {
			var m = front.crossProduct(up);
			m.normalize();
			m.scaleBy(camSpeed);
			pos = pos.subtract(m);
		}
		if (moveRight) {
			var m = front.crossProduct(up);
			m.normalize();
			m.scaleBy(camSpeed);
			pos = pos.add(m);
		}
	}

	public static function onMouseMove(x:Float, y:Float) {
		if (firstMouse) {
			lastX = x;
			lastY = y;
			firstMouse = false;
		}
		sensitivity = 0.1;
		xOffset = x - lastX;
		yOffset = lastY - y;
		lastX = x;
		lastY = y;
		xOffset *= sensitivity;
		yOffset *= sensitivity;
		yaw += xOffset;
		pitch += yOffset;
		if (pitch > 89.0)
			pitch = 89.0;
		if (pitch < -89.0)
			pitch = -89.0;
		var direction:Vector4 = new Vector4();
		direction.x = Math.cos(yaw * Math.PI / 180) * Math.cos(pitch * Math.PI / 180);
		direction.y = Math.sin(pitch * Math.PI / 180);
		direction.z = Math.sin(yaw * Math.PI / 180) * Math.cos(pitch * Math.PI / 180);
		direction.normalize();
		front = direction;
	}
}
