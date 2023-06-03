// Generated by Haxe 5.0.0-alpha.1+2f4b99d
#ifndef INCLUDED_Camera
#define INCLUDED_Camera

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS0(Camera)
HX_DECLARE_CLASS2(lime,math,Vector4)



class HXCPP_CLASS_ATTRIBUTES Camera_obj : public ::hx::Object
{
	public:
		typedef ::hx::Object super;
		typedef Camera_obj OBJ_;
		Camera_obj();

	public:
		enum { _hx_ClassId = 0x4d6b7d85 };

		void __construct();
		inline void *operator new(size_t inSize, bool inContainer=false,const char *inName="Camera")
			{ return ::hx::Object::operator new(inSize,inContainer,inName); }
		inline void *operator new(size_t inSize, int extra)
			{ return ::hx::Object::operator new(inSize+extra,false,"Camera"); }

		inline static ::hx::ObjectPtr< Camera_obj > __new() {
			::hx::ObjectPtr< Camera_obj > __this = new Camera_obj();
			__this->__construct();
			return __this;
		}

		inline static ::hx::ObjectPtr< Camera_obj > __alloc(::hx::Ctx *_hx_ctx) {
			Camera_obj *__this = (Camera_obj*)(::hx::Ctx::alloc(_hx_ctx, sizeof(Camera_obj), false, "Camera"));
			*(void **)__this = Camera_obj::_hx_vtable;
			return __this;
		}

		static void * _hx_vtable;
		static Dynamic __CreateEmpty();
		static Dynamic __Create(::hx::DynamicArray inArgs);
		//~Camera_obj();

		HX_DO_RTTI_ALL;
		static bool __GetStatic(const ::String &inString, Dynamic &outValue, ::hx::PropertyAccess inCallProp);
		static bool __SetStatic(const ::String &inString, Dynamic &ioValue, ::hx::PropertyAccess inCallProp);
		static void __register();
		bool _hx_isInstanceOf(int inClassId);
		::String __ToString() const { return HX_("Camera",c5,ba,20,ec); }

		static void __boot();
		static bool moveLeft;
		static bool moveRight;
		static bool moveForward;
		static bool moveBackward;
		static int speed;
		static bool firstMouse;
		static Float lastX;
		static Float lastY;
		static Float xOffset;
		static Float yOffset;
		static Float sensitivity;
		static Float yaw;
		static Float pitch;
		static Float fov;
		static  ::lime::math::Vector4 pos;
		static  ::lime::math::Vector4 front;
		static  ::lime::math::Vector4 up;
		static void init();
		static ::Dynamic init_dyn();

		static void moveCamera(Float delta);
		static ::Dynamic moveCamera_dyn();

		static void onMouseMove(Float x,Float y);
		static ::Dynamic onMouseMove_dyn();

};


#endif /* INCLUDED_Camera */ 
