// Generated by Haxe 5.0.0-alpha.1+2f4b99d
#ifndef INCLUDED_input2action__InputState_KeyCombo
#define INCLUDED_input2action__InputState_KeyCombo

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS1(input2action,ActionState)
HX_DECLARE_CLASS2(input2action,_InputState,KeyCombo)

namespace input2action{
namespace _InputState{


class HXCPP_CLASS_ATTRIBUTES KeyCombo_obj : public ::hx::Object
{
	public:
		typedef ::hx::Object super;
		typedef KeyCombo_obj OBJ_;
		KeyCombo_obj();

	public:
		enum { _hx_ClassId = 0x3c3f3717 };

		void __construct(int keyCode, ::input2action::ActionState actionState,::hx::Null< int >  __o_deviceID);
		inline void *operator new(size_t inSize, bool inContainer=true,const char *inName="input2action._InputState.KeyCombo")
			{ return ::hx::Object::operator new(inSize,inContainer,inName); }
		inline void *operator new(size_t inSize, int extra)
			{ return ::hx::Object::operator new(inSize+extra,true,"input2action._InputState.KeyCombo"); }
		static ::hx::ObjectPtr< KeyCombo_obj > __new(int keyCode, ::input2action::ActionState actionState,::hx::Null< int >  __o_deviceID);
		static ::hx::ObjectPtr< KeyCombo_obj > __alloc(::hx::Ctx *_hx_ctx,int keyCode, ::input2action::ActionState actionState,::hx::Null< int >  __o_deviceID);
		static void * _hx_vtable;
		static Dynamic __CreateEmpty();
		static Dynamic __Create(::hx::DynamicArray inArgs);
		//~KeyCombo_obj();

		HX_DO_RTTI_ALL;
		::hx::Val __Field(const ::String &inString, ::hx::PropertyAccess inCallProp);
		::hx::Val __SetField(const ::String &inString,const ::hx::Val &inValue, ::hx::PropertyAccess inCallProp);
		void __GetFields(Array< ::String> &outFields);
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		bool _hx_isInstanceOf(int inClassId);
		::String __ToString() const { return HX_("KeyCombo",4f,8a,78,68); }

		int keyCode;
		int deviceID;
		 ::input2action::ActionState actionState;
};

} // end namespace input2action
} // end namespace _InputState

#endif /* INCLUDED_input2action__InputState_KeyCombo */ 
