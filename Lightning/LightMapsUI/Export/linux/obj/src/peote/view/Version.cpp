// Generated by Haxe 5.0.0-alpha.1+2f4b99d
#include <hxcpp.h>

#ifndef INCLUDED_peote_view_Version
#include <peote/view/Version.h>
#endif

HX_LOCAL_STACK_FRAME(_hx_pos_22225c653776fbbb_205_boot,"peote.view.Version","boot",0xa9ad00ae,"peote.view.Version.boot","peote/view/PeoteGL.hx",205,0x90807f54)
namespace peote{
namespace view{

void Version_obj::__construct() { }

Dynamic Version_obj::__CreateEmpty() { return new Version_obj; }

void *Version_obj::_hx_vtable = 0;

Dynamic Version_obj::__Create(::hx::DynamicArray inArgs)
{
	::hx::ObjectPtr< Version_obj > _hx_result = new Version_obj();
	_hx_result->__construct();
	return _hx_result;
}

bool Version_obj::_hx_isInstanceOf(int inClassId) {
	return inClassId==(int)0x00000001 || inClassId==(int)0x0d08c5bc;
}

bool Version_obj::isES3;


Version_obj::Version_obj()
{
}

bool Version_obj::__GetStatic(const ::String &inName, Dynamic &outValue, ::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"isES3") ) { outValue = ( isES3 ); return true; }
	}
	return false;
}

bool Version_obj::__SetStatic(const ::String &inName,Dynamic &ioValue,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"isES3") ) { isES3=ioValue.Cast< bool >(); return true; }
	}
	return false;
}

#ifdef HXCPP_SCRIPTABLE
static ::hx::StorageInfo *Version_obj_sMemberStorageInfo = 0;
static ::hx::StaticInfo Version_obj_sStaticStorageInfo[] = {
	{::hx::fsBool,(void *) &Version_obj::isES3,HX_("isES3",5b,16,4b,c1)},
	{ ::hx::fsUnknown, 0, null()}
};
#endif

static void Version_obj_sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Version_obj::isES3,"isES3");
};

#ifdef HXCPP_VISIT_ALLOCS
static void Version_obj_sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Version_obj::isES3,"isES3");
};

#endif

::hx::Class Version_obj::__mClass;

static ::String Version_obj_sStaticFields[] = {
	HX_("isES3",5b,16,4b,c1),
	::String(null())
};

void Version_obj::__register()
{
	Version_obj _hx_dummy;
	Version_obj::_hx_vtable = *(void **)&_hx_dummy;
	::hx::Static(__mClass) = new ::hx::Class_obj();
	__mClass->mName = HX_("peote.view.Version",72,35,2c,93);
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mConstructEmpty = &__CreateEmpty;
	__mClass->mConstructArgs = &__Create;
	__mClass->mGetStaticField = &Version_obj::__GetStatic;
	__mClass->mSetStaticField = &Version_obj::__SetStatic;
	__mClass->mMarkFunc = Version_obj_sMarkStatics;
	__mClass->mStatics = ::hx::Class_obj::dupFunctions(Version_obj_sStaticFields);
	__mClass->mMembers = ::hx::Class_obj::dupFunctions(0 /* sMemberFields */);
	__mClass->mCanCast = ::hx::TCanCast< Version_obj >;
#ifdef HXCPP_VISIT_ALLOCS
	__mClass->mVisitFunc = Version_obj_sVisitStatics;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mMemberStorageInfo = Version_obj_sMemberStorageInfo;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mStaticStorageInfo = Version_obj_sStaticStorageInfo;
#endif
	::hx::_hx_RegisterClass(__mClass->mName, __mClass);
}

void Version_obj::__boot()
{
{
            	HX_STACKFRAME(&_hx_pos_22225c653776fbbb_205_boot)
HXDLIN( 205)		isES3 = false;
            	}
}

} // end namespace peote
} // end namespace view
