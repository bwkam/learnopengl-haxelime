// Generated by Haxe 5.0.0-alpha.1+2f4b99d
#include <hxcpp.h>

#ifndef INCLUDED_lime_graphics_opengl_ext_AMD_compressed_3DC_texture
#include <lime/graphics/opengl/ext/AMD_compressed_3DC_texture.h>
#endif

HX_DEFINE_STACK_FRAME(_hx_pos_d2a7e04602cd59d8_4_new,"lime.graphics.opengl.ext.AMD_compressed_3DC_texture","new",0x9572fa2b,"lime.graphics.opengl.ext.AMD_compressed_3DC_texture.new","lime/graphics/opengl/ext/AMD_compressed_3DC_texture.hx",4,0x59f1a9c3)
namespace lime{
namespace graphics{
namespace opengl{
namespace ext{

void AMD_compressed_3DC_texture_obj::__construct(){
            	HX_STACKFRAME(&_hx_pos_d2a7e04602cd59d8_4_new)
HXLINE(   7)		this->_3DC_XY_AMD = 34810;
HXLINE(   6)		this->_3DC_X_AMD = 34809;
            	}

Dynamic AMD_compressed_3DC_texture_obj::__CreateEmpty() { return new AMD_compressed_3DC_texture_obj; }

void *AMD_compressed_3DC_texture_obj::_hx_vtable = 0;

Dynamic AMD_compressed_3DC_texture_obj::__Create(::hx::DynamicArray inArgs)
{
	::hx::ObjectPtr< AMD_compressed_3DC_texture_obj > _hx_result = new AMD_compressed_3DC_texture_obj();
	_hx_result->__construct();
	return _hx_result;
}

bool AMD_compressed_3DC_texture_obj::_hx_isInstanceOf(int inClassId) {
	return inClassId==(int)0x00000001 || inClassId==(int)0x0ff1fa41;
}


AMD_compressed_3DC_texture_obj::AMD_compressed_3DC_texture_obj()
{
}

::hx::Val AMD_compressed_3DC_texture_obj::__Field(const ::String &inName,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 10:
		if (HX_FIELD_EQ(inName,"_3DC_X_AMD") ) { return ::hx::Val( _3DC_X_AMD ); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"_3DC_XY_AMD") ) { return ::hx::Val( _3DC_XY_AMD ); }
	}
	return super::__Field(inName,inCallProp);
}

::hx::Val AMD_compressed_3DC_texture_obj::__SetField(const ::String &inName,const ::hx::Val &inValue,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 10:
		if (HX_FIELD_EQ(inName,"_3DC_X_AMD") ) { _3DC_X_AMD=inValue.Cast< int >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"_3DC_XY_AMD") ) { _3DC_XY_AMD=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void AMD_compressed_3DC_texture_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_("_3DC_X_AMD",25,fa,65,5b));
	outFields->push(HX_("_3DC_XY_AMD",e6,be,38,3d));
	super::__GetFields(outFields);
};

#ifdef HXCPP_SCRIPTABLE
static ::hx::StorageInfo AMD_compressed_3DC_texture_obj_sMemberStorageInfo[] = {
	{::hx::fsInt,(int)offsetof(AMD_compressed_3DC_texture_obj,_3DC_X_AMD),HX_("_3DC_X_AMD",25,fa,65,5b)},
	{::hx::fsInt,(int)offsetof(AMD_compressed_3DC_texture_obj,_3DC_XY_AMD),HX_("_3DC_XY_AMD",e6,be,38,3d)},
	{ ::hx::fsUnknown, 0, null()}
};
static ::hx::StaticInfo *AMD_compressed_3DC_texture_obj_sStaticStorageInfo = 0;
#endif

static ::String AMD_compressed_3DC_texture_obj_sMemberFields[] = {
	HX_("_3DC_X_AMD",25,fa,65,5b),
	HX_("_3DC_XY_AMD",e6,be,38,3d),
	::String(null()) };

::hx::Class AMD_compressed_3DC_texture_obj::__mClass;

void AMD_compressed_3DC_texture_obj::__register()
{
	AMD_compressed_3DC_texture_obj _hx_dummy;
	AMD_compressed_3DC_texture_obj::_hx_vtable = *(void **)&_hx_dummy;
	::hx::Static(__mClass) = new ::hx::Class_obj();
	__mClass->mName = HX_("lime.graphics.opengl.ext.AMD_compressed_3DC_texture",b9,08,f2,db);
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mConstructEmpty = &__CreateEmpty;
	__mClass->mConstructArgs = &__Create;
	__mClass->mGetStaticField = &::hx::Class_obj::GetNoStaticField;
	__mClass->mSetStaticField = &::hx::Class_obj::SetNoStaticField;
	__mClass->mStatics = ::hx::Class_obj::dupFunctions(0 /* sStaticFields */);
	__mClass->mMembers = ::hx::Class_obj::dupFunctions(AMD_compressed_3DC_texture_obj_sMemberFields);
	__mClass->mCanCast = ::hx::TCanCast< AMD_compressed_3DC_texture_obj >;
#ifdef HXCPP_SCRIPTABLE
	__mClass->mMemberStorageInfo = AMD_compressed_3DC_texture_obj_sMemberStorageInfo;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mStaticStorageInfo = AMD_compressed_3DC_texture_obj_sStaticStorageInfo;
#endif
	::hx::_hx_RegisterClass(__mClass->mName, __mClass);
}

} // end namespace lime
} // end namespace graphics
} // end namespace opengl
} // end namespace ext
