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

	private static var lightAmbient:Float = 0.5;
	private static var lightDiffuse:Float = 1.0;
	private static var lightSpecular:Float = 2.0;

	private static var materialAmbient:Float = 2.0;
	private static var materialSpecular:Float = 2.0;

	public function new() {
		try {
			new Font<FontStyleTiled>("assets/hack_ascii.json").load(createUI);
		} catch (_) {
			trace(haxe.CallStack.toString(haxe.CallStack.exceptionStack()), _);
		}
	}

	public static function createUI(font:Font<FontStyleTiled>) {
		window = Application.current.window;
		peoteView = new PeoteView(window, false);

		uiDisplay = new PeoteUIDisplay(0, 0, window.width, window.height);
		peoteView.addDisplay(uiDisplay);

		// ------------------
		// ----- Styles -----
		// ------------------

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

		// ------------------
		// ----- UIArea -----
		// ------------------

		var area = new UIArea(50, 50, 200, 300, roundBorderStyle);
		uiDisplay.add(area);

		// this looks complicate but need if you zoom the peoteView or UIDisplay
		area.setDragArea(Std.int(-uiDisplay.xOffset / uiDisplay.xz), Std.int(-uiDisplay.yOffset / uiDisplay.yz), Std.int(uiDisplay.width / uiDisplay.xz),
			Std.int(uiDisplay.height / uiDisplay.yz));

		// ---- add content to area ----

		var header = new UITextLine<FontStyleTiled>(0, 0, area.width, 0, 1, "=== Header ===", font, fontStyle,
			{backgroundStyle: roundBorderStyle, hAlign: HAlign.CENTER});
		header.onPointerDown = (_, e:PointerEvent) -> area.startDragging(e);
		header.onPointerUp = (_, e:PointerEvent) -> area.stopDragging(e);
		area.add(header);

		// ---- Descriptions and Sliders -----

		var sliderHeight = 20;
		var leftGap = 10;
		var rightGap = 10;
		var size = area.width - leftGap - rightGap;
		var gapText = 20;
		var gap = 32;
		var yPos = 0;

		var lightAmbientText = new UITextLine<FontStyleTiled>(leftGap, yPos += gap, size, 0, 1, "lightAmbient", font, fontStyle);
		area.add(lightAmbientText);

		var lightAmbientSlider = new UISlider(leftGap, yPos += gapText, size, sliderHeight, sliderConfig);
		lightAmbientSlider.value = lightAmbient;
		lightAmbientSlider.onMouseWheel = (s:UISlider, e:WheelEvent) -> s.setWheelDelta(e.deltaY);
		lightAmbientSlider.onChange = (s:UISlider, value:Float, percent:Float) -> lightAmbient = value;
		area.add(lightAmbientSlider);

		var lightDiffuseText = new UITextLine<FontStyleTiled>(leftGap, yPos += gap, size, 0, 1, "lightDiffuse", font, fontStyle);
		area.add(lightDiffuseText);

		var lightDiffuseSlider = new UISlider(leftGap, yPos += gapText, size, sliderHeight, sliderConfig);
		lightDiffuseSlider.value = lightDiffuse;
		lightDiffuseSlider.onMouseWheel = (s:UISlider, e:WheelEvent) -> s.setWheelDelta(e.deltaY);
		lightDiffuseSlider.onChange = (s:UISlider, value:Float, percent:Float) -> lightDiffuse = value;
		area.add(lightDiffuseSlider);

		PeoteUIDisplay.registerEvents(window);
	}

	public static function getVals() {
		return {
			lightAmbient: lightAmbient,
			lightDiffuse: lightDiffuse,
			lightSpecular: 2,
			materialAmbient: 2,
			materialSpecular: 2,
		}
	}
}
