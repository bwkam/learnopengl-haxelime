// Generated by Haxe 5.0.0-alpha.1+2f4b99d
#ifndef INCLUDED_peote_view_Precision
#define INCLUDED_peote_view_Precision

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(peote,view,Precision)

namespace peote{
namespace view{


class HXCPP_CLASS_ATTRIBUTES Precision_obj : public ::hx::Object
{
	public:
		typedef ::hx::Object super;
		typedef Precision_obj OBJ_;
		Precision_obj();

	public:
		enum { _hx_ClassId = 0x50027352 };

		void __construct();
		inline void *operator new(size_t inSize, bool inContainer=false,const char *inName="peote.view.Precision")
			{ return ::hx::Object::operator new(inSize,inContainer,inName); }
		inline void *operator new(size_t inSize, int extra)
			{ return ::hx::Object::operator new(inSize+extra,false,"peote.view.Precision"); }

		inline static ::hx::ObjectPtr< Precision_obj > __new() {
			::hx::ObjectPtr< Precision_obj > __this = new Precision_obj();
			__this->__construct();
			return __this;
		}

		inline static ::hx::ObjectPtr< Precision_obj > __alloc(::hx::Ctx *_hx_ctx) {
			Precision_obj *__this = (Precision_obj*)(::hx::Ctx::alloc(_hx_ctx, sizeof(Precision_obj), false, "peote.view.Precision"));
			*(void **)__this = Precision_obj::_hx_vtable;
			return __this;
		}

		static void * _hx_vtable;
		static Dynamic __CreateEmpty();
		static Dynamic __Create(::hx::DynamicArray inArgs);
		//~Precision_obj();

		HX_DO_RTTI_ALL;
		static bool __GetStatic(const ::String &inString, Dynamic &outValue, ::hx::PropertyAccess inCallProp);
		static bool __SetStatic(const ::String &inString, Dynamic &ioValue, ::hx::PropertyAccess inCallProp);
		static void __register();
		bool _hx_isInstanceOf(int inClassId);
		::String __ToString() const { return HX_("Precision",1e,b5,9a,22); }

		static void __boot();
		static  ::Dynamic VertexFloat;
		static  ::Dynamic VertexInt;
		static  ::Dynamic VertexSampler;
		static  ::Dynamic FragmentFloat;
		static  ::Dynamic FragmentInt;
		static  ::Dynamic FragmentSampler;
};

} // end namespace peote
} // end namespace view

#endif /* INCLUDED_peote_view_Precision */ 
