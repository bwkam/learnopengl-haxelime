// Generated by Haxe 5.0.0-alpha.1+2f4b99d
#include <hxcpp.h>

#ifndef INCLUDED_lime__internal_backend_native_NativeOpenGLRenderContext
#include <lime/_internal/backend/native/NativeOpenGLRenderContext.h>
#endif
#ifndef INCLUDED_lime_graphics_opengl_GL
#include <lime/graphics/opengl/GL.h>
#endif

namespace lime{
namespace graphics{
namespace opengl{

void GL_obj::__construct() { }

Dynamic GL_obj::__CreateEmpty() { return new GL_obj; }

void *GL_obj::_hx_vtable = 0;

Dynamic GL_obj::__Create(::hx::DynamicArray inArgs)
{
	::hx::ObjectPtr< GL_obj > _hx_result = new GL_obj();
	_hx_result->__construct();
	return _hx_result;
}

bool GL_obj::_hx_isInstanceOf(int inClassId) {
	return inClassId==(int)0x00000001 || inClassId==(int)0x6ab38d34;
}

 ::lime::_internal::backend::native::NativeOpenGLRenderContext GL_obj::context;


GL_obj::GL_obj()
{
}

bool GL_obj::__GetStatic(const ::String &inName, Dynamic &outValue, ::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 7:
		if (HX_FIELD_EQ(inName,"context") ) { outValue = ( context ); return true; }
	}
	return false;
}

bool GL_obj::__SetStatic(const ::String &inName,Dynamic &ioValue,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 7:
		if (HX_FIELD_EQ(inName,"context") ) { context=ioValue.Cast<  ::lime::_internal::backend::native::NativeOpenGLRenderContext >(); return true; }
	}
	return false;
}

#ifdef HXCPP_SCRIPTABLE
static ::hx::StorageInfo *GL_obj_sMemberStorageInfo = 0;
static ::hx::StaticInfo GL_obj_sStaticStorageInfo[] = {
	{::hx::fsObject /*  ::lime::_internal::backend::native::NativeOpenGLRenderContext */ ,(void *) &GL_obj::context,HX_("context",ef,95,77,19)},
	{ ::hx::fsUnknown, 0, null()}
};
#endif

static void GL_obj_sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(GL_obj::context,"context");
};

#ifdef HXCPP_VISIT_ALLOCS
static void GL_obj_sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(GL_obj::context,"context");
};

#endif

::hx::Class GL_obj::__mClass;

static ::String GL_obj_sStaticFields[] = {
	HX_("context",ef,95,77,19),
	::String(null())
};

void GL_obj::__register()
{
	GL_obj _hx_dummy;
	GL_obj::_hx_vtable = *(void **)&_hx_dummy;
	::hx::Static(__mClass) = new ::hx::Class_obj();
	__mClass->mName = HX_("lime.graphics.opengl.GL",1a,ed,24,f2);
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mConstructEmpty = &__CreateEmpty;
	__mClass->mConstructArgs = &__Create;
	__mClass->mGetStaticField = &GL_obj::__GetStatic;
	__mClass->mSetStaticField = &GL_obj::__SetStatic;
	__mClass->mMarkFunc = GL_obj_sMarkStatics;
	__mClass->mStatics = ::hx::Class_obj::dupFunctions(GL_obj_sStaticFields);
	__mClass->mMembers = ::hx::Class_obj::dupFunctions(0 /* sMemberFields */);
	__mClass->mCanCast = ::hx::TCanCast< GL_obj >;
#ifdef HXCPP_VISIT_ALLOCS
	__mClass->mVisitFunc = GL_obj_sVisitStatics;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mMemberStorageInfo = GL_obj_sMemberStorageInfo;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mStaticStorageInfo = GL_obj_sStaticStorageInfo;
#endif
	::hx::_hx_RegisterClass(__mClass->mName, __mClass);
}

} // end namespace lime
} // end namespace graphics
} // end namespace opengl
