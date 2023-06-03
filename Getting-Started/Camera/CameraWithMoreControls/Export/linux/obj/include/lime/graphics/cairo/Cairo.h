// Generated by Haxe 5.0.0-alpha.1+2f4b99d
#ifndef INCLUDED_lime_graphics_cairo_Cairo
#define INCLUDED_lime_graphics_cairo_Cairo

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(lime,graphics,cairo,Cairo)
HX_DECLARE_CLASS3(lime,graphics,cairo,CairoGlyph)
HX_DECLARE_CLASS2(lime,math,Matrix3)
HX_DECLARE_CLASS2(lime,math,Vector2)

namespace lime{
namespace graphics{
namespace cairo{


class HXCPP_CLASS_ATTRIBUTES Cairo_obj : public ::hx::Object
{
	public:
		typedef ::hx::Object super;
		typedef Cairo_obj OBJ_;
		Cairo_obj();

	public:
		enum { _hx_ClassId = 0x0bd6c148 };

		void __construct( ::Dynamic surface);
		inline void *operator new(size_t inSize, bool inContainer=true,const char *inName="lime.graphics.cairo.Cairo")
			{ return ::hx::Object::operator new(inSize,inContainer,inName); }
		inline void *operator new(size_t inSize, int extra)
			{ return ::hx::Object::operator new(inSize+extra,true,"lime.graphics.cairo.Cairo"); }
		static ::hx::ObjectPtr< Cairo_obj > __new( ::Dynamic surface);
		static ::hx::ObjectPtr< Cairo_obj > __alloc(::hx::Ctx *_hx_ctx, ::Dynamic surface);
		static void * _hx_vtable;
		static Dynamic __CreateEmpty();
		static Dynamic __Create(::hx::DynamicArray inArgs);
		//~Cairo_obj();

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
		::String __ToString() const { return HX_("Cairo",68,a0,46,d4); }

		static int version;
		static ::String versionString;
		static int get_version();
		static ::Dynamic get_version_dyn();

		static ::String get_versionString();
		static ::Dynamic get_versionString_dyn();

		 ::Dynamic target;
		 ::Dynamic userData;
		 ::Dynamic handle;
		void arc(Float xc,Float yc,Float radius,Float angle1,Float angle2);
		::Dynamic arc_dyn();

		void arcNegative(Float xc,Float yc,Float radius,Float angle1,Float angle2);
		::Dynamic arcNegative_dyn();

		void clip();
		::Dynamic clip_dyn();

		void clipExtents(Float x1,Float y1,Float x2,Float y2);
		::Dynamic clipExtents_dyn();

		void clipPreserve();
		::Dynamic clipPreserve_dyn();

		void closePath();
		::Dynamic closePath_dyn();

		void copyPage();
		::Dynamic copyPage_dyn();

		void curveTo(Float x1,Float y1,Float x2,Float y2,Float x3,Float y3);
		::Dynamic curveTo_dyn();

		void fill();
		::Dynamic fill_dyn();

		void fillExtents(Float x1,Float y1,Float x2,Float y2);
		::Dynamic fillExtents_dyn();

		void fillPreserve();
		::Dynamic fillPreserve_dyn();

		int getOperator();
		::Dynamic getOperator_dyn();

		void identityMatrix();
		::Dynamic identityMatrix_dyn();

		bool inClip(Float x,Float y);
		::Dynamic inClip_dyn();

		bool inFill(Float x,Float y);
		::Dynamic inFill_dyn();

		bool inStroke(Float x,Float y);
		::Dynamic inStroke_dyn();

		void lineTo(Float x,Float y);
		::Dynamic lineTo_dyn();

		void mask( ::Dynamic pattern);
		::Dynamic mask_dyn();

		void maskSurface( ::Dynamic surface,Float x,Float y);
		::Dynamic maskSurface_dyn();

		void moveTo(Float x,Float y);
		::Dynamic moveTo_dyn();

		void newPath();
		::Dynamic newPath_dyn();

		void paint();
		::Dynamic paint_dyn();

		void paintWithAlpha(Float alpha);
		::Dynamic paintWithAlpha_dyn();

		 ::Dynamic popGroup();
		::Dynamic popGroup_dyn();

		void popGroupToSource();
		::Dynamic popGroupToSource_dyn();

		void pushGroup();
		::Dynamic pushGroup_dyn();

		void pushGroupWithContent(int content);
		::Dynamic pushGroupWithContent_dyn();

		void recreate( ::Dynamic surface);
		::Dynamic recreate_dyn();

		void rectangle(Float x,Float y,Float width,Float height);
		::Dynamic rectangle_dyn();

		void relCurveTo(Float dx1,Float dy1,Float dx2,Float dy2,Float dx3,Float dy3);
		::Dynamic relCurveTo_dyn();

		void relLineTo(Float dx,Float dy);
		::Dynamic relLineTo_dyn();

		void relMoveTo(Float dx,Float dy);
		::Dynamic relMoveTo_dyn();

		void resetClip();
		::Dynamic resetClip_dyn();

		void restore();
		::Dynamic restore_dyn();

		void rotate(Float amount);
		::Dynamic rotate_dyn();

		void save();
		::Dynamic save_dyn();

		void scale(Float x,Float y);
		::Dynamic scale_dyn();

		void setFontSize(Float size);
		::Dynamic setFontSize_dyn();

		int setOperator(int value);
		::Dynamic setOperator_dyn();

		void setSourceRGB(Float r,Float g,Float b);
		::Dynamic setSourceRGB_dyn();

		void setSourceRGBA(Float r,Float g,Float b,Float a);
		::Dynamic setSourceRGBA_dyn();

		void setSourceSurface( ::Dynamic surface,Float x,Float y);
		::Dynamic setSourceSurface_dyn();

		void showGlyphs(::Array< ::Dynamic> glyphs);
		::Dynamic showGlyphs_dyn();

		void showPage();
		::Dynamic showPage_dyn();

		void showText(::String utf8);
		::Dynamic showText_dyn();

		int status();
		::Dynamic status_dyn();

		void stroke();
		::Dynamic stroke_dyn();

		void strokeExtents(Float x1,Float y1,Float x2,Float y2);
		::Dynamic strokeExtents_dyn();

		void strokePreserve();
		::Dynamic strokePreserve_dyn();

		void textPath(::String utf8);
		::Dynamic textPath_dyn();

		void transform( ::lime::math::Matrix3 matrix);
		::Dynamic transform_dyn();

		void translate(Float x,Float y);
		::Dynamic translate_dyn();

		int get_antialias();
		::Dynamic get_antialias_dyn();

		int set_antialias(int value);
		::Dynamic set_antialias_dyn();

		 ::lime::math::Vector2 get_currentPoint();
		::Dynamic get_currentPoint_dyn();

		::Array< Float > get_dash();
		::Dynamic get_dash_dyn();

		::Array< Float > set_dash(::Array< Float > value);
		::Dynamic set_dash_dyn();

		int get_dashCount();
		::Dynamic get_dashCount_dyn();

		int get_fillRule();
		::Dynamic get_fillRule_dyn();

		int set_fillRule(int value);
		::Dynamic set_fillRule_dyn();

		 ::Dynamic get_fontFace();
		::Dynamic get_fontFace_dyn();

		 ::Dynamic set_fontFace( ::Dynamic value);
		::Dynamic set_fontFace_dyn();

		 ::Dynamic get_fontOptions();
		::Dynamic get_fontOptions_dyn();

		 ::Dynamic set_fontOptions( ::Dynamic value);
		::Dynamic set_fontOptions_dyn();

		 ::Dynamic get_groupTarget();
		::Dynamic get_groupTarget_dyn();

		bool get_hasCurrentPoint();
		::Dynamic get_hasCurrentPoint_dyn();

		int get_lineCap();
		::Dynamic get_lineCap_dyn();

		int set_lineCap(int value);
		::Dynamic set_lineCap_dyn();

		int get_lineJoin();
		::Dynamic get_lineJoin_dyn();

		int set_lineJoin(int value);
		::Dynamic set_lineJoin_dyn();

		Float get_lineWidth();
		::Dynamic get_lineWidth_dyn();

		Float set_lineWidth(Float value);
		::Dynamic set_lineWidth_dyn();

		 ::lime::math::Matrix3 get_matrix();
		::Dynamic get_matrix_dyn();

		 ::lime::math::Matrix3 set_matrix( ::lime::math::Matrix3 value);
		::Dynamic set_matrix_dyn();

		Float get_miterLimit();
		::Dynamic get_miterLimit_dyn();

		Float set_miterLimit(Float value);
		::Dynamic set_miterLimit_dyn();

		 ::Dynamic get_source();
		::Dynamic get_source_dyn();

		 ::Dynamic set_source( ::Dynamic value);
		::Dynamic set_source_dyn();

		 ::Dynamic get_target();
		::Dynamic get_target_dyn();

		Float get_tolerance();
		::Dynamic get_tolerance_dyn();

		Float set_tolerance(Float value);
		::Dynamic set_tolerance_dyn();

};

} // end namespace lime
} // end namespace graphics
} // end namespace cairo

#endif /* INCLUDED_lime_graphics_cairo_Cairo */ 
