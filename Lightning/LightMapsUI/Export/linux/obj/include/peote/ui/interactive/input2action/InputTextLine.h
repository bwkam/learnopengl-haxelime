// Generated by Haxe 5.0.0-alpha.1+2f4b99d
#ifndef INCLUDED_peote_ui_interactive_input2action_InputTextLine
#define INCLUDED_peote_ui_interactive_input2action_InputTextLine

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS1(haxe,IMap)
HX_DECLARE_CLASS2(haxe,ds,StringMap)
HX_DECLARE_CLASS1(input2action,ActionConfigItem)
HX_DECLARE_CLASS1(input2action,Input2Action)
HX_DECLARE_CLASS4(peote,ui,interactive,input2action,InputTextLine)
HX_DECLARE_CLASS4(peote,ui,interactive,interfaces,ActionTextLine)

namespace peote{
namespace ui{
namespace interactive{
namespace input2action{


class HXCPP_CLASS_ATTRIBUTES InputTextLine_obj : public ::hx::Object
{
	public:
		typedef ::hx::Object super;
		typedef InputTextLine_obj OBJ_;
		InputTextLine_obj();

	public:
		enum { _hx_ClassId = 0x3bb49906 };

		void __construct();
		inline void *operator new(size_t inSize, bool inContainer=false,const char *inName="peote.ui.interactive.input2action.InputTextLine")
			{ return ::hx::Object::operator new(inSize,inContainer,inName); }
		inline void *operator new(size_t inSize, int extra)
			{ return ::hx::Object::operator new(inSize+extra,false,"peote.ui.interactive.input2action.InputTextLine"); }

		inline static ::hx::ObjectPtr< InputTextLine_obj > __new() {
			::hx::ObjectPtr< InputTextLine_obj > __this = new InputTextLine_obj();
			__this->__construct();
			return __this;
		}

		inline static ::hx::ObjectPtr< InputTextLine_obj > __alloc(::hx::Ctx *_hx_ctx) {
			InputTextLine_obj *__this = (InputTextLine_obj*)(::hx::Ctx::alloc(_hx_ctx, sizeof(InputTextLine_obj), false, "peote.ui.interactive.input2action.InputTextLine"));
			*(void **)__this = InputTextLine_obj::_hx_vtable;
			return __this;
		}

		static void * _hx_vtable;
		static Dynamic __CreateEmpty();
		static Dynamic __Create(::hx::DynamicArray inArgs);
		//~InputTextLine_obj();

		HX_DO_RTTI_ALL;
		static bool __GetStatic(const ::String &inString, Dynamic &outValue, ::hx::PropertyAccess inCallProp);
		static bool __SetStatic(const ::String &inString, Dynamic &ioValue, ::hx::PropertyAccess inCallProp);
		static void __register();
		bool _hx_isInstanceOf(int inClassId);
		::String __ToString() const { return HX_("InputTextLine",4b,55,40,21); }

		static void __boot();
		static ::Array< ::Dynamic> actionConfig;
		static  ::haxe::ds::StringMap actionMap;
		static  ::input2action::Input2Action input2Action;
		static ::Dynamic focusElement;
		static void deleteChar(bool _,int _1);
		static ::Dynamic deleteChar_dyn();

		static void backspace(bool _,int _1);
		static ::Dynamic backspace_dyn();

		static void delLeft(bool _,int _1);
		static ::Dynamic delLeft_dyn();

		static void delRight(bool _,int _1);
		static ::Dynamic delRight_dyn();

		static void tabulator(bool _,int _1);
		static ::Dynamic tabulator_dyn();

		static void copyToClipboard(bool _,int _1);
		static ::Dynamic copyToClipboard_dyn();

		static void cutToClipboard(bool _,int _1);
		static ::Dynamic cutToClipboard_dyn();

		static void pasteFromClipboard(bool _,int _1);
		static ::Dynamic pasteFromClipboard_dyn();

		static bool isShift;
		static void shiftModifier(bool isDown,int _);
		static ::Dynamic shiftModifier_dyn();

		static void selectAll(bool _,int _1);
		static ::Dynamic selectAll_dyn();

		static void undo(bool _,int _1);
		static ::Dynamic undo_dyn();

		static void redo(bool _,int _1);
		static ::Dynamic redo_dyn();

		static void cursorStart(bool _,int _1);
		static ::Dynamic cursorStart_dyn();

		static void cursorEnd(bool _,int _1);
		static ::Dynamic cursorEnd_dyn();

		static void cursorLeft(bool _,int _1);
		static ::Dynamic cursorLeft_dyn();

		static void cursorRight(bool _,int _1);
		static ::Dynamic cursorRight_dyn();

		static void cursorLeftWord(bool _,int _1);
		static ::Dynamic cursorLeftWord_dyn();

		static void cursorRightWord(bool _,int _1);
		static ::Dynamic cursorRightWord_dyn();

};

} // end namespace peote
} // end namespace ui
} // end namespace interactive
} // end namespace input2action

#endif /* INCLUDED_peote_ui_interactive_input2action_InputTextLine */ 
