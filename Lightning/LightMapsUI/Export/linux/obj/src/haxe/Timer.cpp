// Generated by Haxe 5.0.0-alpha.1+2f4b99d
#include <hxcpp.h>

#ifndef INCLUDED_haxe_Timer
#include <haxe/Timer.h>
#endif
#ifndef INCLUDED_lime_system_System
#include <lime/system/System.h>
#endif

HX_DEFINE_STACK_FRAME(_hx_pos_102f69689d37b2bb_230_new,"haxe.Timer","new",0x4136b0cf,"haxe.Timer.new","haxe/Timer.hx",230,0x1a690682)
HX_LOCAL_STACK_FRAME(_hx_pos_102f69689d37b2bb_263___default_run,"haxe.Timer","__default_run",0xdc2b9b9c,"haxe.Timer.__default_run","haxe/Timer.hx",263,0x1a690682)
HX_LOCAL_STACK_FRAME(_hx_pos_102f69689d37b2bb_273_stop,"haxe.Timer","stop",0xd1fd70b3,"haxe.Timer.stop","haxe/Timer.hx",273,0x1a690682)
HX_LOCAL_STACK_FRAME(_hx_pos_102f69689d37b2bb_252_getMS,"haxe.Timer","getMS",0xf90fafab,"haxe.Timer.getMS","haxe/Timer.hx",252,0x1a690682)
HX_LOCAL_STACK_FRAME(_hx_pos_102f69689d37b2bb_223_boot,"haxe.Timer","boot",0xc6bd04e3,"haxe.Timer.boot","haxe/Timer.hx",223,0x1a690682)
namespace haxe{

void Timer_obj::__construct(Float time){
            	HX_STACKFRAME(&_hx_pos_102f69689d37b2bb_230_new)
HXLINE( 231)		this->mTime = time;
HXLINE( 232)		::haxe::Timer_obj::sRunningTimers->push(::hx::ObjectPtr<OBJ_>(this));
HXLINE( 233)		Float _hx_tmp = ::haxe::Timer_obj::getMS();
HXDLIN( 233)		this->mFireAt = (_hx_tmp + this->mTime);
HXLINE( 234)		this->mRunning = true;
            	}

Dynamic Timer_obj::__CreateEmpty() { return new Timer_obj; }

void *Timer_obj::_hx_vtable = 0;

Dynamic Timer_obj::__Create(::hx::DynamicArray inArgs)
{
	::hx::ObjectPtr< Timer_obj > _hx_result = new Timer_obj();
	_hx_result->__construct(inArgs[0]);
	return _hx_result;
}

bool Timer_obj::_hx_isInstanceOf(int inClassId) {
	return inClassId==(int)0x00000001 || inClassId==(int)0x04eaa0bb;
}

HX_BEGIN_DEFAULT_FUNC(__default_run,Timer_obj)
void _hx_run(){
            	HX_STACKFRAME(&_hx_pos_102f69689d37b2bb_263___default_run)
            	}
HX_END_LOCAL_FUNC0((void))
HX_END_DEFAULT_FUNC

void Timer_obj::stop(){
            	HX_STACKFRAME(&_hx_pos_102f69689d37b2bb_273_stop)
HXDLIN( 273)		if (this->mRunning) {
HXLINE( 275)			this->mRunning = false;
HXLINE( 277)			{
HXLINE( 277)				int _g = 0;
HXDLIN( 277)				int _g1 = ::haxe::Timer_obj::sRunningTimers->length;
HXDLIN( 277)				while((_g < _g1)){
HXLINE( 277)					_g = (_g + 1);
HXDLIN( 277)					int i = (_g - 1);
HXLINE( 279)					if (::hx::IsInstanceEq( ::haxe::Timer_obj::sRunningTimers->__get(i).StaticCast<  ::haxe::Timer >(),::hx::ObjectPtr<OBJ_>(this) )) {
HXLINE( 281)						::haxe::Timer_obj::sRunningTimers[i] = null();
HXLINE( 282)						goto _hx_goto_2;
            					}
            				}
            				_hx_goto_2:;
            			}
            		}
            	}


HX_DEFINE_DYNAMIC_FUNC0(Timer_obj,stop,(void))

::Array< ::Dynamic> Timer_obj::sRunningTimers;

Float Timer_obj::getMS(){
            	HX_STACKFRAME(&_hx_pos_102f69689d37b2bb_252_getMS)
HXDLIN( 252)		return ( (Float)(::lime::_hx_system::System_obj::getTimer()) );
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Timer_obj,getMS,return )


void Timer_obj::__alloc_dynamic_functions(::hx::Ctx *_hx_ctx,Timer_obj *_hx_obj) {
	if (!_hx_obj->run.mPtr) _hx_obj->run = new __default_run(_hx_obj);
}
Timer_obj::Timer_obj()
{
	run = new __default_run(this);
}

void Timer_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Timer);
	HX_MARK_MEMBER_NAME(mTime,"mTime");
	HX_MARK_MEMBER_NAME(mFireAt,"mFireAt");
	HX_MARK_MEMBER_NAME(mRunning,"mRunning");
	HX_MARK_MEMBER_NAME(run,"run");
	HX_MARK_END_CLASS();
}

void Timer_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(mTime,"mTime");
	HX_VISIT_MEMBER_NAME(mFireAt,"mFireAt");
	HX_VISIT_MEMBER_NAME(mRunning,"mRunning");
	HX_VISIT_MEMBER_NAME(run,"run");
}

::hx::Val Timer_obj::__Field(const ::String &inName,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"run") ) { return ::hx::Val( run ); }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"stop") ) { return ::hx::Val( stop_dyn() ); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"mTime") ) { return ::hx::Val( mTime ); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"mFireAt") ) { return ::hx::Val( mFireAt ); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"mRunning") ) { return ::hx::Val( mRunning ); }
	}
	return super::__Field(inName,inCallProp);
}

bool Timer_obj::__GetStatic(const ::String &inName, Dynamic &outValue, ::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"getMS") ) { outValue = getMS_dyn(); return true; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"sRunningTimers") ) { outValue = ( sRunningTimers ); return true; }
	}
	return false;
}

::hx::Val Timer_obj::__SetField(const ::String &inName,const ::hx::Val &inValue,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"run") ) { run=inValue.Cast<  ::Dynamic >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"mTime") ) { mTime=inValue.Cast< Float >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"mFireAt") ) { mFireAt=inValue.Cast< Float >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"mRunning") ) { mRunning=inValue.Cast< bool >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

bool Timer_obj::__SetStatic(const ::String &inName,Dynamic &ioValue,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 14:
		if (HX_FIELD_EQ(inName,"sRunningTimers") ) { sRunningTimers=ioValue.Cast< ::Array< ::Dynamic> >(); return true; }
	}
	return false;
}

void Timer_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_("mTime",1a,33,83,fa));
	outFields->push(HX_("mFireAt",96,ea,58,72));
	outFields->push(HX_("mRunning",12,2d,35,13));
	super::__GetFields(outFields);
};

#ifdef HXCPP_SCRIPTABLE
static ::hx::StorageInfo Timer_obj_sMemberStorageInfo[] = {
	{::hx::fsFloat,(int)offsetof(Timer_obj,mTime),HX_("mTime",1a,33,83,fa)},
	{::hx::fsFloat,(int)offsetof(Timer_obj,mFireAt),HX_("mFireAt",96,ea,58,72)},
	{::hx::fsBool,(int)offsetof(Timer_obj,mRunning),HX_("mRunning",12,2d,35,13)},
	{::hx::fsObject /*  ::Dynamic */ ,(int)offsetof(Timer_obj,run),HX_("run",4b,e7,56,00)},
	{ ::hx::fsUnknown, 0, null()}
};
static ::hx::StaticInfo Timer_obj_sStaticStorageInfo[] = {
	{::hx::fsObject /* ::Array< ::Dynamic> */ ,(void *) &Timer_obj::sRunningTimers,HX_("sRunningTimers",fa,bb,cd,fe)},
	{ ::hx::fsUnknown, 0, null()}
};
#endif

static ::String Timer_obj_sMemberFields[] = {
	HX_("mTime",1a,33,83,fa),
	HX_("mFireAt",96,ea,58,72),
	HX_("mRunning",12,2d,35,13),
	HX_("run",4b,e7,56,00),
	HX_("stop",02,f0,5b,4c),
	::String(null()) };

static void Timer_obj_sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Timer_obj::sRunningTimers,"sRunningTimers");
};

#ifdef HXCPP_VISIT_ALLOCS
static void Timer_obj_sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Timer_obj::sRunningTimers,"sRunningTimers");
};

#endif

::hx::Class Timer_obj::__mClass;

static ::String Timer_obj_sStaticFields[] = {
	HX_("sRunningTimers",fa,bb,cd,fe),
	HX_("getMS",7c,95,60,91),
	::String(null())
};

void Timer_obj::__register()
{
	Timer_obj _hx_dummy;
	Timer_obj::_hx_vtable = *(void **)&_hx_dummy;
	::hx::Static(__mClass) = new ::hx::Class_obj();
	__mClass->mName = HX_("haxe.Timer",5d,9d,24,4b);
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mConstructEmpty = &__CreateEmpty;
	__mClass->mConstructArgs = &__Create;
	__mClass->mGetStaticField = &Timer_obj::__GetStatic;
	__mClass->mSetStaticField = &Timer_obj::__SetStatic;
	__mClass->mMarkFunc = Timer_obj_sMarkStatics;
	__mClass->mStatics = ::hx::Class_obj::dupFunctions(Timer_obj_sStaticFields);
	__mClass->mMembers = ::hx::Class_obj::dupFunctions(Timer_obj_sMemberFields);
	__mClass->mCanCast = ::hx::TCanCast< Timer_obj >;
#ifdef HXCPP_VISIT_ALLOCS
	__mClass->mVisitFunc = Timer_obj_sVisitStatics;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mMemberStorageInfo = Timer_obj_sMemberStorageInfo;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mStaticStorageInfo = Timer_obj_sStaticStorageInfo;
#endif
	::hx::_hx_RegisterClass(__mClass->mName, __mClass);
}

void Timer_obj::__boot()
{
{
            	HX_STACKFRAME(&_hx_pos_102f69689d37b2bb_223_boot)
HXDLIN( 223)		sRunningTimers = ::Array_obj< ::Dynamic>::__new(0);
            	}
}

} // end namespace haxe
