// Generated by Haxe 5.0.0-alpha.1+2f4b99d
#ifndef INCLUDED_haxe_Timer
#define INCLUDED_haxe_Timer

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_STACK_FRAME(_hx_pos_102f69689d37b2bb_230_new)
HX_DECLARE_CLASS1(haxe,Timer)

namespace haxe{


class HXCPP_CLASS_ATTRIBUTES Timer_obj : public ::hx::Object
{
	public:
		typedef ::hx::Object super;
		typedef Timer_obj OBJ_;
		Timer_obj();

	public:
		enum { _hx_ClassId = 0x04eaa0bb };

		void __construct(Float time);
		inline void *operator new(size_t inSize, bool inContainer=true,const char *inName="haxe.Timer")
			{ return ::hx::Object::operator new(inSize,inContainer,inName); }
		inline void *operator new(size_t inSize, int extra)
			{ return ::hx::Object::operator new(inSize+extra,true,"haxe.Timer"); }

		inline static ::hx::ObjectPtr< Timer_obj > __new(Float time) {
			::hx::ObjectPtr< Timer_obj > __this = new Timer_obj();
			__this->__construct(time);
			return __this;
		}

		inline static ::hx::ObjectPtr< Timer_obj > __alloc(::hx::Ctx *_hx_ctx,Float time) {
			Timer_obj *__this = (Timer_obj*)(::hx::Ctx::alloc(_hx_ctx, sizeof(Timer_obj), true, "haxe.Timer"));
			*(void **)__this = Timer_obj::_hx_vtable;
			haxe::Timer_obj::__alloc_dynamic_functions(_hx_ctx,__this);
{
            	HX_STACKFRAME(&_hx_pos_102f69689d37b2bb_230_new)
HXLINE( 231)		( ( ::haxe::Timer)(__this) )->mTime = time;
HXLINE( 232)		::haxe::Timer_obj::sRunningTimers->push(__this);
HXLINE( 233)		Float _hx_tmp = ::haxe::Timer_obj::getMS();
HXDLIN( 233)		( ( ::haxe::Timer)(__this) )->mFireAt = (_hx_tmp + ( ( ::haxe::Timer)(__this) )->mTime);
HXLINE( 234)		( ( ::haxe::Timer)(__this) )->mRunning = true;
            	}
		
			return __this;
		}

		static void * _hx_vtable;
		static Dynamic __CreateEmpty();
		static Dynamic __Create(::hx::DynamicArray inArgs);
		static void __alloc_dynamic_functions(::hx::Ctx *_hx_alloc,Timer_obj *_hx_obj);
		//~Timer_obj();

		HX_DO_RTTI_ALL;
		::hx::Val __Field(const ::String &inString, ::hx::PropertyAccess inCallProp);
		static bool __GetStatic(const ::String &inString, Dynamic &outValue, ::hx::PropertyAccess inCallProp);
		::hx::Val __SetField(const ::String &inString,const ::hx::Val &inValue, ::hx::PropertyAccess inCallProp);
		static bool __SetStatic(const ::String &inString, Dynamic &ioValue, ::hx::PropertyAccess inCallProp);
		void __GetFields(Array< ::String> &outFields);
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		bool _hx_isInstanceOf(int inClassId);
		::String __ToString() const { return HX_("Timer",a5,2f,63,a3); }

		static void __boot();
		static ::Array< ::Dynamic> sRunningTimers;
		static  ::haxe::Timer delay( ::Dynamic f,int time);
		static ::Dynamic delay_dyn();

		static Float getMS();
		static ::Dynamic getMS_dyn();

		static  ::Dynamic measure( ::Dynamic f, ::Dynamic pos);
		static ::Dynamic measure_dyn();

		static Float stamp();
		static ::Dynamic stamp_dyn();

		Float mTime;
		Float mFireAt;
		bool mRunning;
		::Dynamic run;
		inline ::Dynamic &run_dyn() {return run; }

		void stop();
		::Dynamic stop_dyn();

		void _hx___check(Float inTime);
		::Dynamic _hx___check_dyn();

};

} // end namespace haxe

#endif /* INCLUDED_haxe_Timer */ 
