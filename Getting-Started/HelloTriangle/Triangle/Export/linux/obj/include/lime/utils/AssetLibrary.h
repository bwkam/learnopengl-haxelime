// Generated by Haxe 5.0.0-alpha.1+2f4b99d
#ifndef INCLUDED_lime_utils_AssetLibrary
#define INCLUDED_lime_utils_AssetLibrary

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS1(haxe,IMap)
HX_DECLARE_CLASS2(haxe,ds,StringMap)
HX_DECLARE_CLASS2(haxe,io,Bytes)
HX_DECLARE_CLASS2(lime,app,Future)
HX_DECLARE_CLASS2(lime,app,Promise_lime_utils_AssetLibrary)
HX_DECLARE_CLASS2(lime,app,_Event_Void_Void)
HX_DECLARE_CLASS2(lime,graphics,Image)
HX_DECLARE_CLASS2(lime,media,AudioBuffer)
HX_DECLARE_CLASS2(lime,text,Font)
HX_DECLARE_CLASS2(lime,utils,AssetBundle)
HX_DECLARE_CLASS2(lime,utils,AssetLibrary)
HX_DECLARE_CLASS2(lime,utils,AssetManifest)

namespace lime{
namespace utils{


class HXCPP_CLASS_ATTRIBUTES AssetLibrary_obj : public ::hx::Object
{
	public:
		typedef ::hx::Object super;
		typedef AssetLibrary_obj OBJ_;
		AssetLibrary_obj();

	public:
		enum { _hx_ClassId = 0x25654723 };

		void __construct();
		inline void *operator new(size_t inSize, bool inContainer=true,const char *inName="lime.utils.AssetLibrary")
			{ return ::hx::Object::operator new(inSize,inContainer,inName); }
		inline void *operator new(size_t inSize, int extra)
			{ return ::hx::Object::operator new(inSize+extra,true,"lime.utils.AssetLibrary"); }
		static ::hx::ObjectPtr< AssetLibrary_obj > __new();
		static ::hx::ObjectPtr< AssetLibrary_obj > __alloc(::hx::Ctx *_hx_ctx);
		static void * _hx_vtable;
		static Dynamic __CreateEmpty();
		static Dynamic __Create(::hx::DynamicArray inArgs);
		//~AssetLibrary_obj();

		HX_DO_RTTI_ALL;
		::hx::Val __Field(const ::String &inString, ::hx::PropertyAccess inCallProp);
		static bool __GetStatic(const ::String &inString, Dynamic &outValue, ::hx::PropertyAccess inCallProp);
		::hx::Val __SetField(const ::String &inString,const ::hx::Val &inValue, ::hx::PropertyAccess inCallProp);
		void __GetFields(Array< ::String> &outFields);
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		bool _hx_isInstanceOf(int inClassId);
		::String __ToString() const { return HX_("AssetLibrary",0b,4f,d4,27); }

		static  ::lime::utils::AssetLibrary fromBytes( ::haxe::io::Bytes bytes,::String rootPath);
		static ::Dynamic fromBytes_dyn();

		static  ::lime::utils::AssetLibrary fromFile(::String path,::String rootPath);
		static ::Dynamic fromFile_dyn();

		static  ::lime::utils::AssetLibrary fromBundle( ::lime::utils::AssetBundle bundle);
		static ::Dynamic fromBundle_dyn();

		static  ::lime::utils::AssetLibrary fromManifest( ::lime::utils::AssetManifest manifest);
		static ::Dynamic fromManifest_dyn();

		static  ::lime::app::Future loadFromBytes( ::haxe::io::Bytes bytes,::String rootPath);
		static ::Dynamic loadFromBytes_dyn();

		static  ::lime::app::Future loadFromFile(::String path,::String rootPath);
		static ::Dynamic loadFromFile_dyn();

		static  ::lime::app::Future loadFromManifest( ::lime::utils::AssetManifest manifest);
		static ::Dynamic loadFromManifest_dyn();

		 ::lime::app::_Event_Void_Void onChange;
		int assetsLoaded;
		int assetsTotal;
		int bytesLoaded;
		 ::haxe::ds::StringMap bytesLoadedCache;
		int bytesTotal;
		 ::haxe::ds::StringMap cachedAudioBuffers;
		 ::haxe::ds::StringMap cachedBytes;
		 ::haxe::ds::StringMap cachedFonts;
		 ::haxe::ds::StringMap cachedImages;
		 ::haxe::ds::StringMap cachedText;
		 ::haxe::ds::StringMap classTypes;
		bool loaded;
		 ::haxe::ds::StringMap pathGroups;
		 ::haxe::ds::StringMap paths;
		 ::haxe::ds::StringMap preload;
		 ::lime::app::Promise_lime_utils_AssetLibrary promise;
		 ::haxe::ds::StringMap sizes;
		 ::haxe::ds::StringMap types;
		bool exists(::String id,::String type);
		::Dynamic exists_dyn();

		 ::Dynamic getAsset(::String id,::String type);
		::Dynamic getAsset_dyn();

		 ::lime::media::AudioBuffer getAudioBuffer(::String id);
		::Dynamic getAudioBuffer_dyn();

		 ::haxe::io::Bytes getBytes(::String id);
		::Dynamic getBytes_dyn();

		 ::lime::text::Font getFont(::String id);
		::Dynamic getFont_dyn();

		 ::lime::graphics::Image getImage(::String id);
		::Dynamic getImage_dyn();

		::String getPath(::String id);
		::Dynamic getPath_dyn();

		::String getText(::String id);
		::Dynamic getText_dyn();

		bool isLocal(::String id,::String type);
		::Dynamic isLocal_dyn();

		::Array< ::String > list(::String type);
		::Dynamic list_dyn();

		 ::lime::app::Future loadAsset(::String id,::String type);
		::Dynamic loadAsset_dyn();

		 ::lime::app::Future load();
		::Dynamic load_dyn();

		 ::lime::app::Future loadAudioBuffer(::String id);
		::Dynamic loadAudioBuffer_dyn();

		 ::lime::app::Future loadBytes(::String id);
		::Dynamic loadBytes_dyn();

		 ::lime::app::Future loadFont(::String id);
		::Dynamic loadFont_dyn();

		 ::lime::app::Future loadImage(::String id);
		::Dynamic loadImage_dyn();

		 ::lime::app::Future loadText(::String id);
		::Dynamic loadText_dyn();

		void unload();
		::Dynamic unload_dyn();

		void _hx___assetLoaded(::String id);
		::Dynamic _hx___assetLoaded_dyn();

		::String _hx___cacheBreak(::String path);
		::Dynamic _hx___cacheBreak_dyn();

		void _hx___fromBundle( ::lime::utils::AssetBundle bundle, ::lime::utils::AssetManifest manifest);
		::Dynamic _hx___fromBundle_dyn();

		void _hx___fromManifest( ::lime::utils::AssetManifest manifest);
		::Dynamic _hx___fromManifest_dyn();

		::String _hx___resolvePath(::String path);
		::Dynamic _hx___resolvePath_dyn();

		void loadAudioBuffer_onComplete(::String id, ::lime::media::AudioBuffer audioBuffer);
		::Dynamic loadAudioBuffer_onComplete_dyn();

		void loadAudioBuffer_onError(::String id, ::Dynamic message);
		::Dynamic loadAudioBuffer_onError_dyn();

		void loadBytes_onComplete(::String id, ::haxe::io::Bytes bytes);
		::Dynamic loadBytes_onComplete_dyn();

		void loadFont_onComplete(::String id, ::lime::text::Font font);
		::Dynamic loadFont_onComplete_dyn();

		void loadImage_onComplete(::String id, ::lime::graphics::Image image);
		::Dynamic loadImage_onComplete_dyn();

		void loadText_onComplete(::String id,::String text);
		::Dynamic loadText_onComplete_dyn();

		void load_onError(::String id, ::Dynamic message);
		::Dynamic load_onError_dyn();

		void load_onProgress(::String id,int bytesLoaded,int bytesTotal);
		::Dynamic load_onProgress_dyn();

};

} // end namespace lime
} // end namespace utils

#endif /* INCLUDED_lime_utils_AssetLibrary */ 
