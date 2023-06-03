// Generated by Haxe 5.0.0-alpha.1+2f4b99d
#include <hxcpp.h>

#ifndef INCLUDED_lime__internal_graphics_ImageCanvasUtil
#include <lime/_internal/graphics/ImageCanvasUtil.h>
#endif
#ifndef INCLUDED_lime_graphics_Image
#include <lime/graphics/Image.h>
#endif
#ifndef INCLUDED_lime_graphics_ImageBuffer
#include <lime/graphics/ImageBuffer.h>
#endif
#ifndef INCLUDED_lime_graphics_ImageType
#include <lime/graphics/ImageType.h>
#endif
#ifndef INCLUDED_lime_math_Rectangle
#include <lime/math/Rectangle.h>
#endif

HX_LOCAL_STACK_FRAME(_hx_pos_c961afc6e6a20fc0_75_convertToCanvas,"lime._internal.graphics.ImageCanvasUtil","convertToCanvas",0xeeada195,"lime._internal.graphics.ImageCanvasUtil.convertToCanvas","lime/_internal/graphics/ImageCanvasUtil.hx",75,0x04a6dce0)
HX_LOCAL_STACK_FRAME(_hx_pos_c961afc6e6a20fc0_180_createCanvas,"lime._internal.graphics.ImageCanvasUtil","createCanvas",0x241eedc5,"lime._internal.graphics.ImageCanvasUtil.createCanvas","lime/_internal/graphics/ImageCanvasUtil.hx",180,0x04a6dce0)
HX_LOCAL_STACK_FRAME(_hx_pos_c961afc6e6a20fc0_226_fillRect,"lime._internal.graphics.ImageCanvasUtil","fillRect",0xcb6da198,"lime._internal.graphics.ImageCanvasUtil.fillRect","lime/_internal/graphics/ImageCanvasUtil.hx",226,0x04a6dce0)
namespace lime{
namespace _internal{
namespace graphics{

void ImageCanvasUtil_obj::__construct() { }

Dynamic ImageCanvasUtil_obj::__CreateEmpty() { return new ImageCanvasUtil_obj; }

void *ImageCanvasUtil_obj::_hx_vtable = 0;

Dynamic ImageCanvasUtil_obj::__Create(::hx::DynamicArray inArgs)
{
	::hx::ObjectPtr< ImageCanvasUtil_obj > _hx_result = new ImageCanvasUtil_obj();
	_hx_result->__construct();
	return _hx_result;
}

bool ImageCanvasUtil_obj::_hx_isInstanceOf(int inClassId) {
	return inClassId==(int)0x00000001 || inClassId==(int)0x608a0907;
}

void ImageCanvasUtil_obj::convertToCanvas( ::lime::graphics::Image image,::hx::Null< bool >  __o_clear){
            		bool clear = __o_clear.Default(false);
            	HX_STACKFRAME(&_hx_pos_c961afc6e6a20fc0_75_convertToCanvas)
HXDLIN(  75)		image->type = ::lime::graphics::ImageType_obj::CANVAS_dyn();
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(ImageCanvasUtil_obj,convertToCanvas,(void))

void ImageCanvasUtil_obj::createCanvas( ::lime::graphics::Image image,int width,int height){
            	HX_STACKFRAME(&_hx_pos_c961afc6e6a20fc0_180_createCanvas)
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(ImageCanvasUtil_obj,createCanvas,(void))

void ImageCanvasUtil_obj::fillRect( ::lime::graphics::Image image, ::lime::math::Rectangle rect,int color,int format){
            	HX_STACKFRAME(&_hx_pos_c961afc6e6a20fc0_226_fillRect)
HXLINE( 227)		::lime::_internal::graphics::ImageCanvasUtil_obj::convertToCanvas(image,null());
HXLINE( 229)		int r;
HXDLIN( 229)		int g;
HXDLIN( 229)		int b;
HXDLIN( 229)		int a;
HXLINE( 231)		if ((format == 1)) {
HXLINE( 233)			r = ((color >> 16) & 255);
HXLINE( 234)			g = ((color >> 8) & 255);
HXLINE( 235)			b = (color & 255);
HXLINE( 236)			if (image->get_transparent()) {
HXLINE( 236)				a = ((color >> 24) & 255);
            			}
            			else {
HXLINE( 236)				a = 255;
            			}
            		}
            		else {
HXLINE( 240)			r = ((color >> 24) & 255);
HXLINE( 241)			g = ((color >> 16) & 255);
HXLINE( 242)			b = ((color >> 8) & 255);
HXLINE( 243)			if (image->get_transparent()) {
HXLINE( 243)				a = (color & 255);
            			}
            			else {
HXLINE( 243)				a = 255;
            			}
            		}
HXLINE( 246)		bool _hx_tmp;
HXDLIN( 246)		bool _hx_tmp1;
HXDLIN( 246)		bool _hx_tmp2;
HXDLIN( 246)		if ((rect->x == 0)) {
HXLINE( 246)			_hx_tmp2 = (rect->y == 0);
            		}
            		else {
HXLINE( 246)			_hx_tmp2 = false;
            		}
HXDLIN( 246)		if (_hx_tmp2) {
HXLINE( 246)			_hx_tmp1 = (rect->width == image->width);
            		}
            		else {
HXLINE( 246)			_hx_tmp1 = false;
            		}
HXDLIN( 246)		if (_hx_tmp1) {
HXLINE( 246)			_hx_tmp = (rect->height == image->height);
            		}
            		else {
HXLINE( 246)			_hx_tmp = false;
            		}
HXDLIN( 246)		if (_hx_tmp) {
HXLINE( 248)			bool _hx_tmp3;
HXDLIN( 248)			if (image->get_transparent()) {
HXLINE( 248)				_hx_tmp3 = (a == 0);
            			}
            			else {
HXLINE( 248)				_hx_tmp3 = false;
            			}
HXDLIN( 248)			if (_hx_tmp3) {
HXLINE( 250)				image->buffer->_hx___srcCanvas->__SetField(HX_("width",06,b6,62,ca),image->buffer->width,::hx::paccDynamic);
HXLINE( 251)				return;
            			}
            		}
HXLINE( 255)		if ((a < 255)) {
HXLINE( 257)			image->buffer->_hx___srcContext->__Field(HX_("clearRect",51,35,68,bf),::hx::paccDynamic)((rect->x + image->offsetX),(rect->y + image->offsetY),(rect->width + image->offsetX),(rect->height + image->offsetY));
            		}
HXLINE( 260)		if ((a > 0)) {
HXLINE( 262)			image->buffer->_hx___srcContext->__SetField(HX_("fillStyle",ae,cb,c4,52),((((((((HX_("rgba(",f4,cc,0d,e8) + r) + HX_(", ",74,26,00,00)) + g) + HX_(", ",74,26,00,00)) + b) + HX_(", ",74,26,00,00)) + (( (Float)(a) ) / ( (Float)(255) ))) + HX_(")",29,00,00,00)),::hx::paccDynamic);
HXLINE( 263)			image->buffer->_hx___srcContext->__Field(HX_("fillRect",47,45,b9,6c),::hx::paccDynamic)((rect->x + image->offsetX),(rect->y + image->offsetY),(rect->width + image->offsetX),(rect->height + image->offsetY));
            		}
HXLINE( 266)		image->dirty = true;
HXLINE( 267)		image->version++;
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC4(ImageCanvasUtil_obj,fillRect,(void))


ImageCanvasUtil_obj::ImageCanvasUtil_obj()
{
}

bool ImageCanvasUtil_obj::__GetStatic(const ::String &inName, Dynamic &outValue, ::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 8:
		if (HX_FIELD_EQ(inName,"fillRect") ) { outValue = fillRect_dyn(); return true; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"createCanvas") ) { outValue = createCanvas_dyn(); return true; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"convertToCanvas") ) { outValue = convertToCanvas_dyn(); return true; }
	}
	return false;
}

#ifdef HXCPP_SCRIPTABLE
static ::hx::StorageInfo *ImageCanvasUtil_obj_sMemberStorageInfo = 0;
static ::hx::StaticInfo *ImageCanvasUtil_obj_sStaticStorageInfo = 0;
#endif

::hx::Class ImageCanvasUtil_obj::__mClass;

static ::String ImageCanvasUtil_obj_sStaticFields[] = {
	HX_("convertToCanvas",c6,61,e8,14),
	HX_("createCanvas",f4,94,97,da),
	HX_("fillRect",47,45,b9,6c),
	::String(null())
};

void ImageCanvasUtil_obj::__register()
{
	ImageCanvasUtil_obj _hx_dummy;
	ImageCanvasUtil_obj::_hx_vtable = *(void **)&_hx_dummy;
	::hx::Static(__mClass) = new ::hx::Class_obj();
	__mClass->mName = HX_("lime._internal.graphics.ImageCanvasUtil",3d,d2,c0,58);
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mConstructEmpty = &__CreateEmpty;
	__mClass->mConstructArgs = &__Create;
	__mClass->mGetStaticField = &ImageCanvasUtil_obj::__GetStatic;
	__mClass->mSetStaticField = &::hx::Class_obj::SetNoStaticField;
	__mClass->mStatics = ::hx::Class_obj::dupFunctions(ImageCanvasUtil_obj_sStaticFields);
	__mClass->mMembers = ::hx::Class_obj::dupFunctions(0 /* sMemberFields */);
	__mClass->mCanCast = ::hx::TCanCast< ImageCanvasUtil_obj >;
#ifdef HXCPP_SCRIPTABLE
	__mClass->mMemberStorageInfo = ImageCanvasUtil_obj_sMemberStorageInfo;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mStaticStorageInfo = ImageCanvasUtil_obj_sStaticStorageInfo;
#endif
	::hx::_hx_RegisterClass(__mClass->mName, __mClass);
}

} // end namespace lime
} // end namespace _internal
} // end namespace graphics
