// Generated by Haxe 5.0.0-alpha.1+2f4b99d
#ifndef INCLUDED_lime_text__Glyph_Glyph_Impl_
#define INCLUDED_lime_text__Glyph_Glyph_Impl_

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(lime,text,_Glyph,Glyph_Impl_)

namespace lime{
namespace text{
namespace _Glyph{


class HXCPP_CLASS_ATTRIBUTES Glyph_Impl__obj : public ::hx::Object
{
	public:
		typedef ::hx::Object super;
		typedef Glyph_Impl__obj OBJ_;
		Glyph_Impl__obj();

	public:
		enum { _hx_ClassId = 0x0e0d6eed };

		void __construct();
		inline void *operator new(size_t inSize, bool inContainer=false,const char *inName="lime.text._Glyph.Glyph_Impl_")
			{ return ::hx::Object::operator new(inSize,inContainer,inName); }
		inline void *operator new(size_t inSize, int extra)
			{ return ::hx::Object::operator new(inSize+extra,false,"lime.text._Glyph.Glyph_Impl_"); }

		inline static ::hx::ObjectPtr< Glyph_Impl__obj > __new() {
			::hx::ObjectPtr< Glyph_Impl__obj > __this = new Glyph_Impl__obj();
			__this->__construct();
			return __this;
		}

		inline static ::hx::ObjectPtr< Glyph_Impl__obj > __alloc(::hx::Ctx *_hx_ctx) {
			Glyph_Impl__obj *__this = (Glyph_Impl__obj*)(::hx::Ctx::alloc(_hx_ctx, sizeof(Glyph_Impl__obj), false, "lime.text._Glyph.Glyph_Impl_"));
			*(void **)__this = Glyph_Impl__obj::_hx_vtable;
			return __this;
		}

		static void * _hx_vtable;
		static Dynamic __CreateEmpty();
		static Dynamic __Create(::hx::DynamicArray inArgs);
		//~Glyph_Impl__obj();

		HX_DO_RTTI_ALL;
		static bool __GetStatic(const ::String &inString, Dynamic &outValue, ::hx::PropertyAccess inCallProp);
		static void __register();
		bool _hx_isInstanceOf(int inClassId);
		::String __ToString() const { return HX_("Glyph_Impl_",2c,5b,88,c8); }

		static int _new(int i);
		static ::Dynamic _new_dyn();

};

} // end namespace lime
} // end namespace text
} // end namespace _Glyph

#endif /* INCLUDED_lime_text__Glyph_Glyph_Impl_ */ 
