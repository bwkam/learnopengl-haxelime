// Generated by Haxe 5.0.0-alpha.1+2f4b99d
#ifndef INCLUDED_peote_ui_style_interfaces_StyleProgram
#define INCLUDED_peote_ui_style_interfaces_StyleProgram

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(peote,ui,config,Space)
HX_DECLARE_CLASS3(peote,ui,interactive,Interactive)
HX_DECLARE_CLASS4(peote,ui,style,interfaces,StyleElement)
HX_DECLARE_CLASS4(peote,ui,style,interfaces,StyleProgram)

namespace peote{
namespace ui{
namespace style{
namespace interfaces{


class HXCPP_CLASS_ATTRIBUTES StyleProgram_obj {
	public:
		typedef ::hx::Object super;
		HX_DO_INTERFACE_RTTI;

		::Dynamic (::hx::Object :: *_hx_createElement)( ::peote::ui::interactive::Interactive uiElement, ::Dynamic style, ::peote::ui::config::Space space); 
		static inline ::Dynamic createElement( ::Dynamic _hx_, ::peote::ui::interactive::Interactive uiElement, ::Dynamic style, ::peote::ui::config::Space space) {
			return (_hx_.mPtr->*( ::hx::interface_cast< ::peote::ui::style::interfaces::StyleProgram_obj *>(_hx_.mPtr->_hx_getInterface(0x8679ac7f)))->_hx_createElement)(uiElement,style,space);
		}
		void (::hx::Object :: *_hx_addElement)(::Dynamic styleElement); 
		static inline void addElement( ::Dynamic _hx_,::Dynamic styleElement) {
			(_hx_.mPtr->*( ::hx::interface_cast< ::peote::ui::style::interfaces::StyleProgram_obj *>(_hx_.mPtr->_hx_getInterface(0x8679ac7f)))->_hx_addElement)(styleElement);
		}
		void (::hx::Object :: *_hx_removeElement)(::Dynamic styleElement); 
		static inline void removeElement( ::Dynamic _hx_,::Dynamic styleElement) {
			(_hx_.mPtr->*( ::hx::interface_cast< ::peote::ui::style::interfaces::StyleProgram_obj *>(_hx_.mPtr->_hx_getInterface(0x8679ac7f)))->_hx_removeElement)(styleElement);
		}
		void (::hx::Object :: *_hx_update)(::Dynamic styleElement); 
		static inline void update( ::Dynamic _hx_,::Dynamic styleElement) {
			(_hx_.mPtr->*( ::hx::interface_cast< ::peote::ui::style::interfaces::StyleProgram_obj *>(_hx_.mPtr->_hx_getInterface(0x8679ac7f)))->_hx_update)(styleElement);
		}
};

} // end namespace peote
} // end namespace ui
} // end namespace style
} // end namespace interfaces

#endif /* INCLUDED_peote_ui_style_interfaces_StyleProgram */ 
