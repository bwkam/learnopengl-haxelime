// Generated by Haxe 5.0.0-alpha.1+2f4b99d
#include <hxcpp.h>

#ifndef INCLUDED_lime_graphics_opengl_ext_QCOM_driver_control
#include <lime/graphics/opengl/ext/QCOM_driver_control.h>
#endif

HX_DEFINE_STACK_FRAME(_hx_pos_0a23424fb5ae89d7_5_new,"lime.graphics.opengl.ext.QCOM_driver_control","new",0x1b676c45,"lime.graphics.opengl.ext.QCOM_driver_control.new","lime/graphics/opengl/ext/QCOM_driver_control.hx",5,0x7b71f4ed)
namespace lime{
namespace graphics{
namespace opengl{
namespace ext{

void QCOM_driver_control_obj::__construct(){
            	HX_STACKFRAME(&_hx_pos_0a23424fb5ae89d7_5_new)
            	}

Dynamic QCOM_driver_control_obj::__CreateEmpty() { return new QCOM_driver_control_obj; }

void *QCOM_driver_control_obj::_hx_vtable = 0;

Dynamic QCOM_driver_control_obj::__Create(::hx::DynamicArray inArgs)
{
	::hx::ObjectPtr< QCOM_driver_control_obj > _hx_result = new QCOM_driver_control_obj();
	_hx_result->__construct();
	return _hx_result;
}

bool QCOM_driver_control_obj::_hx_isInstanceOf(int inClassId) {
	return inClassId==(int)0x00000001 || inClassId==(int)0x503219e7;
}


QCOM_driver_control_obj::QCOM_driver_control_obj()
{
}

#ifdef HXCPP_SCRIPTABLE
static ::hx::StorageInfo *QCOM_driver_control_obj_sMemberStorageInfo = 0;
static ::hx::StaticInfo *QCOM_driver_control_obj_sStaticStorageInfo = 0;
#endif

::hx::Class QCOM_driver_control_obj::__mClass;

void QCOM_driver_control_obj::__register()
{
	QCOM_driver_control_obj _hx_dummy;
	QCOM_driver_control_obj::_hx_vtable = *(void **)&_hx_dummy;
	::hx::Static(__mClass) = new ::hx::Class_obj();
	__mClass->mName = HX_("lime.graphics.opengl.ext.QCOM_driver_control",d3,e5,48,f8);
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mConstructEmpty = &__CreateEmpty;
	__mClass->mConstructArgs = &__Create;
	__mClass->mGetStaticField = &::hx::Class_obj::GetNoStaticField;
	__mClass->mSetStaticField = &::hx::Class_obj::SetNoStaticField;
	__mClass->mStatics = ::hx::Class_obj::dupFunctions(0 /* sStaticFields */);
	__mClass->mMembers = ::hx::Class_obj::dupFunctions(0 /* sMemberFields */);
	__mClass->mCanCast = ::hx::TCanCast< QCOM_driver_control_obj >;
#ifdef HXCPP_SCRIPTABLE
	__mClass->mMemberStorageInfo = QCOM_driver_control_obj_sMemberStorageInfo;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mStaticStorageInfo = QCOM_driver_control_obj_sStaticStorageInfo;
#endif
	::hx::_hx_RegisterClass(__mClass->mName, __mClass);
}

} // end namespace lime
} // end namespace graphics
} // end namespace opengl
} // end namespace ext
