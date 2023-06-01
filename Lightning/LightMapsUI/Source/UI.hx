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

	private static var materialSpecular:Float;

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
		uiDisplay = new PeoteUIDisplay(30, 30, 220, 400, Color.CYAN);
		peoteView.addDisplay(uiDisplay);

		var boxStyle = new BoxStyle(0x041144ff);

		var roundBorderStyle = RoundBorderStyle.createById(0);

		var cursorStyle = BoxStyle.createById(1, Color.RED);
		var selectionStyle = BoxStyle.createById(2, Color.GREY3);

		var fontStyleHeader = FontStyleTiled.createById(0);
		var fontStyleInput = FontStyleTiled.createById(1);

		var textInputConfig:TextConfig = {
			backgroundStyle: boxStyle.copy(Color.GREY5),
			selectionStyle: selectionStyle,
			cursorStyle: cursorStyle
		}

		var sliderConfig:SliderConfig = {
			backgroundStyle: roundBorderStyle.copy(Color.GREY2),
			draggerStyle: roundBorderStyle.copy(Color.GREY3, Color.GREY2, 0.5),
			draggerSize: 16,
			draggSpace: 1,
		};

		uiDisplay = new PeoteUIDisplay(10, 10, window.width - 20, window.height - 20, Color.GREY1, [
			roundBorderStyle,
			boxStyle,
			selectionStyle,
			fontStyleInput,
			fontStyleHeader,
			cursorStyle
		]);

		peoteView.addDisplay(uiDisplay);

		var area = new UIArea(50, 50, 500, 500, roundBorderStyle);
		uiDisplay.add(area);

		area.setDragArea(Std.int(-uiDisplay.xOffset / uiDisplay.xz), Std.int(-uiDisplay.yOffset / uiDisplay.yz), Std.int(uiDisplay.width / uiDisplay.xz),
			Std.int(uiDisplay.height / uiDisplay.yz));

		var header = new UITextLine<FontStyleTiled>(0, 0, 500, 0, 1, "=== UIArea ===", null, fontStyleHeader,
			{backgroundStyle: roundBorderStyle, hAlign: HAlign.CENTER});
		header.onPointerDown = (_, e:PointerEvent) -> area.startDragging(e);
		header.onPointerUp = (_, e:PointerEvent) -> area.stopDragging(e);
		area.add(header);

		var content = new UIArea(2, header.height, area.width - 20 - 2, area.height - header.height - 20, boxStyle);
		area.add(content);

		// ---- add content ----

		var uiDisplay = new UIDisplay(20, 20, 200, 200, 1, Color.BLUE);
		uiDisplay.onPointerOver = (_, _) -> uiDisplay.display.color = Color.RED;
		uiDisplay.onPointerOut = (_, _) -> uiDisplay.display.color = Color.BLUE;
		uiDisplay.onPointerDown = (_, e:PointerEvent) -> {
			uiDisplay.setDragArea(Std.int(content.x), Std.int(content.y), Std.int(content.width + uiDisplay.width - 10),
				Std.int(content.height + uiDisplay.height - 10));
			uiDisplay.startDragging(e);
		}
		uiDisplay.onPointerUp = (_, e:PointerEvent) -> uiDisplay.stopDragging(e);
		uiDisplay.onDrag = (_, x:Float, y:Float) -> {
			content.updateInnerSize();
			uiDisplay.maskByElement(content, true);
		}
		content.add(uiDisplay);

		var uiElement = new UIElement(220, 20, 200, 200, 0, roundBorderStyle);
		uiElement.onPointerDown = (_, e:PointerEvent) -> {
			uiElement.setDragArea(Std.int(content.x), Std.int(content.y), Std.int(content.width + uiElement.width - 10),
				Std.int(content.height + uiElement.height - 10));
			uiElement.startDragging(e);
		}
		uiElement.onPointerUp = (_, e:PointerEvent) -> uiElement.stopDragging(e);
		uiElement.onDrag = (_, x:Float, y:Float) -> {
			content.updateInnerSize();
			uiElement.maskByElement(content, true);
		}
		content.add(uiElement);

		var inputPage = new UITextPage<FontStyleTiled>(250, 300, 0, 0, 1, "input\ntext by\nUIText\tPage", font, fontStyleInput, textInputConfig);
		inputPage.onPointerDown = function(t:UITextPage<FontStyleTiled>, e:PointerEvent) {
			t.setInputFocus(e);
			t.startSelection(e);
		}
		inputPage.onPointerUp = function(t:UITextPage<FontStyleTiled>, e:PointerEvent) {
			t.stopSelection(e);
		}
		inputPage.onResizeWidth = (_, width:Int, deltaWidth:Int) -> {
			content.updateInnerSize();
			inputPage.maskByElement(content, true); // CHECK: need here ?
		}
		inputPage.onResizeHeight = (_, height:Int, deltaHeight:Int) -> {
			content.updateInnerSize();
			inputPage.maskByElement(content, true); // CHECK: need here ?
		}
		content.add(inputPage);

		// ---------------------------------------------------------
		// ---- Sliders to scroll the innerArea ----
		// ---------------------------------------------------------

		var hSlider = new UISlider(0, area.height - 20, area.width - 20, 20, sliderConfig);
		hSlider.onMouseWheel = (_, e:WheelEvent) -> hSlider.setWheelDelta(e.deltaY);
		area.add(hSlider);

		var vSlider = new UISlider(area.width - 20, header.height, 20, area.height - header.height - 20, sliderConfig);
		vSlider.onMouseWheel = (_, e:WheelEvent) -> vSlider.setWheelDelta(e.deltaY);
		area.add(vSlider);

		// bindings for sliders
		content.bindHSlider(hSlider);
		content.bindVSlider(vSlider);

		// all here automatic after binding content to sliders
		/*
			// ----- initial ranges for sliders ------
			hSlider.setRange( 0, Math.min(0, content.width - content.innerRight), content.width/content.innerRight, false, false );
			vSlider.setRange( 0, Math.min(0, content.height - content.innerBottom), content.height/content.innerBottom , false, false);		

			hSlider.onChange = (_, value:Float, percent:Float) -> {
				content.xOffset = Std.int(value);
				content.updateLayout();
			}
			vSlider.onChange = (_, value:Float, percent:Float) -> {
				content.yOffset = Std.int(value);
				content.updateLayout();
			}

			// ----- update Sliders if content size is changed -----

			content.onResizeInnerWidth = content.onResizeWidth = (_, width:Int, deltaWidth:Int) -> {
				hSlider.setRange( 0, Math.min(0, content.width - content.innerRight), content.width/content.innerRight, true, false );
				//hSlider.setRange( 0, content.width - content.innerRight, content.width/content.innerRight, true, false );
				//hSlider.setRange( content.xOffsetStart, content.xOffsetEnd, false, false );
			}

			content.onResizeInnerHeight = content.onResizeHeight = (_, height:Int, deltaHeight:Int) -> {
				vSlider.setRange( 0, Math.min(0, content.height - content.innerBottom), content.height/content.innerBottom, true, false );
				//vSlider.setRange( content.yOffsetStart, content.yOffsetEnd, false, false );
			}

			content.onChangeXOffset = (_, xOffset:Float, deltaXOffset:Float) -> {
				hSlider.setValue( xOffset);
			}
			content.onChangeYOffset = (_, yOffset:Float, deltaYOffset:Float) -> {
				vSlider.setValue( yOffset);
			}				
		 */

		// ---------------------------------------------
		// -------- button to change the size ----------
		// ---------------------------------------------

		var resizerBottomRight:UIElement = new UIElement(area.width - 19, area.height - 19, 18, 18, 2, roundBorderStyle.copy(Color.GREY3, Color.GREY1));

		// resizerBottomRight.onPointerDown = (_, e:PointerEvent) -> {
		// 	resizerBottomRight.setDragArea(Std.int(area.x + 240), Std.int(area.y + 140),
		// 		Std.int((uiDisplay.width - uiDisplay.xOffset) / uiDisplay.xz - area.x - 240),
		// 		Std.int((uiDisplay.height - uiDisplay.yOffset) / uiDisplay.yz - area.y - 140));
		// 	resizerBottomRight.startDragging(e);
		// }
		resizerBottomRight.onPointerUp = (_, e:PointerEvent) -> resizerBottomRight.stopDragging(e);

		resizerBottomRight.onDrag = (_, x:Float, y:Float) -> {
			area.rightSize = resizerBottomRight.right + 1;
			area.bottomSize = resizerBottomRight.bottom + 1;
			area.updateLayout();
		};
		resizerBottomRight.onPointerOver = (_, _) -> window.cursor = MouseCursor.RESIZE_NWSE;
		resizerBottomRight.onPointerOut = (_, _) -> window.cursor = MouseCursor.DEFAULT;

		area.add(resizerBottomRight);

		// --- arrange header and sliders if area size is changing ---

		area.onResizeWidth = (_, width:Int, deltaWidth:Int) -> {
			header.width = width;
			vSlider.right = area.right;
			content.rightSize = hSlider.rightSize = vSlider.left;
		}

		area.onResizeHeight = (_, height:Int, deltaHeight:Int) -> {
			hSlider.bottom = area.bottom;
			content.bottomSize = vSlider.bottomSize = hSlider.top;
		}

		PeoteUIDisplay.registerEvents(window);
	}

	public static function getVals() {
		return {
			lightAmbient: 0,
			lightDiffuse: 0,
			lightSpecular: 0,
			materialAmbient: 0,
			materialSpecular: 0,
		}
	}
}
