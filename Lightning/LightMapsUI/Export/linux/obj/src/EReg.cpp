// Generated by Haxe 5.0.0-alpha.1+2f4b99d
#include <hxcpp.h>

#ifndef INCLUDED_EReg
#include <EReg.h>
#endif
#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_StringBuf
#include <StringBuf.h>
#endif
#ifndef INCLUDED_haxe_Exception
#include <haxe/Exception.h>
#endif
#ifndef INCLUDED_haxe_ValueException
#include <haxe/ValueException.h>
#endif

HX_DEFINE_STACK_FRAME(_hx_pos_0f9ac110bd093a4e_28_new,"EReg","new",0x8b859e81,"EReg.new","/usr/share/haxe/std/cpp/_std/EReg.hx",28,0x3bcaa0cb)
HX_LOCAL_STACK_FRAME(_hx_pos_0f9ac110bd093a4e_36_match,"EReg","match",0x18fda1a6,"EReg.match","/usr/share/haxe/std/cpp/_std/EReg.hx",36,0x3bcaa0cb)
HX_LOCAL_STACK_FRAME(_hx_pos_0f9ac110bd093a4e_45_matched,"EReg","matched",0x8ce62f85,"EReg.matched","/usr/share/haxe/std/cpp/_std/EReg.hx",45,0x3bcaa0cb)
HX_LOCAL_STACK_FRAME(_hx_pos_0f9ac110bd093a4e_55_matchedRight,"EReg","matchedRight",0x6157ea17,"EReg.matchedRight","/usr/share/haxe/std/cpp/_std/EReg.hx",55,0x3bcaa0cb)
HX_LOCAL_STACK_FRAME(_hx_pos_0f9ac110bd093a4e_62_matchedPos,"EReg","matchedPos",0x7007a70f,"EReg.matchedPos","/usr/share/haxe/std/cpp/_std/EReg.hx",62,0x3bcaa0cb)
HX_LOCAL_STACK_FRAME(_hx_pos_0f9ac110bd093a4e_98_replace,"EReg","replace",0xae923ad5,"EReg.replace","/usr/share/haxe/std/cpp/_std/EReg.hx",98,0x3bcaa0cb)
static const ::String _hx_array_data_2dda4a0f_8[] = {
	HX_("$",24,00,00,00),
};
static const ::String _hx_array_data_2dda4a0f_9[] = {
	HX_("$",24,00,00,00),
};

void EReg_obj::__construct(::String r,::String opt){
            	HX_STACKFRAME(&_hx_pos_0f9ac110bd093a4e_28_new)
HXLINE(  29)		::Array< ::String > a = opt.split(HX_("g",67,00,00,00));
HXLINE(  30)		this->global = (a->length > 1);
HXLINE(  31)		if (this->global) {
HXLINE(  32)			opt = a->join(HX_("",00,00,00,00));
            		}
HXLINE(  33)		this->r = _hx_regexp_new_options(r,opt);
            	}

Dynamic EReg_obj::__CreateEmpty() { return new EReg_obj; }

void *EReg_obj::_hx_vtable = 0;

Dynamic EReg_obj::__Create(::hx::DynamicArray inArgs)
{
	::hx::ObjectPtr< EReg_obj > _hx_result = new EReg_obj();
	_hx_result->__construct(inArgs[0],inArgs[1]);
	return _hx_result;
}

bool EReg_obj::_hx_isInstanceOf(int inClassId) {
	return inClassId==(int)0x00000001 || inClassId==(int)0x022d4033;
}

bool EReg_obj::match(::String s){
            	HX_STACKFRAME(&_hx_pos_0f9ac110bd093a4e_36_match)
HXLINE(  37)		bool p = _hx_regexp_match(this->r,s,0,s.length);
HXLINE(  38)		if (p) {
HXLINE(  39)			this->last = s;
            		}
            		else {
HXLINE(  41)			this->last = null();
            		}
HXLINE(  42)		return p;
            	}


HX_DEFINE_DYNAMIC_FUNC1(EReg_obj,match,return )

::String EReg_obj::matched(int n){
            	HX_STACKFRAME(&_hx_pos_0f9ac110bd093a4e_45_matched)
HXLINE(  46)		::String m = _hx_regexp_matched(this->r,n);
HXLINE(  47)		return m;
            	}


HX_DEFINE_DYNAMIC_FUNC1(EReg_obj,matched,return )

::String EReg_obj::matchedRight(){
            	HX_STACKFRAME(&_hx_pos_0f9ac110bd093a4e_55_matchedRight)
HXLINE(  56)		 ::Dynamic p = _hx_regexp_matched_pos(this->r,0);
HXLINE(  57)		int sz = ( (int)((p->__Field(HX_("pos",94,5d,55,00),::hx::paccDynamic) + p->__Field(HX_("len",d5,4b,52,00),::hx::paccDynamic))) );
HXLINE(  58)		return this->last.substr(sz,(this->last.length - sz));
            	}


HX_DEFINE_DYNAMIC_FUNC0(EReg_obj,matchedRight,return )

 ::Dynamic EReg_obj::matchedPos(){
            	HX_STACKFRAME(&_hx_pos_0f9ac110bd093a4e_62_matchedPos)
HXDLIN(  62)		return _hx_regexp_matched_pos(this->r,0);
            	}


HX_DEFINE_DYNAMIC_FUNC0(EReg_obj,matchedPos,return )

::String EReg_obj::replace(::String s,::String by){
            	HX_GC_STACKFRAME(&_hx_pos_0f9ac110bd093a4e_98_replace)
HXLINE(  99)		 ::StringBuf b =  ::StringBuf_obj::__alloc( HX_CTX );
HXLINE( 100)		int pos = 0;
HXLINE( 101)		int len = s.length;
HXLINE( 102)		::Array< ::String > a = by.split(HX_("$",24,00,00,00));
HXLINE( 103)		bool first = true;
HXLINE( 104)		while(_hx_regexp_match(this->r,s,pos,len)){
HXLINE( 107)			 ::Dynamic p = _hx_regexp_matched_pos(this->r,0);
HXLINE( 108)			bool _hx_tmp;
HXDLIN( 108)			if (::hx::IsEq( p->__Field(HX_("len",d5,4b,52,00),::hx::paccDynamic),0 )) {
HXLINE( 108)				_hx_tmp = !(first);
            			}
            			else {
HXLINE( 108)				_hx_tmp = false;
            			}
HXDLIN( 108)			if (_hx_tmp) {
HXLINE( 109)				if (::hx::IsEq( p->__Field(HX_("pos",94,5d,55,00),::hx::paccDynamic),s.length )) {
HXLINE( 110)					goto _hx_goto_5;
            				}
HXLINE( 111)				 ::Dynamic p1 = p;
HXDLIN( 111)				p1->__SetField(HX_("pos",94,5d,55,00),(p1->__Field(HX_("pos",94,5d,55,00),::hx::paccDynamic) + 1),::hx::paccDynamic);
            			}
HXLINE( 113)			{
HXLINE( 113)				 ::Dynamic len1 = (( (int)(p->__Field(HX_("pos",94,5d,55,00),::hx::paccDynamic)) ) - pos);
HXDLIN( 113)				if (::hx::IsNotNull( b->charBuf )) {
HXLINE( 113)					b->flush();
            				}
HXDLIN( 113)				if (::hx::IsNull( b->b )) {
HXLINE( 113)					b->b = ::Array_obj< ::String >::__new(1)->init(0,s.substr(pos,len1));
            				}
            				else {
HXLINE( 113)					::Array< ::String > b1 = b->b;
HXDLIN( 113)					b1->push(s.substr(pos,len1));
            				}
            			}
HXLINE( 114)			if ((a->length > 0)) {
HXLINE( 115)				::String x = a->__get(0);
HXDLIN( 115)				if (::hx::IsNotNull( b->charBuf )) {
HXLINE( 115)					b->flush();
            				}
HXDLIN( 115)				if (::hx::IsNull( b->b )) {
HXLINE( 115)					b->b = ::Array_obj< ::String >::__new(1)->init(0,::Std_obj::string(x));
            				}
            				else {
HXLINE( 115)					::Array< ::String > b2 = b->b;
HXDLIN( 115)					b2->push(::Std_obj::string(x));
            				}
            			}
HXLINE( 116)			int i = 1;
HXLINE( 117)			while((i < a->length)){
HXLINE( 118)				::String k = a->__get(i);
HXLINE( 119)				 ::Dynamic c = k.charCodeAt(0);
HXLINE( 121)				bool _hx_tmp1;
HXDLIN( 121)				if (::hx::IsGreaterEq( c,49 )) {
HXLINE( 121)					_hx_tmp1 = ::hx::IsLessEq( c,57 );
            				}
            				else {
HXLINE( 121)					_hx_tmp1 = false;
            				}
HXDLIN( 121)				if (_hx_tmp1) {
HXLINE( 122)					 ::Dynamic p2;
HXDLIN( 122)					try {
            						HX_STACK_CATCHABLE(::String, 0);
            						HX_STACK_CATCHABLE( ::haxe::ValueException, 1);
HXLINE( 122)						 ::Dynamic p3 = this->r;
HXDLIN( 122)						p2 = _hx_regexp_matched_pos(p3,(::Std_obj::_hx_int(( (Float)(c) )) - 48));
            					} catch( ::Dynamic _hx_e) {
            						if (_hx_e.IsClass< ::String >() && _hx_e->toString()!=null() ){
            							HX_STACK_BEGIN_CATCH
            							::String e = _hx_e;
HXLINE( 122)							p2 = null();
            						}
            						else if (_hx_e.IsClass<  ::haxe::ValueException >() ){
            							HX_STACK_BEGIN_CATCH
            							 ::haxe::ValueException _g = _hx_e;
HXLINE( 122)							{
HXLINE( 122)								null();
            							}
HXDLIN( 122)							if (::Std_obj::isOfType(_g->value,::hx::ClassOf< ::String >())) {
HXLINE( 122)								p2 = null();
            							}
            							else {
HXLINE( 122)								HX_STACK_DO_THROW(_g);
            							}
            						}
            						else {
            							HX_STACK_DO_THROW(_hx_e);
            						}
            					}
HXLINE( 123)					if (::hx::IsNull( p2 )) {
HXLINE( 124)						{
HXLINE( 124)							if (::hx::IsNotNull( b->charBuf )) {
HXLINE( 124)								b->flush();
            							}
HXDLIN( 124)							if (::hx::IsNull( b->b )) {
HXLINE( 124)								b->b = ::Array_obj< ::String >::fromData( _hx_array_data_2dda4a0f_8,1);
            							}
            							else {
HXLINE( 124)								b->b->push(HX_("$",24,00,00,00));
            							}
            						}
HXLINE( 125)						{
HXLINE( 125)							if (::hx::IsNotNull( b->charBuf )) {
HXLINE( 125)								b->flush();
            							}
HXDLIN( 125)							if (::hx::IsNull( b->b )) {
HXLINE( 125)								b->b = ::Array_obj< ::String >::__new(1)->init(0,::Std_obj::string(k));
            							}
            							else {
HXLINE( 125)								::Array< ::String > b3 = b->b;
HXDLIN( 125)								b3->push(::Std_obj::string(k));
            							}
            						}
            					}
            					else {
HXLINE( 127)						{
HXLINE( 127)							int pos1 = ( (int)(p2->__Field(HX_("pos",94,5d,55,00),::hx::paccDynamic)) );
HXDLIN( 127)							 ::Dynamic len2 = p2->__Field(HX_("len",d5,4b,52,00),::hx::paccDynamic);
HXDLIN( 127)							if (::hx::IsNotNull( b->charBuf )) {
HXLINE( 127)								b->flush();
            							}
HXDLIN( 127)							if (::hx::IsNull( b->b )) {
HXLINE( 127)								b->b = ::Array_obj< ::String >::__new(1)->init(0,s.substr(pos1,len2));
            							}
            							else {
HXLINE( 127)								::Array< ::String > b4 = b->b;
HXDLIN( 127)								b4->push(s.substr(pos1,len2));
            							}
            						}
HXLINE( 128)						{
HXLINE( 128)							 ::Dynamic len3 = (k.length - 1);
HXDLIN( 128)							if (::hx::IsNotNull( b->charBuf )) {
HXLINE( 128)								b->flush();
            							}
HXDLIN( 128)							if (::hx::IsNull( b->b )) {
HXLINE( 128)								b->b = ::Array_obj< ::String >::__new(1)->init(0,k.substr(1,len3));
            							}
            							else {
HXLINE( 128)								::Array< ::String > b5 = b->b;
HXDLIN( 128)								b5->push(k.substr(1,len3));
            							}
            						}
            					}
            				}
            				else {
HXLINE( 130)					if (::hx::IsNull( c )) {
HXLINE( 131)						{
HXLINE( 131)							if (::hx::IsNotNull( b->charBuf )) {
HXLINE( 131)								b->flush();
            							}
HXDLIN( 131)							if (::hx::IsNull( b->b )) {
HXLINE( 131)								b->b = ::Array_obj< ::String >::fromData( _hx_array_data_2dda4a0f_9,1);
            							}
            							else {
HXLINE( 131)								b->b->push(HX_("$",24,00,00,00));
            							}
            						}
HXLINE( 132)						i = (i + 1);
HXLINE( 133)						::String k2 = a->__get(i);
HXLINE( 134)						bool _hx_tmp2;
HXDLIN( 134)						if (::hx::IsNotNull( k2 )) {
HXLINE( 134)							_hx_tmp2 = (k2.length > 0);
            						}
            						else {
HXLINE( 134)							_hx_tmp2 = false;
            						}
HXDLIN( 134)						if (_hx_tmp2) {
HXLINE( 135)							if (::hx::IsNotNull( b->charBuf )) {
HXLINE( 135)								b->flush();
            							}
HXDLIN( 135)							if (::hx::IsNull( b->b )) {
HXLINE( 135)								b->b = ::Array_obj< ::String >::__new(1)->init(0,::Std_obj::string(k2));
            							}
            							else {
HXLINE( 135)								::Array< ::String > b6 = b->b;
HXDLIN( 135)								b6->push(::Std_obj::string(k2));
            							}
            						}
            					}
            					else {
HXLINE( 137)						::String x1 = (HX_("$",24,00,00,00) + k);
HXDLIN( 137)						if (::hx::IsNotNull( b->charBuf )) {
HXLINE( 137)							b->flush();
            						}
HXDLIN( 137)						if (::hx::IsNull( b->b )) {
HXLINE( 137)							b->b = ::Array_obj< ::String >::__new(1)->init(0,::Std_obj::string(x1));
            						}
            						else {
HXLINE( 137)							::Array< ::String > b7 = b->b;
HXDLIN( 137)							b7->push(::Std_obj::string(x1));
            						}
            					}
            				}
HXLINE( 138)				i = (i + 1);
            			}
HXLINE( 140)			int tot = (( (int)((p->__Field(HX_("pos",94,5d,55,00),::hx::paccDynamic) + p->__Field(HX_("len",d5,4b,52,00),::hx::paccDynamic))) ) - pos);
HXLINE( 141)			pos = (pos + tot);
HXLINE( 142)			len = (len - tot);
HXLINE( 143)			first = false;
HXLINE( 104)			if (!(this->global)) {
HXLINE( 104)				goto _hx_goto_5;
            			}
            		}
            		_hx_goto_5:;
HXLINE( 145)		{
HXLINE( 145)			if (::hx::IsNotNull( b->charBuf )) {
HXLINE( 145)				b->flush();
            			}
HXDLIN( 145)			if (::hx::IsNull( b->b )) {
HXLINE( 145)				b->b = ::Array_obj< ::String >::__new(1)->init(0,s.substr(pos,len));
            			}
            			else {
HXLINE( 145)				::Array< ::String > b8 = b->b;
HXDLIN( 145)				b8->push(s.substr(pos,len));
            			}
            		}
HXLINE( 146)		return b->toString();
            	}


HX_DEFINE_DYNAMIC_FUNC2(EReg_obj,replace,return )


::hx::ObjectPtr< EReg_obj > EReg_obj::__new(::String r,::String opt) {
	::hx::ObjectPtr< EReg_obj > __this = new EReg_obj();
	__this->__construct(r,opt);
	return __this;
}

::hx::ObjectPtr< EReg_obj > EReg_obj::__alloc(::hx::Ctx *_hx_ctx,::String r,::String opt) {
	EReg_obj *__this = (EReg_obj*)(::hx::Ctx::alloc(_hx_ctx, sizeof(EReg_obj), true, "EReg"));
	*(void **)__this = EReg_obj::_hx_vtable;
	__this->__construct(r,opt);
	return __this;
}

EReg_obj::EReg_obj()
{
}

void EReg_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(EReg);
	HX_MARK_MEMBER_NAME(r,"r");
	HX_MARK_MEMBER_NAME(last,"last");
	HX_MARK_MEMBER_NAME(global,"global");
	HX_MARK_END_CLASS();
}

void EReg_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(r,"r");
	HX_VISIT_MEMBER_NAME(last,"last");
	HX_VISIT_MEMBER_NAME(global,"global");
}

::hx::Val EReg_obj::__Field(const ::String &inName,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 1:
		if (HX_FIELD_EQ(inName,"r") ) { return ::hx::Val( r ); }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"last") ) { return ::hx::Val( last ); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"match") ) { return ::hx::Val( match_dyn() ); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"global") ) { return ::hx::Val( global ); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"matched") ) { return ::hx::Val( matched_dyn() ); }
		if (HX_FIELD_EQ(inName,"replace") ) { return ::hx::Val( replace_dyn() ); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"matchedPos") ) { return ::hx::Val( matchedPos_dyn() ); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"matchedRight") ) { return ::hx::Val( matchedRight_dyn() ); }
	}
	return super::__Field(inName,inCallProp);
}

::hx::Val EReg_obj::__SetField(const ::String &inName,const ::hx::Val &inValue,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 1:
		if (HX_FIELD_EQ(inName,"r") ) { r=inValue.Cast<  ::Dynamic >(); return inValue; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"last") ) { last=inValue.Cast< ::String >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"global") ) { global=inValue.Cast< bool >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void EReg_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_("r",72,00,00,00));
	outFields->push(HX_("last",56,0a,ad,47));
	outFields->push(HX_("global",63,31,b2,a7));
	super::__GetFields(outFields);
};

#ifdef HXCPP_SCRIPTABLE
static ::hx::StorageInfo EReg_obj_sMemberStorageInfo[] = {
	{::hx::fsObject /*  ::Dynamic */ ,(int)offsetof(EReg_obj,r),HX_("r",72,00,00,00)},
	{::hx::fsString,(int)offsetof(EReg_obj,last),HX_("last",56,0a,ad,47)},
	{::hx::fsBool,(int)offsetof(EReg_obj,global),HX_("global",63,31,b2,a7)},
	{ ::hx::fsUnknown, 0, null()}
};
static ::hx::StaticInfo *EReg_obj_sStaticStorageInfo = 0;
#endif

static ::String EReg_obj_sMemberFields[] = {
	HX_("r",72,00,00,00),
	HX_("last",56,0a,ad,47),
	HX_("global",63,31,b2,a7),
	HX_("match",45,49,23,03),
	HX_("matched",e4,3c,7c,89),
	HX_("matchedRight",58,04,9a,a4),
	HX_("matchedPos",10,ff,c2,cb),
	HX_("replace",34,48,28,ab),
	::String(null()) };

::hx::Class EReg_obj::__mClass;

void EReg_obj::__register()
{
	EReg_obj _hx_dummy;
	EReg_obj::_hx_vtable = *(void **)&_hx_dummy;
	::hx::Static(__mClass) = new ::hx::Class_obj();
	__mClass->mName = HX_("EReg",0f,4a,da,2d);
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mConstructEmpty = &__CreateEmpty;
	__mClass->mConstructArgs = &__Create;
	__mClass->mGetStaticField = &::hx::Class_obj::GetNoStaticField;
	__mClass->mSetStaticField = &::hx::Class_obj::SetNoStaticField;
	__mClass->mStatics = ::hx::Class_obj::dupFunctions(0 /* sStaticFields */);
	__mClass->mMembers = ::hx::Class_obj::dupFunctions(EReg_obj_sMemberFields);
	__mClass->mCanCast = ::hx::TCanCast< EReg_obj >;
#ifdef HXCPP_SCRIPTABLE
	__mClass->mMemberStorageInfo = EReg_obj_sMemberStorageInfo;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mStaticStorageInfo = EReg_obj_sStaticStorageInfo;
#endif
	::hx::_hx_RegisterClass(__mClass->mName, __mClass);
}

