// Generated by Haxe 5.0.0-alpha.1+2f4b99d
#include <hxcpp.h>

#ifndef INCLUDED_lime_graphics_opengl_ext_OES_surfaceless_context
#include <lime/graphics/opengl/ext/OES_surfaceless_context.h>
#endif

HX_DEFINE_STACK_FRAME(_hx_pos_e453a9408eead012_6_new,"lime.graphics.opengl.ext.OES_surfaceless_context","new",0x7eb95b04,"lime.graphics.opengl.ext.OES_surfaceless_context.new","lime/graphics/opengl/ext/OES_surfaceless_context.hx",6,0x47811c0e)
namespace lime{
namespace graphics{
namespace opengl{
namespace ext{

void OES_surfaceless_context_obj::__construct(){
            	HX_STACKFRAME(&_hx_pos_e453a9408eead012_6_new)
HXDLIN(   6)		this->FRAMEBUFFER_UNDEFINED_OES = 33305;
            	}

Dynamic OES_surfaceless_context_obj::__CreateEmpty() { return new OES_surfaceless_context_obj; }

void *OES_surfaceless_context_obj::_hx_vtable = 0;

Dynamic OES_surfaceless_context_obj::__Create(::hx::DynamicArray inArgs)
{
	::hx::ObjectPtr< OES_surfaceless_context_obj > _hx_result = new OES_surfaceless_context_obj();
	_hx_result->__construct();
	return _hx_result;
}

bool OES_surfaceless_context_obj::_hx_isInstanceOf(int inClassId) {
	return inClassId==(int)0x00000001 || inClassId==(int)0x71571bc2;
}


OES_surfaceless_context_obj::OES_surfaceless_context_obj()
{
}

::hx::Val OES_surfaceless_context_obj::__Field(const ::String &inName,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 25:
		if (HX_FIELD_EQ(inName,"FRAMEBUFFER_UNDEFINED_OES") ) { return ::hx::Val( FRAMEBUFFER_UNDEFINED_OES ); }
	}
	return super::__Field(inName,inCallProp);
}

::hx::Val OES_surfaceless_context_obj::__SetField(const ::String &inName,const ::hx::Val &inValue,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 25:
		if (HX_FIELD_EQ(inName,"FRAMEBUFFER_UNDEFINED_OES") ) { FRAMEBUFFER_UNDEFINED_OES=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void OES_surfaceless_context_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_("FRAMEBUFFER_UNDEFINED_OES",bc,17,87,95));
	super::__GetFields(outFields);
};

#ifdef HXCPP_SCRIPTABLE
static ::hx::StorageInfo OES_surfaceless_context_obj_sMemberStorageInfo[] = {
	{::hx::fsInt,(int)offsetof(OES_surfaceless_context_obj,FRAMEBUFFER_UNDEFINED_OES),HX_("FRAMEBUFFER_UNDEFINED_OES",bc,17,87,95)},
	{ ::hx::fsUnknown, 0, null()}
};
static ::hx::StaticInfo *OES_surfaceless_context_obj_sStaticStorageInfo = 0;
#endif

static ::String OES_surfaceless_context_obj_sMemberFields[] = {
	HX_("FRAMEBUFFER_UNDEFINED_OES",bc,17,87,95),
	::String(null()) };

::hx::Class OES_surfaceless_context_obj::__mClass;

void OES_surfaceless_context_obj::__register()
{
	OES_surfaceless_context_obj _hx_dummy;
	OES_surfaceless_context_obj::_hx_vtable = *(void **)&_hx_dummy;
	::hx::Static(__mClass) = new ::hx::Class_obj();
	__mClass->mName = HX_("lime.graphics.opengl.ext.OES_surfaceless_context",12,c9,2e,49);
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mConstructEmpty = &__CreateEmpty;
	__mClass->mConstructArgs = &__Create;
	__mClass->mGetStaticField = &::hx::Class_obj::GetNoStaticField;
	__mClass->mSetStaticField = &::hx::Class_obj::SetNoStaticField;
	__mClass->mStatics = ::hx::Class_obj::dupFunctions(0 /* sStaticFields */);
	__mClass->mMembers = ::hx::Class_obj::dupFunctions(OES_surfaceless_context_obj_sMemberFields);
	__mClass->mCanCast = ::hx::TCanCast< OES_surfaceless_context_obj >;
#ifdef HXCPP_SCRIPTABLE
	__mClass->mMemberStorageInfo = OES_surfaceless_context_obj_sMemberStorageInfo;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mStaticStorageInfo = OES_surfaceless_context_obj_sStaticStorageInfo;
#endif
	::hx::_hx_RegisterClass(__mClass->mName, __mClass);
}

} // end namespace lime
} // end namespace graphics
} // end namespace opengl
} // end namespace ext
