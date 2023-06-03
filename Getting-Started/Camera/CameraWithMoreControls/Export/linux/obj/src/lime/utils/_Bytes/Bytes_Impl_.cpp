// Generated by Haxe 5.0.0-alpha.1+2f4b99d
#include <hxcpp.h>

#ifndef INCLUDED_haxe_io_Bytes
#include <haxe/io/Bytes.h>
#endif
#ifndef INCLUDED_haxe_io_Encoding
#include <haxe/io/Encoding.h>
#endif
#ifndef INCLUDED_lime__internal_backend_native_NativeCFFI
#include <lime/_internal/backend/native/NativeCFFI.h>
#endif
#ifndef INCLUDED_lime__internal_format_Deflate
#include <lime/_internal/format/Deflate.h>
#endif
#ifndef INCLUDED_lime__internal_format_GZip
#include <lime/_internal/format/GZip.h>
#endif
#ifndef INCLUDED_lime__internal_format_LZMA
#include <lime/_internal/format/LZMA.h>
#endif
#ifndef INCLUDED_lime__internal_format_Zlib
#include <lime/_internal/format/Zlib.h>
#endif
#ifndef INCLUDED_lime_app_Future
#include <lime/app/Future.h>
#endif
#ifndef INCLUDED_lime_net__HTTPRequest_AbstractHTTPRequest
#include <lime/net/_HTTPRequest/AbstractHTTPRequest.h>
#endif
#ifndef INCLUDED_lime_net__HTTPRequest_Bytes
#include <lime/net/_HTTPRequest_Bytes.h>
#endif
#ifndef INCLUDED_lime_net__HTTPRequest_lime_utils_Bytes
#include <lime/net/_HTTPRequest_lime_utils_Bytes.h>
#endif
#ifndef INCLUDED_lime_net__IHTTPRequest
#include <lime/net/_IHTTPRequest.h>
#endif
#ifndef INCLUDED_lime_utils_CompressionAlgorithm
#include <lime/utils/CompressionAlgorithm.h>
#endif
#ifndef INCLUDED_lime_utils__Bytes_Bytes_Impl_
#include <lime/utils/_Bytes/Bytes_Impl_.h>
#endif

HX_LOCAL_STACK_FRAME(_hx_pos_3ebd2a3b5b6c79d1_19__new,"lime.utils._Bytes.Bytes_Impl_","_new",0x0e8a4e50,"lime.utils._Bytes.Bytes_Impl_._new","lime/utils/Bytes.hx",19,0x9fbf972b)
HX_LOCAL_STACK_FRAME(_hx_pos_3ebd2a3b5b6c79d1_35_alloc,"lime.utils._Bytes.Bytes_Impl_","alloc",0xcffa3ca6,"lime.utils._Bytes.Bytes_Impl_.alloc","lime/utils/Bytes.hx",35,0x9fbf972b)
HX_LOCAL_STACK_FRAME(_hx_pos_3ebd2a3b5b6c79d1_40_compress,"lime.utils._Bytes.Bytes_Impl_","compress",0xf1eb2411,"lime.utils._Bytes.Bytes_Impl_.compress","lime/utils/Bytes.hx",40,0x9fbf972b)
HX_LOCAL_STACK_FRAME(_hx_pos_3ebd2a3b5b6c79d1_61_decompress,"lime.utils._Bytes.Bytes_Impl_","decompress",0x10439e52,"lime.utils._Bytes.Bytes_Impl_.decompress","lime/utils/Bytes.hx",61,0x9fbf972b)
HX_LOCAL_STACK_FRAME(_hx_pos_3ebd2a3b5b6c79d1_82_fastGet,"lime.utils._Bytes.Bytes_Impl_","fastGet",0xe584c5cb,"lime.utils._Bytes.Bytes_Impl_.fastGet","lime/utils/Bytes.hx",82,0x9fbf972b)
HX_LOCAL_STACK_FRAME(_hx_pos_3ebd2a3b5b6c79d1_86_fromBytes,"lime.utils._Bytes.Bytes_Impl_","fromBytes",0x6a55f752,"lime.utils._Bytes.Bytes_Impl_.fromBytes","lime/utils/Bytes.hx",86,0x9fbf972b)
HX_LOCAL_STACK_FRAME(_hx_pos_3ebd2a3b5b6c79d1_93_fromFile,"lime.utils._Bytes.Bytes_Impl_","fromFile",0x0fb37975,"lime.utils._Bytes.Bytes_Impl_.fromFile","lime/utils/Bytes.hx",93,0x9fbf972b)
HX_LOCAL_STACK_FRAME(_hx_pos_3ebd2a3b5b6c79d1_109_loadFromBytes,"lime.utils._Bytes.Bytes_Impl_","loadFromBytes",0x2f7a74cc,"lime.utils._Bytes.Bytes_Impl_.loadFromBytes","lime/utils/Bytes.hx",109,0x9fbf972b)
HX_LOCAL_STACK_FRAME(_hx_pos_3ebd2a3b5b6c79d1_113_loadFromFile,"lime.utils._Bytes.Bytes_Impl_","loadFromFile",0xcbb4c93b,"lime.utils._Bytes.Bytes_Impl_.loadFromFile","lime/utils/Bytes.hx",113,0x9fbf972b)
HX_LOCAL_STACK_FRAME(_hx_pos_3ebd2a3b5b6c79d1_119_ofData,"lime.utils._Bytes.Bytes_Impl_","ofData",0x35174d90,"lime.utils._Bytes.Bytes_Impl_.ofData","lime/utils/Bytes.hx",119,0x9fbf972b)
HX_LOCAL_STACK_FRAME(_hx_pos_3ebd2a3b5b6c79d1_125_ofString,"lime.utils._Bytes.Bytes_Impl_","ofString",0x125d45b7,"lime.utils._Bytes.Bytes_Impl_.ofString","lime/utils/Bytes.hx",125,0x9fbf972b)
HX_LOCAL_STACK_FRAME(_hx_pos_3ebd2a3b5b6c79d1_132___fromNativePointer,"lime.utils._Bytes.Bytes_Impl_","__fromNativePointer",0x287bf4ed,"lime.utils._Bytes.Bytes_Impl_.__fromNativePointer","lime/utils/Bytes.hx",132,0x9fbf972b)
namespace lime{
namespace utils{
namespace _Bytes{

void Bytes_Impl__obj::__construct() { }

Dynamic Bytes_Impl__obj::__CreateEmpty() { return new Bytes_Impl__obj; }

void *Bytes_Impl__obj::_hx_vtable = 0;

Dynamic Bytes_Impl__obj::__Create(::hx::DynamicArray inArgs)
{
	::hx::ObjectPtr< Bytes_Impl__obj > _hx_result = new Bytes_Impl__obj();
	_hx_result->__construct();
	return _hx_result;
}

bool Bytes_Impl__obj::_hx_isInstanceOf(int inClassId) {
	return inClassId==(int)0x00000001 || inClassId==(int)0x0007f847;
}

 ::haxe::io::Bytes Bytes_Impl__obj::_new(int length,::Array< unsigned char > bytesData){
            	HX_GC_STACKFRAME(&_hx_pos_3ebd2a3b5b6c79d1_19__new)
HXDLIN(  19)		return  ::haxe::io::Bytes_obj::__alloc( HX_CTX ,length,bytesData);
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Bytes_Impl__obj,_new,return )

 ::haxe::io::Bytes Bytes_Impl__obj::alloc(int length){
            	HX_STACKFRAME(&_hx_pos_3ebd2a3b5b6c79d1_35_alloc)
HXDLIN(  35)		return ::haxe::io::Bytes_obj::alloc(length);
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Bytes_Impl__obj,alloc,return )

 ::haxe::io::Bytes Bytes_Impl__obj::compress( ::haxe::io::Bytes this1, ::lime::utils::CompressionAlgorithm algorithm){
            	HX_STACKFRAME(&_hx_pos_3ebd2a3b5b6c79d1_40_compress)
HXDLIN(  40)		switch((int)(algorithm->_hx_getIndex())){
            			case (int)0: {
HXLINE(  43)				return ::lime::_internal::format::Deflate_obj::compress(this1);
            			}
            			break;
            			case (int)1: {
HXLINE(  46)				return ::lime::_internal::format::GZip_obj::compress(this1);
            			}
            			break;
            			case (int)2: {
HXLINE(  49)				return ::lime::_internal::format::LZMA_obj::compress(this1);
            			}
            			break;
            			case (int)3: {
HXLINE(  52)				return ::lime::_internal::format::Zlib_obj::compress(this1);
            			}
            			break;
            		}
HXLINE(  40)		return null();
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Bytes_Impl__obj,compress,return )

 ::haxe::io::Bytes Bytes_Impl__obj::decompress( ::haxe::io::Bytes this1, ::lime::utils::CompressionAlgorithm algorithm){
            	HX_STACKFRAME(&_hx_pos_3ebd2a3b5b6c79d1_61_decompress)
HXDLIN(  61)		switch((int)(algorithm->_hx_getIndex())){
            			case (int)0: {
HXLINE(  64)				return ::lime::_internal::format::Deflate_obj::decompress(this1);
            			}
            			break;
            			case (int)1: {
HXLINE(  67)				return ::lime::_internal::format::GZip_obj::decompress(this1);
            			}
            			break;
            			case (int)2: {
HXLINE(  70)				return ::lime::_internal::format::LZMA_obj::decompress(this1);
            			}
            			break;
            			case (int)3: {
HXLINE(  73)				return ::lime::_internal::format::Zlib_obj::decompress(this1);
            			}
            			break;
            		}
HXLINE(  61)		return null();
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Bytes_Impl__obj,decompress,return )

int Bytes_Impl__obj::fastGet(::Array< unsigned char > b,int pos){
            	HX_STACKFRAME(&_hx_pos_3ebd2a3b5b6c79d1_82_fastGet)
HXDLIN(  82)		return ( (int)(_hx_array_unsafe_get(b,pos)) );
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Bytes_Impl__obj,fastGet,return )

 ::haxe::io::Bytes Bytes_Impl__obj::fromBytes( ::haxe::io::Bytes bytes){
            	HX_STACKFRAME(&_hx_pos_3ebd2a3b5b6c79d1_86_fromBytes)
HXLINE(  87)		if (::hx::IsNull( bytes )) {
HXLINE(  87)			return null();
            		}
HXLINE(  89)		return ::lime::utils::_Bytes::Bytes_Impl__obj::_new(bytes->length,bytes->b);
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Bytes_Impl__obj,fromBytes,return )

 ::haxe::io::Bytes Bytes_Impl__obj::fromFile(::String path){
            	HX_STACKFRAME(&_hx_pos_3ebd2a3b5b6c79d1_93_fromFile)
HXLINE(  96)		 ::haxe::io::Bytes bytes = ::lime::utils::_Bytes::Bytes_Impl__obj::alloc(0);
HXLINE(  97)		::lime::_internal::backend::native::NativeCFFI_obj::lime_bytes_read_file(path,::hx::DynamicPtr(bytes));
HXLINE(  98)		if ((bytes->length > 0)) {
HXLINE(  98)			return bytes;
            		}
HXLINE( 104)		return null();
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Bytes_Impl__obj,fromFile,return )

 ::lime::app::Future Bytes_Impl__obj::loadFromBytes( ::haxe::io::Bytes bytes){
            	HX_STACKFRAME(&_hx_pos_3ebd2a3b5b6c79d1_109_loadFromBytes)
HXDLIN( 109)		return ::lime::app::Future_obj::withValue(::lime::utils::_Bytes::Bytes_Impl__obj::fromBytes(bytes));
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Bytes_Impl__obj,loadFromBytes,return )

 ::lime::app::Future Bytes_Impl__obj::loadFromFile(::String path){
            	HX_GC_STACKFRAME(&_hx_pos_3ebd2a3b5b6c79d1_113_loadFromFile)
HXLINE( 114)		 ::lime::net::_HTTPRequest_lime_utils_Bytes request =  ::lime::net::_HTTPRequest_lime_utils_Bytes_obj::__alloc( HX_CTX ,null());
HXLINE( 115)		return request->load(path);
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Bytes_Impl__obj,loadFromFile,return )

 ::haxe::io::Bytes Bytes_Impl__obj::ofData(::Array< unsigned char > b){
            	HX_STACKFRAME(&_hx_pos_3ebd2a3b5b6c79d1_119_ofData)
HXLINE( 120)		 ::haxe::io::Bytes bytes = ::haxe::io::Bytes_obj::ofData(b);
HXLINE( 121)		return ::lime::utils::_Bytes::Bytes_Impl__obj::_new(bytes->length,bytes->b);
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Bytes_Impl__obj,ofData,return )

 ::haxe::io::Bytes Bytes_Impl__obj::ofString(::String s){
            	HX_STACKFRAME(&_hx_pos_3ebd2a3b5b6c79d1_125_ofString)
HXLINE( 126)		 ::haxe::io::Bytes bytes = ::haxe::io::Bytes_obj::ofString(s,null());
HXLINE( 127)		return ::lime::utils::_Bytes::Bytes_Impl__obj::_new(bytes->length,bytes->b);
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Bytes_Impl__obj,ofString,return )

 ::haxe::io::Bytes Bytes_Impl__obj::_hx___fromNativePointer( ::Dynamic data,int length){
            	HX_STACKFRAME(&_hx_pos_3ebd2a3b5b6c79d1_132___fromNativePointer)
HXLINE( 133)		 ::haxe::io::Bytes bytes = ::lime::utils::_Bytes::Bytes_Impl__obj::alloc(0);
HXLINE( 134)		return ( ( ::Dynamic)(::lime::_internal::backend::native::NativeCFFI_obj::lime_bytes_from_data_pointer(( (Float)(data) ),length,::hx::DynamicPtr(bytes))) );
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Bytes_Impl__obj,_hx___fromNativePointer,return )


Bytes_Impl__obj::Bytes_Impl__obj()
{
}

bool Bytes_Impl__obj::__GetStatic(const ::String &inName, Dynamic &outValue, ::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"_new") ) { outValue = _new_dyn(); return true; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"alloc") ) { outValue = alloc_dyn(); return true; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"ofData") ) { outValue = ofData_dyn(); return true; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"fastGet") ) { outValue = fastGet_dyn(); return true; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"compress") ) { outValue = compress_dyn(); return true; }
		if (HX_FIELD_EQ(inName,"fromFile") ) { outValue = fromFile_dyn(); return true; }
		if (HX_FIELD_EQ(inName,"ofString") ) { outValue = ofString_dyn(); return true; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"fromBytes") ) { outValue = fromBytes_dyn(); return true; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"decompress") ) { outValue = decompress_dyn(); return true; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"loadFromFile") ) { outValue = loadFromFile_dyn(); return true; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"loadFromBytes") ) { outValue = loadFromBytes_dyn(); return true; }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"__fromNativePointer") ) { outValue = _hx___fromNativePointer_dyn(); return true; }
	}
	return false;
}

#ifdef HXCPP_SCRIPTABLE
static ::hx::StorageInfo *Bytes_Impl__obj_sMemberStorageInfo = 0;
static ::hx::StaticInfo *Bytes_Impl__obj_sStaticStorageInfo = 0;
#endif

::hx::Class Bytes_Impl__obj::__mClass;

static ::String Bytes_Impl__obj_sStaticFields[] = {
	HX_("_new",61,15,1f,3f),
	HX_("alloc",75,a4,93,21),
	HX_("compress",a2,47,bf,83),
	HX_("decompress",23,88,14,da),
	HX_("fastGet",5a,ff,22,de),
	HX_("fromBytes",a1,f2,20,72),
	HX_("fromFile",06,9d,87,a1),
	HX_("loadFromBytes",9b,c3,86,f4),
	HX_("loadFromFile",4c,89,f0,5a),
	HX_("ofData",e1,ba,b8,49),
	HX_("ofString",48,69,31,a4),
	HX_("__fromNativePointer",fc,c8,91,68),
	::String(null())
};

void Bytes_Impl__obj::__register()
{
	Bytes_Impl__obj _hx_dummy;
	Bytes_Impl__obj::_hx_vtable = *(void **)&_hx_dummy;
	::hx::Static(__mClass) = new ::hx::Class_obj();
	__mClass->mName = HX_("lime.utils._Bytes.Bytes_Impl_",df,cd,f1,d5);
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mConstructEmpty = &__CreateEmpty;
	__mClass->mConstructArgs = &__Create;
	__mClass->mGetStaticField = &Bytes_Impl__obj::__GetStatic;
	__mClass->mSetStaticField = &::hx::Class_obj::SetNoStaticField;
	__mClass->mStatics = ::hx::Class_obj::dupFunctions(Bytes_Impl__obj_sStaticFields);
	__mClass->mMembers = ::hx::Class_obj::dupFunctions(0 /* sMemberFields */);
	__mClass->mCanCast = ::hx::TCanCast< Bytes_Impl__obj >;
#ifdef HXCPP_SCRIPTABLE
	__mClass->mMemberStorageInfo = Bytes_Impl__obj_sMemberStorageInfo;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mStaticStorageInfo = Bytes_Impl__obj_sStaticStorageInfo;
#endif
	::hx::_hx_RegisterClass(__mClass->mName, __mClass);
}

} // end namespace lime
} // end namespace utils
} // end namespace _Bytes
