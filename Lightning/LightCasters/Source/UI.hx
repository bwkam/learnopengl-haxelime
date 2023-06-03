import peote.text.Font;
import peote.ui.config.HAlign;
import peote.ui.interactive.UITextLine;
import peote.ui.interactive.UIDisplay;
import peote.ui.interactive.UITextPage;
import lime.ui.MouseCursor;
import peote.ui.interactive.UIElement;
import peote.ui.interactive.UIArea;
import peote.ui.style.FontStyleTiled;
import peote.ui.config.TextConfig;
import peote.ui.style.BoxStyle;
import peote.ui.event.WheelEvent;
import peote.ui.event.PointerEvent;
import peote.ui.interactive.UISlider;
import peote.ui.config.SliderConfig;
import peote.view.Color;
import peote.ui.style.RoundBorderStyle;
import lime.ui.Window;
import lime.app.Application;
import peote.ui.PeoteUIDisplay;
import peote.view.PeoteView;

class UI {
	public static var peoteView:PeoteView;
	private static var uiDisplay:PeoteUIDisplay;
	private static var window:Window;

	private static var lightAmbient:Float;
	private static var lightDiffuse:Float;
	private static var lightSpecular:Float;

	private static var materialAmbient:Float;
	private static var materialSpecular:Float;

	public function new() {
		createUI();
	}

	public static function createUI() {
		var sliderHeight = 20;
		var leftGap = 10;
		var rightGap = 10;
		var size = 200 - leftGap - rightGap;
		var gapText = 20;
		var gap = 32;
		var yPos = 0;

		window = Application.current.window;
		peoteView = new PeoteView(window, false);
		uiDisplay = new PeoteUIDisplay(0, 0, window.width, window.height);
		peoteView.addDisplay(uiDisplay);

		var boxStyle = new BoxStyle(0x041144ff);
		var roundBorderStyle = new RoundBorderStyle(Color.GREY2);

		var fontStyle = new FontStyleTiled();
		fontStyle.color = Color.GREY6;

		var sliderConfig:SliderConfig = {
			backgroundStyle: roundBorderStyle.copy(Color.GREY2),
			draggerStyle: roundBorderStyle.copy(Color.GREY3, Color.GREY2, 0.5),
			draggerSize: 16,
			draggSpace: 1,
		};

		var area = new UIArea(window.width - 200, 0, 200, window.height, roundBorderStyle);
		uiDisplay.add(area);

		// this looks complicate but need if you zoom the peoteView or UIDisplay
		area.setDragArea(Std.int(-uiDisplay.xOffset / uiDisplay.xz), Std.int(-uiDisplay.yOffset / uiDisplay.yz), Std.int(uiDisplay.width / uiDisplay.xz),
			Std.int(uiDisplay.height / uiDisplay.yz));

		var lightAmbientSlider = new UISlider(leftGap, yPos += gapText, size, sliderHeight, sliderConfig);
		lightAmbientSlider.onMouseWheel = (s:UISlider, e:WheelEvent) -> s.setWheelDelta(e.deltaY);
		lightAmbientSlider.onChange = (s:UISlider, value:Float, percent:Float) -> lightAmbient = value;
		area.add(lightAmbientSlider);

		PeoteUIDisplay.registerEvents(window);
	}

	public static function getVals() {
		return {
			lightAmbient: lightAmbient,
			lightDiffuse: lightDiffuse,
			lightSpecular: lightSpecular,
			materialSpecular: materialSpecular,
		}
	}
}
