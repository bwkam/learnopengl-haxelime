// Generated by Haxe 5.0.0-alpha.1+2f4b99d
#ifndef INCLUDED_sys_thread_EventLoop
#define INCLUDED_sys_thread_EventLoop

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(sys,thread,EventLoop)
HX_DECLARE_CLASS2(sys,thread,Lock)
HX_DECLARE_CLASS2(sys,thread,Mutex)
HX_DECLARE_CLASS2(sys,thread,NextEventTime)
HX_DECLARE_CLASS3(sys,thread,_EventLoop,RegularEvent)

namespace sys{
namespace thread{


class HXCPP_CLASS_ATTRIBUTES EventLoop_obj : public ::hx::Object
{
	public:
		typedef ::hx::Object super;
		typedef EventLoop_obj OBJ_;
		EventLoop_obj();

	public:
		enum { _hx_ClassId = 0x6a581147 };

		void __construct();
		inline void *operator new(size_t inSize, bool inContainer=true,const char *inName="sys.thread.EventLoop")
			{ return ::hx::Object::operator new(inSize,inContainer,inName); }
		inline void *operator new(size_t inSize, int extra)
			{ return ::hx::Object::operator new(inSize+extra,true,"sys.thread.EventLoop"); }
		static ::hx::ObjectPtr< EventLoop_obj > __new();
		static ::hx::ObjectPtr< EventLoop_obj > __alloc(::hx::Ctx *_hx_ctx);
		static void * _hx_vtable;
		static Dynamic __CreateEmpty();
		static Dynamic __Create(::hx::DynamicArray inArgs);
		//~EventLoop_obj();

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
		::String __ToString() const { return HX_("EventLoop",7e,8f,97,98); }

		static bool CREATED;
		 ::sys::thread::Mutex mutex;
		::Array< ::Dynamic> oneTimeEvents;
		int oneTimeEventsIdx;
		 ::sys::thread::Lock waitLock;
		int promisedEventsCount;
		 ::sys::thread::_EventLoop::RegularEvent regularEvents;
		bool isMainThread;
		 ::sys::thread::NextEventTime progress();
		::Dynamic progress_dyn();

		void loop();
		::Dynamic loop_dyn();

};

} // end namespace sys
} // end namespace thread

#endif /* INCLUDED_sys_thread_EventLoop */ 
