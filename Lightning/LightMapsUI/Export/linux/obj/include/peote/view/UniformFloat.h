// Generated by Haxe 5.0.0-alpha.1+2f4b99d
#ifndef INCLUDED_peote_view_UniformFloat
#define INCLUDED_peote_view_UniformFloat

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_STACK_FRAME(_hx_pos_1fb9e961772ea334_11_new)
HX_DECLARE_CLASS2(peote,view,UniformFloat)

namespace peote{
namespace view{


class HXCPP_CLASS_ATTRIBUTES UniformFloat_obj : public ::hx::Object
{
	public:
		typedef ::hx::Object super;
		typedef UniformFloat_obj OBJ_;
		UniformFloat_obj();

	public:
		enum { _hx_ClassId = 0x40d77e34 };

		void __construct(::String name,Float value);
		inline void *operator new(size_t inSize, bool inContainer=true,const char *inName="peote.view.UniformFloat")
			{ return ::hx::Object::operator new(inSize,inContainer,inName); }
		inline void *operator new(size_t inSize, int extra)
			{ return ::hx::Object::operator new(inSize+extra,true,"peote.view.UniformFloat"); }

		inline static ::hx::ObjectPtr< UniformFloat_obj > __new(::String name,Float value) {
			::hx::ObjectPtr< UniformFloat_obj > __this = new UniformFloat_obj();
			__this->__construct(name,value);
			return __this;
		}

		inline static ::hx::ObjectPtr< UniformFloat_obj > __alloc(::hx::Ctx *_hx_ctx,::String name,Float value) {
			UniformFloat_obj *__this = (UniformFloat_obj*)(::hx::Ctx::alloc(_hx_ctx, sizeof(UniformFloat_obj), true, "peote.view.UniformFloat"));
			*(void **)__this = UniformFloat_obj::_hx_vtable;
{
            	HX_STACKFRAME(&_hx_pos_1fb9e961772ea334_11_new)
HXLINE(  12)		( ( ::peote::view::UniformFloat)(__this) )->name = name;
HXLINE(  13)		( ( ::peote::view::UniformFloat)(__this) )->value = value;
            	}
		
			return __this;
		}

		static void * _hx_vtable;
		static Dynamic __CreateEmpty();
		static Dynamic __Create(::hx::DynamicArray inArgs);
		//~UniformFloat_obj();

		HX_DO_RTTI_ALL;
		::hx::Val __Field(const ::String &inString, ::hx::PropertyAccess inCallProp);
		::hx::Val __SetField(const ::String &inString,const ::hx::Val &inValue, ::hx::PropertyAccess inCallProp);
		void __GetFields(Array< ::String> &outFields);
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		bool _hx_isInstanceOf(int inClassId);
		::String __ToString() const { return HX_("UniformFloat",e8,63,f5,9a); }

		Float value;
		::String name;
};

} // end namespace peote
} // end namespace view

#endif /* INCLUDED_peote_view_UniformFloat */ 
