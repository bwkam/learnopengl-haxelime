// Generated by Haxe 5.0.0-alpha.1+2f4b99d
#include <hxcpp.h>

#ifndef INCLUDED_lime_graphics_opengl_ext_EXT_texture_rg
#include <lime/graphics/opengl/ext/EXT_texture_rg.h>
#endif

HX_DEFINE_STACK_FRAME(_hx_pos_d8ba4f960147a2e5_4_new,"lime.graphics.opengl.ext.EXT_texture_rg","new",0x508d2dab,"lime.graphics.opengl.ext.EXT_texture_rg.new","lime/graphics/opengl/ext/EXT_texture_rg.hx",4,0xac103143)
namespace lime{
namespace graphics{
namespace opengl{
namespace ext{

void EXT_texture_rg_obj::__construct(){
            	HX_STACKFRAME(&_hx_pos_d8ba4f960147a2e5_4_new)
HXLINE(   9)		this->RG8_EXT = 33323;
HXLINE(   8)		this->R8_EXT = 33321;
HXLINE(   7)		this->RG_EXT = 33319;
HXLINE(   6)		this->RED_EXT = 6403;
            	}

Dynamic EXT_texture_rg_obj::__CreateEmpty() { return new EXT_texture_rg_obj; }

void *EXT_texture_rg_obj::_hx_vtable = 0;

Dynamic EXT_texture_rg_obj::__Create(::hx::DynamicArray inArgs)
{
	::hx::ObjectPtr< EXT_texture_rg_obj > _hx_result = new EXT_texture_rg_obj();
	_hx_result->__construct();
	return _hx_result;
}

bool EXT_texture_rg_obj::_hx_isInstanceOf(int inClassId) {
	return inClassId==(int)0x00000001 || inClassId==(int)0x0557c0a5;
}


EXT_texture_rg_obj::EXT_texture_rg_obj()
{
}

::hx::Val EXT_texture_rg_obj::__Field(const ::String &inName,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"RG_EXT") ) { return ::hx::Val( RG_EXT ); }
		if (HX_FIELD_EQ(inName,"R8_EXT") ) { return ::hx::Val( R8_EXT ); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"RED_EXT") ) { return ::hx::Val( RED_EXT ); }
		if (HX_FIELD_EQ(inName,"RG8_EXT") ) { return ::hx::Val( RG8_EXT ); }
	}
	return super::__Field(inName,inCallProp);
}

::hx::Val EXT_texture_rg_obj::__SetField(const ::String &inName,const ::hx::Val &inValue,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"RG_EXT") ) { RG_EXT=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"R8_EXT") ) { R8_EXT=inValue.Cast< int >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"RED_EXT") ) { RED_EXT=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"RG8_EXT") ) { RG8_EXT=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void EXT_texture_rg_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_("RED_EXT",33,4f,bf,4e));
	outFields->push(HX_("RG_EXT",b7,b3,b6,e9));
	outFields->push(HX_("R8_EXT",28,00,b4,46));
	outFields->push(HX_("RG8_EXT",e5,11,a7,32));
	super::__GetFields(outFields);
};

#ifdef HXCPP_SCRIPTABLE
static ::hx::StorageInfo EXT_texture_rg_obj_sMemberStorageInfo[] = {
	{::hx::fsInt,(int)offsetof(EXT_texture_rg_obj,RED_EXT),HX_("RED_EXT",33,4f,bf,4e)},
	{::hx::fsInt,(int)offsetof(EXT_texture_rg_obj,RG_EXT),HX_("RG_EXT",b7,b3,b6,e9)},
	{::hx::fsInt,(int)offsetof(EXT_texture_rg_obj,R8_EXT),HX_("R8_EXT",28,00,b4,46)},
	{::hx::fsInt,(int)offsetof(EXT_texture_rg_obj,RG8_EXT),HX_("RG8_EXT",e5,11,a7,32)},
	{ ::hx::fsUnknown, 0, null()}
};
static ::hx::StaticInfo *EXT_texture_rg_obj_sStaticStorageInfo = 0;
#endif

static ::String EXT_texture_rg_obj_sMemberFields[] = {
	HX_("RED_EXT",33,4f,bf,4e),
	HX_("RG_EXT",b7,b3,b6,e9),
	HX_("R8_EXT",28,00,b4,46),
	HX_("RG8_EXT",e5,11,a7,32),
	::String(null()) };

::hx::Class EXT_texture_rg_obj::__mClass;

void EXT_texture_rg_obj::__register()
{
	EXT_texture_rg_obj _hx_dummy;
	EXT_texture_rg_obj::_hx_vtable = *(void **)&_hx_dummy;
	::hx::Static(__mClass) = new ::hx::Class_obj();
	__mClass->mName = HX_("lime.graphics.opengl.ext.EXT_texture_rg",39,7c,0c,ba);
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mConstructEmpty = &__CreateEmpty;
	__mClass->mConstructArgs = &__Create;
	__mClass->mGetStaticField = &::hx::Class_obj::GetNoStaticField;
	__mClass->mSetStaticField = &::hx::Class_obj::SetNoStaticField;
	__mClass->mStatics = ::hx::Class_obj::dupFunctions(0 /* sStaticFields */);
	__mClass->mMembers = ::hx::Class_obj::dupFunctions(EXT_texture_rg_obj_sMemberFields);
	__mClass->mCanCast = ::hx::TCanCast< EXT_texture_rg_obj >;
#ifdef HXCPP_SCRIPTABLE
	__mClass->mMemberStorageInfo = EXT_texture_rg_obj_sMemberStorageInfo;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mStaticStorageInfo = EXT_texture_rg_obj_sStaticStorageInfo;
#endif
	::hx::_hx_RegisterClass(__mClass->mName, __mClass);
}

} // end namespace lime
} // end namespace graphics
} // end namespace opengl
} // end namespace ext
