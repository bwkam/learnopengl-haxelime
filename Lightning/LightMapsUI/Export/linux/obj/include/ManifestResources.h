// Generated by Haxe 5.0.0-alpha.1+2f4b99d
#ifndef INCLUDED_ManifestResources
#define INCLUDED_ManifestResources

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS0(ManifestResources)
HX_DECLARE_CLASS2(lime,utils,AssetLibrary)



class HXCPP_CLASS_ATTRIBUTES ManifestResources_obj : public ::hx::Object
{
	public:
		typedef ::hx::Object super;
		typedef ManifestResources_obj OBJ_;
		ManifestResources_obj();

	public:
		enum { _hx_ClassId = 0x7f5bd976 };

		void __construct();
		inline void *operator new(size_t inSize, bool inContainer=false,const char *inName="ManifestResources")
			{ return ::hx::Object::operator new(inSize,inContainer,inName); }
		inline void *operator new(size_t inSize, int extra)
			{ return ::hx::Object::operator new(inSize+extra,false,"ManifestResources"); }

		inline static ::hx::ObjectPtr< ManifestResources_obj > __new() {
			::hx::ObjectPtr< ManifestResources_obj > __this = new ManifestResources_obj();
			__this->__construct();
			return __this;
		}

		inline static ::hx::ObjectPtr< ManifestResources_obj > __alloc(::hx::Ctx *_hx_ctx) {
			ManifestResources_obj *__this = (ManifestResources_obj*)(::hx::Ctx::alloc(_hx_ctx, sizeof(ManifestResources_obj), false, "ManifestResources"));
			*(void **)__this = ManifestResources_obj::_hx_vtable;
			return __this;
		}

		static void * _hx_vtable;
		static Dynamic __CreateEmpty();
		static Dynamic __Create(::hx::DynamicArray inArgs);
		//~ManifestResources_obj();

		HX_DO_RTTI_ALL;
		static bool __GetStatic(const ::String &inString, Dynamic &outValue, ::hx::PropertyAccess inCallProp);
		static bool __SetStatic(const ::String &inString, Dynamic &ioValue, ::hx::PropertyAccess inCallProp);
		static void __register();
		bool _hx_isInstanceOf(int inClassId);
		::String __ToString() const { return HX_("ManifestResources",16,0e,30,56); }

		static ::Array< ::Dynamic> preloadLibraries;
		static ::Array< ::String > preloadLibraryNames;
		static ::String rootPath;
		static void init( ::Dynamic config);
		static ::Dynamic init_dyn();

};


#endif /* INCLUDED_ManifestResources */ 
