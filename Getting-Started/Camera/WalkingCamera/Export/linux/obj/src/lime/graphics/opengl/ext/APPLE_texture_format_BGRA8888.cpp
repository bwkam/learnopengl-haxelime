// Generated by Haxe 5.0.0-alpha.1+2f4b99d
#include <hxcpp.h>

#ifndef INCLUDED_lime_graphics_opengl_ext_APPLE_texture_format_BGRA8888
#include <lime/graphics/opengl/ext/APPLE_texture_format_BGRA8888.h>
#endif

HX_DEFINE_STACK_FRAME(_hx_pos_315ede9a8526b069_6_new,"lime.graphics.opengl.ext.APPLE_texture_format_BGRA8888","new",0x11d71fa3,"lime.graphics.opengl.ext.APPLE_texture_format_BGRA8888.new","lime/graphics/opengl/ext/APPLE_texture_format_BGRA8888.hx",6,0x566515cf)
namespace lime{
namespace graphics{
namespace opengl{
namespace ext{

void APPLE_texture_format_BGRA8888_obj::__construct(){
            	HX_STACKFRAME(&_hx_pos_315ede9a8526b069_6_new)
HXDLIN(   6)		this->BGRA_EXT = 32993;
            	}

Dynamic APPLE_texture_format_BGRA8888_obj::__CreateEmpty() { return new APPLE_texture_format_BGRA8888_obj; }

void *APPLE_texture_format_BGRA8888_obj::_hx_vtable = 0;

Dynamic APPLE_texture_format_BGRA8888_obj::__Create(::hx::DynamicArray inArgs)
{
	::hx::ObjectPtr< APPLE_texture_format_BGRA8888_obj > _hx_result = new APPLE_texture_format_BGRA8888_obj();
	_hx_result->__construct();
	return _hx_result;
}

bool APPLE_texture_format_BGRA8888_obj::_hx_isInstanceOf(int inClassId) {
	return inClassId==(int)0x00000001 || inClassId==(int)0x0efb88e1;
}


APPLE_texture_format_BGRA8888_obj::APPLE_texture_format_BGRA8888_obj()
{
}

::hx::Val APPLE_texture_format_BGRA8888_obj::__Field(const ::String &inName,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 8:
		if (HX_FIELD_EQ(inName,"BGRA_EXT") ) { return ::hx::Val( BGRA_EXT ); }
	}
	return super::__Field(inName,inCallProp);
}

::hx::Val APPLE_texture_format_BGRA8888_obj::__SetField(const ::String &inName,const ::hx::Val &inValue,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 8:
		if (HX_FIELD_EQ(inName,"BGRA_EXT") ) { BGRA_EXT=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void APPLE_texture_format_BGRA8888_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_("BGRA_EXT",36,94,c4,bc));
	super::__GetFields(outFields);
};

#ifdef HXCPP_SCRIPTABLE
static ::hx::StorageInfo APPLE_texture_format_BGRA8888_obj_sMemberStorageInfo[] = {
	{::hx::fsInt,(int)offsetof(APPLE_texture_format_BGRA8888_obj,BGRA_EXT),HX_("BGRA_EXT",36,94,c4,bc)},
	{ ::hx::fsUnknown, 0, null()}
};
static ::hx::StaticInfo *APPLE_texture_format_BGRA8888_obj_sStaticStorageInfo = 0;
#endif

static ::String APPLE_texture_format_BGRA8888_obj_sMemberFields[] = {
	HX_("BGRA_EXT",36,94,c4,bc),
	::String(null()) };

::hx::Class APPLE_texture_format_BGRA8888_obj::__mClass;

void APPLE_texture_format_BGRA8888_obj::__register()
{
	APPLE_texture_format_BGRA8888_obj _hx_dummy;
	APPLE_texture_format_BGRA8888_obj::_hx_vtable = *(void **)&_hx_dummy;
	::hx::Static(__mClass) = new ::hx::Class_obj();
	__mClass->mName = HX_("lime.graphics.opengl.ext.APPLE_texture_format_BGRA8888",31,12,08,e2);
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mConstructEmpty = &__CreateEmpty;
	__mClass->mConstructArgs = &__Create;
	__mClass->mGetStaticField = &::hx::Class_obj::GetNoStaticField;
	__mClass->mSetStaticField = &::hx::Class_obj::SetNoStaticField;
	__mClass->mStatics = ::hx::Class_obj::dupFunctions(0 /* sStaticFields */);
	__mClass->mMembers = ::hx::Class_obj::dupFunctions(APPLE_texture_format_BGRA8888_obj_sMemberFields);
	__mClass->mCanCast = ::hx::TCanCast< APPLE_texture_format_BGRA8888_obj >;
#ifdef HXCPP_SCRIPTABLE
	__mClass->mMemberStorageInfo = APPLE_texture_format_BGRA8888_obj_sMemberStorageInfo;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mStaticStorageInfo = APPLE_texture_format_BGRA8888_obj_sStaticStorageInfo;
#endif
	::hx::_hx_RegisterClass(__mClass->mName, __mClass);
}

} // end namespace lime
} // end namespace graphics
} // end namespace opengl
} // end namespace ext
