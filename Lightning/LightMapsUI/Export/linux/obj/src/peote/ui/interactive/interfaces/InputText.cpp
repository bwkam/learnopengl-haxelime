// Generated by Haxe 5.0.0-alpha.1+2f4b99d
#include <hxcpp.h>

#ifndef INCLUDED_peote_ui_interactive_interfaces_InputText
#include <peote/ui/interactive/interfaces/InputText.h>
#endif

namespace peote{
namespace ui{
namespace interactive{
namespace interfaces{


static ::String InputText_obj_sMemberFields[] = {
	HX_("onSelect",7b,11,e0,49),
	::String(null()) };

::hx::Class InputText_obj::__mClass;

void InputText_obj::__register()
{
	::hx::Static(__mClass) = new ::hx::Class_obj();
	__mClass->mName = HX_("peote.ui.interactive.interfaces.InputText",26,95,9f,06);
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mMembers = ::hx::Class_obj::dupFunctions(InputText_obj_sMemberFields);
	__mClass->mCanCast = ::hx::TIsInterface< (int)0x9a189dda >;
	::hx::_hx_RegisterClass(__mClass->mName, __mClass);
}

} // end namespace peote
} // end namespace ui
} // end namespace interactive
} // end namespace interfaces
