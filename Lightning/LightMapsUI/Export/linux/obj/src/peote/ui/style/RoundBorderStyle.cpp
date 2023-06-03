// Generated by Haxe 5.0.0-alpha.1+2f4b99d
#include <hxcpp.h>

#ifndef INCLUDED_peote_ui_style_RoundBorderStyle
#include <peote/ui/style/RoundBorderStyle.h>
#endif
#ifndef INCLUDED_peote_ui_style_RoundBorderStyleProgram
#include <peote/ui/style/RoundBorderStyleProgram.h>
#endif
#ifndef INCLUDED_peote_ui_style_interfaces_Style
#include <peote/ui/style/interfaces/Style.h>
#endif
#ifndef INCLUDED_peote_ui_style_interfaces_StyleID
#include <peote/ui/style/interfaces/StyleID.h>
#endif
#ifndef INCLUDED_peote_ui_style_interfaces_StyleProgram
#include <peote/ui/style/interfaces/StyleProgram.h>
#endif
#ifndef INCLUDED_peote_view_Program
#include <peote/view/Program.h>
#endif

HX_DEFINE_STACK_FRAME(_hx_pos_0ed7c21cd06884b5_15_new,"peote.ui.style.RoundBorderStyle","new",0xc66fb0dd,"peote.ui.style.RoundBorderStyle.new","peote/ui/style/RoundBorderStyle.hx",15,0x1deb3332)
HX_LOCAL_STACK_FRAME(_hx_pos_0ed7c21cd06884b5_25_createStyleProgram,"peote.ui.style.RoundBorderStyle","createStyleProgram",0xd1e5b692,"peote.ui.style.RoundBorderStyle.createStyleProgram","peote/ui/style/RoundBorderStyle.hx",25,0x1deb3332)
HX_LOCAL_STACK_FRAME(_hx_pos_0ed7c21cd06884b5_15_copy,"peote.ui.style.RoundBorderStyle","copy",0xd40d4898,"peote.ui.style.RoundBorderStyle.copy","peote/ui/style/RoundBorderStyle.hx",15,0x1deb3332)
HX_LOCAL_STACK_FRAME(_hx_pos_eb27d20284f429e0_201_getUUID,"peote.ui.style.RoundBorderStyle","getUUID",0x4abbc8ce,"peote.ui.style.RoundBorderStyle.getUUID","peote/ui/style/interfaces/Style.hx",201,0xa7357ccd)
HX_LOCAL_STACK_FRAME(_hx_pos_eb27d20284f429e0_216_isFontStyle,"peote.ui.style.RoundBorderStyle","isFontStyle",0x23562515,"peote.ui.style.RoundBorderStyle.isFontStyle","peote/ui/style/interfaces/Style.hx",216,0xa7357ccd)
HX_LOCAL_STACK_FRAME(_hx_pos_eb27d20284f429e0_179_boot,"peote.ui.style.RoundBorderStyle","boot",0xd3641115,"peote.ui.style.RoundBorderStyle.boot","peote/ui/style/interfaces/Style.hx",179,0xa7357ccd)
namespace peote{
namespace ui{
namespace style{

void RoundBorderStyle_obj::__construct( ::Dynamic color, ::Dynamic borderColor, ::Dynamic borderSize, ::Dynamic borderRadius){
            	HX_STACKFRAME(&_hx_pos_0ed7c21cd06884b5_15_new)
HXLINE( 188)		this->id = 0;
HXLINE(  21)		this->borderRadius = ((Float)6.0);
HXLINE(  20)		this->borderSize = ((Float)1.0);
HXLINE(  19)		this->borderColor = (int)-2004317953;
HXLINE(  18)		this->color = (int)1717987071;
HXLINE( 106)		if (::hx::IsNotNull( color )) {
HXLINE( 106)			this->color = ( (int)(color) );
            		}
HXDLIN( 106)		if (::hx::IsNotNull( borderColor )) {
HXLINE( 106)			this->borderColor = ( (int)(borderColor) );
            		}
HXDLIN( 106)		if (::hx::IsNotNull( borderSize )) {
HXLINE( 106)			this->borderSize = ( (Float)(borderSize) );
            		}
HXDLIN( 106)		if (::hx::IsNotNull( borderRadius )) {
HXLINE( 106)			this->borderRadius = ( (Float)(borderRadius) );
            		}
            	}

Dynamic RoundBorderStyle_obj::__CreateEmpty() { return new RoundBorderStyle_obj; }

void *RoundBorderStyle_obj::_hx_vtable = 0;

Dynamic RoundBorderStyle_obj::__Create(::hx::DynamicArray inArgs)
{
	::hx::ObjectPtr< RoundBorderStyle_obj > _hx_result = new RoundBorderStyle_obj();
	_hx_result->__construct(inArgs[0],inArgs[1],inArgs[2],inArgs[3]);
	return _hx_result;
}

bool RoundBorderStyle_obj::_hx_isInstanceOf(int inClassId) {
	return inClassId==(int)0x00000001 || inClassId==(int)0x250e9209;
}

static ::peote::ui::style::interfaces::StyleID_obj _hx_peote_ui_style_RoundBorderStyle__hx_peote_ui_style_interfaces_StyleID= {
	( int (::hx::Object::*)())&::peote::ui::style::RoundBorderStyle_obj::getUUID,
	( bool (::hx::Object::*)())&::peote::ui::style::RoundBorderStyle_obj::isFontStyle,
};

static ::peote::ui::style::interfaces::Style_obj _hx_peote_ui_style_RoundBorderStyle__hx_peote_ui_style_interfaces_Style= {
	( int (::hx::Object::*)())&::peote::ui::style::RoundBorderStyle_obj::getUUID,
	( bool (::hx::Object::*)())&::peote::ui::style::RoundBorderStyle_obj::isFontStyle,
};

void *RoundBorderStyle_obj::_hx_getInterface(int inHash) {
	switch(inHash) {
		case (int)0x94b13ba0: return &_hx_peote_ui_style_RoundBorderStyle__hx_peote_ui_style_interfaces_StyleID;
		case (int)0xae281085: return &_hx_peote_ui_style_RoundBorderStyle__hx_peote_ui_style_interfaces_Style;
	}
	#ifdef HXCPP_SCRIPTABLE
	return super::_hx_getInterface(inHash);
	#else
	return 0;
	#endif
}

::Dynamic RoundBorderStyle_obj::createStyleProgram(){
            	HX_GC_STACKFRAME(&_hx_pos_0ed7c21cd06884b5_25_createStyleProgram)
HXDLIN(  25)		return  ::peote::ui::style::RoundBorderStyleProgram_obj::__alloc( HX_CTX );
            	}


HX_DEFINE_DYNAMIC_FUNC0(RoundBorderStyle_obj,createStyleProgram,return )

 ::peote::ui::style::RoundBorderStyle RoundBorderStyle_obj::copy( ::Dynamic color, ::Dynamic borderColor, ::Dynamic borderSize, ::Dynamic borderRadius){
            	HX_GC_STACKFRAME(&_hx_pos_0ed7c21cd06884b5_15_copy)
HXDLIN(  15)		 ::Dynamic newStyle;
HXDLIN(  15)		if (::hx::IsNotNull( color )) {
HXDLIN(  15)			newStyle = color;
            		}
            		else {
HXDLIN(  15)			newStyle = this->color;
            		}
HXDLIN(  15)		 ::Dynamic newStyle1;
HXDLIN(  15)		if (::hx::IsNotNull( borderColor )) {
HXDLIN(  15)			newStyle1 = borderColor;
            		}
            		else {
HXDLIN(  15)			newStyle1 = this->borderColor;
            		}
HXDLIN(  15)		 ::Dynamic newStyle2;
HXDLIN(  15)		if (::hx::IsNotNull( borderSize )) {
HXDLIN(  15)			newStyle2 = borderSize;
            		}
            		else {
HXDLIN(  15)			newStyle2 = this->borderSize;
            		}
HXDLIN(  15)		 ::Dynamic newStyle3;
HXDLIN(  15)		if (::hx::IsNotNull( borderRadius )) {
HXDLIN(  15)			newStyle3 = borderRadius;
            		}
            		else {
HXDLIN(  15)			newStyle3 = this->borderRadius;
            		}
HXDLIN(  15)		 ::peote::ui::style::RoundBorderStyle newStyle4 =  ::peote::ui::style::RoundBorderStyle_obj::__alloc( HX_CTX ,newStyle,newStyle1,newStyle2,newStyle3);
HXDLIN(  15)		newStyle4->id = this->id;
HXDLIN(  15)		return newStyle4;
            	}


HX_DEFINE_DYNAMIC_FUNC4(RoundBorderStyle_obj,copy,return )

int RoundBorderStyle_obj::getUUID(){
            	HX_STACKFRAME(&_hx_pos_eb27d20284f429e0_201_getUUID)
HXDLIN( 201)		return (::peote::ui::style::RoundBorderStyle_obj::ID | this->id);
            	}


HX_DEFINE_DYNAMIC_FUNC0(RoundBorderStyle_obj,getUUID,return )

bool RoundBorderStyle_obj::isFontStyle(){
            	HX_STACKFRAME(&_hx_pos_eb27d20284f429e0_216_isFontStyle)
HXDLIN( 216)		return (::peote::ui::style::RoundBorderStyle_obj::ID >= 2097152);
            	}


HX_DEFINE_DYNAMIC_FUNC0(RoundBorderStyle_obj,isFontStyle,return )

int RoundBorderStyle_obj::ID;


::hx::ObjectPtr< RoundBorderStyle_obj > RoundBorderStyle_obj::__new( ::Dynamic color, ::Dynamic borderColor, ::Dynamic borderSize, ::Dynamic borderRadius) {
	::hx::ObjectPtr< RoundBorderStyle_obj > __this = new RoundBorderStyle_obj();
	__this->__construct(color,borderColor,borderSize,borderRadius);
	return __this;
}

::hx::ObjectPtr< RoundBorderStyle_obj > RoundBorderStyle_obj::__alloc(::hx::Ctx *_hx_ctx, ::Dynamic color, ::Dynamic borderColor, ::Dynamic borderSize, ::Dynamic borderRadius) {
	RoundBorderStyle_obj *__this = (RoundBorderStyle_obj*)(::hx::Ctx::alloc(_hx_ctx, sizeof(RoundBorderStyle_obj), false, "peote.ui.style.RoundBorderStyle"));
	*(void **)__this = RoundBorderStyle_obj::_hx_vtable;
	__this->__construct(color,borderColor,borderSize,borderRadius);
	return __this;
}

RoundBorderStyle_obj::RoundBorderStyle_obj()
{
}

::hx::Val RoundBorderStyle_obj::__Field(const ::String &inName,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 2:
		if (HX_FIELD_EQ(inName,"id") ) { return ::hx::Val( id ); }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"copy") ) { return ::hx::Val( copy_dyn() ); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"color") ) { return ::hx::Val( color ); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"getUUID") ) { return ::hx::Val( getUUID_dyn() ); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"borderSize") ) { return ::hx::Val( borderSize ); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"borderColor") ) { return ::hx::Val( borderColor ); }
		if (HX_FIELD_EQ(inName,"isFontStyle") ) { return ::hx::Val( isFontStyle_dyn() ); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"borderRadius") ) { return ::hx::Val( borderRadius ); }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"createStyleProgram") ) { return ::hx::Val( createStyleProgram_dyn() ); }
	}
	return super::__Field(inName,inCallProp);
}

bool RoundBorderStyle_obj::__GetStatic(const ::String &inName, Dynamic &outValue, ::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 2:
		if (HX_FIELD_EQ(inName,"ID") ) { outValue = ( ID ); return true; }
	}
	return false;
}

::hx::Val RoundBorderStyle_obj::__SetField(const ::String &inName,const ::hx::Val &inValue,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 2:
		if (HX_FIELD_EQ(inName,"id") ) { id=inValue.Cast< int >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"color") ) { color=inValue.Cast< int >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"borderSize") ) { borderSize=inValue.Cast< Float >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"borderColor") ) { borderColor=inValue.Cast< int >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"borderRadius") ) { borderRadius=inValue.Cast< Float >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

bool RoundBorderStyle_obj::__SetStatic(const ::String &inName,Dynamic &ioValue,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 2:
		if (HX_FIELD_EQ(inName,"ID") ) { ID=ioValue.Cast< int >(); return true; }
	}
	return false;
}

void RoundBorderStyle_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_("color",63,71,5c,4a));
	outFields->push(HX_("borderColor",d7,3c,d5,d6));
	outFields->push(HX_("borderSize",cd,ff,ed,06));
	outFields->push(HX_("borderRadius",5e,0a,30,0e));
	outFields->push(HX_("id",db,5b,00,00));
	super::__GetFields(outFields);
};

#ifdef HXCPP_SCRIPTABLE
static ::hx::StorageInfo RoundBorderStyle_obj_sMemberStorageInfo[] = {
	{::hx::fsInt,(int)offsetof(RoundBorderStyle_obj,color),HX_("color",63,71,5c,4a)},
	{::hx::fsInt,(int)offsetof(RoundBorderStyle_obj,borderColor),HX_("borderColor",d7,3c,d5,d6)},
	{::hx::fsFloat,(int)offsetof(RoundBorderStyle_obj,borderSize),HX_("borderSize",cd,ff,ed,06)},
	{::hx::fsFloat,(int)offsetof(RoundBorderStyle_obj,borderRadius),HX_("borderRadius",5e,0a,30,0e)},
	{::hx::fsInt,(int)offsetof(RoundBorderStyle_obj,id),HX_("id",db,5b,00,00)},
	{ ::hx::fsUnknown, 0, null()}
};
static ::hx::StaticInfo RoundBorderStyle_obj_sStaticStorageInfo[] = {
	{::hx::fsInt,(void *) &RoundBorderStyle_obj::ID,HX_("ID",db,3f,00,00)},
	{ ::hx::fsUnknown, 0, null()}
};
#endif

static ::String RoundBorderStyle_obj_sMemberFields[] = {
	HX_("color",63,71,5c,4a),
	HX_("borderColor",d7,3c,d5,d6),
	HX_("borderSize",cd,ff,ed,06),
	HX_("borderRadius",5e,0a,30,0e),
	HX_("createStyleProgram",6f,82,21,1b),
	HX_("copy",b5,bb,c4,41),
	HX_("id",db,5b,00,00),
	HX_("getUUID",d1,65,19,20),
	HX_("isFontStyle",98,ff,79,0e),
	::String(null()) };

static void RoundBorderStyle_obj_sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(RoundBorderStyle_obj::ID,"ID");
};

#ifdef HXCPP_VISIT_ALLOCS
static void RoundBorderStyle_obj_sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(RoundBorderStyle_obj::ID,"ID");
};

#endif

::hx::Class RoundBorderStyle_obj::__mClass;

static ::String RoundBorderStyle_obj_sStaticFields[] = {
	HX_("ID",db,3f,00,00),
	::String(null())
};

void RoundBorderStyle_obj::__register()
{
	RoundBorderStyle_obj _hx_dummy;
	RoundBorderStyle_obj::_hx_vtable = *(void **)&_hx_dummy;
	::hx::Static(__mClass) = new ::hx::Class_obj();
	__mClass->mName = HX_("peote.ui.style.RoundBorderStyle",6b,fe,7c,56);
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mConstructEmpty = &__CreateEmpty;
	__mClass->mConstructArgs = &__Create;
	__mClass->mGetStaticField = &RoundBorderStyle_obj::__GetStatic;
	__mClass->mSetStaticField = &RoundBorderStyle_obj::__SetStatic;
	__mClass->mMarkFunc = RoundBorderStyle_obj_sMarkStatics;
	__mClass->mStatics = ::hx::Class_obj::dupFunctions(RoundBorderStyle_obj_sStaticFields);
	__mClass->mMembers = ::hx::Class_obj::dupFunctions(RoundBorderStyle_obj_sMemberFields);
	__mClass->mCanCast = ::hx::TCanCast< RoundBorderStyle_obj >;
#ifdef HXCPP_VISIT_ALLOCS
	__mClass->mVisitFunc = RoundBorderStyle_obj_sVisitStatics;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mMemberStorageInfo = RoundBorderStyle_obj_sMemberStorageInfo;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mStaticStorageInfo = RoundBorderStyle_obj_sStaticStorageInfo;
#endif
	::hx::_hx_RegisterClass(__mClass->mName, __mClass);
}

void RoundBorderStyle_obj::__boot()
{
{
            	HX_STACKFRAME(&_hx_pos_eb27d20284f429e0_179_boot)
HXDLIN( 179)		ID = 2048;
            	}
}

} // end namespace peote
} // end namespace ui
} // end namespace style
