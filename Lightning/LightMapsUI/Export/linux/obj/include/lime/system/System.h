// Generated by Haxe 5.0.0-alpha.1+2f4b99d
#ifndef INCLUDED_lime_system_System
#define INCLUDED_lime_system_System

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS1(haxe,IMap)
HX_DECLARE_CLASS2(haxe,ds,StringMap)
HX_DECLARE_CLASS2(lime,_hx_system,System)

namespace lime{
namespace _hx_system{


class HXCPP_CLASS_ATTRIBUTES System_obj : public ::hx::Object
{
	public:
		typedef ::hx::Object super;
		typedef System_obj OBJ_;
		System_obj();

	public:
		enum { _hx_ClassId = 0x0470bdb7 };

		void __construct();
		inline void *operator new(size_t inSize, bool inContainer=false,const char *inName="lime.system.System")
			{ return ::hx::Object::operator new(inSize,inContainer,inName); }
		inline void *operator new(size_t inSize, int extra)
			{ return ::hx::Object::operator new(inSize+extra,false,"lime.system.System"); }

		inline static ::hx::ObjectPtr< System_obj > __new() {
			::hx::ObjectPtr< System_obj > __this = new System_obj();
			__this->__construct();
			return __this;
		}

		inline static ::hx::ObjectPtr< System_obj > __alloc(::hx::Ctx *_hx_ctx) {
			System_obj *__this = (System_obj*)(::hx::Ctx::alloc(_hx_ctx, sizeof(System_obj), false, "lime.system.System"));
			*(void **)__this = System_obj::_hx_vtable;
			return __this;
		}

		static void * _hx_vtable;
		static Dynamic __CreateEmpty();
		static Dynamic __Create(::hx::DynamicArray inArgs);
		//~System_obj();

		HX_DO_RTTI_ALL;
		static bool __GetStatic(const ::String &inString, Dynamic &outValue, ::hx::PropertyAccess inCallProp);
		static bool __SetStatic(const ::String &inString, Dynamic &ioValue, ::hx::PropertyAccess inCallProp);
		static void __register();
		bool _hx_isInstanceOf(int inClassId);
		::String __ToString() const { return HX_("System",0f,0b,77,27); }

		static  ::haxe::ds::StringMap _hx___applicationEntryPoint;
		static void exit(int code);
		static ::Dynamic exit_dyn();

		static int getTimer();
		static ::Dynamic getTimer_dyn();

		static void _hx___parseArguments( ::Dynamic attributes);
		static ::Dynamic _hx___parseArguments_dyn();

		static void _hx___registerEntryPoint(::String projectName, ::Dynamic entryPoint);
		static ::Dynamic _hx___registerEntryPoint_dyn();

};

} // end namespace lime
} // end namespace system

#endif /* INCLUDED_lime_system_System */ 
