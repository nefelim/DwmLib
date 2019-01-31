#pragma once
#include <comdef.h>
#include <dwmapi.h>
#pragma comment(lib, "Dwmapi.lib")

#define CHECK_HRESULT(hr) if (!SUCCEEDED(hr)) throw _com_error(hr);
#define DECLARE_GET_FUNCTION(N, I, T) T N() const {T res = T(); CHECK_HRESULT(GetWindowAttribute(I, res)); return res;}
#define DECLARE_SET_FUNCTION(N, I, T) void N(const T& param) const {CHECK_HRESULT(SetWindowAttribute(I, param));}

namespace dwm
{
    /**
    * @addtogroup dwm
    * @class WindowAttributes DwmWindowAttributes.h
    * @brief Retrieves or set the values of a specified attributes applied to a window.
    * @details Retrieves or set the values of a specified attributes applied to a window. 
    */

    class WindowAttributes
    {
    public:
        WindowAttributes(HWND hWnd)
            : m_hWnd(hWnd)
        {
        }

        /**
        * @brief Discovers whether non-client rendering is enabled.
        * @return The retrieved value is of type BOOL. TRUE if non-client rendering is enabled; otherwise, FALSE.
        */
        DECLARE_GET_FUNCTION(GetNcRenderingEnabled,         DWMWA_NCRENDERING_ENABLED,          BOOL)
        /**
        * @brief Sets the non-client rendering policy.
        * @param param The parameter refers to a value from the DWMNCRENDERINGPOLICY enumeration
        */
        DECLARE_SET_FUNCTION(SetNcRenderingPolicy,          DWMWA_NCRENDERING_POLICY,           DWMNCRENDERINGPOLICY)
        /**
        * @brief Enables or forcibly disables DWM transitions.
        * @param param The parameter refers to a value of TRUE to disable transitions or FALSE to enable transitions.
        */
        DECLARE_SET_FUNCTION(SetTransitionsForceDisabled,   DWMWA_TRANSITIONS_FORCEDISABLED,    BOOL)
        /**
        * @brief Enables content rendered in the non-client area to be visible on the frame drawn by DWM.
        * @param param The parameter refers to a value of TRUE to enable content rendered in the non-client area to be visible on the frame; otherwise, it points to FALSE.
        */
        DECLARE_SET_FUNCTION(SetAllowNcPaint,               DWMWA_ALLOW_NCPAINT,                BOOL)
        /**
        * @brief Retrieves the bounds of the caption button area in the window-relative space.
        * @return The retrieved value is of type RECT.
        */
        DECLARE_GET_FUNCTION(GetCaptionButtonBounds,        DWMWA_CAPTION_BUTTON_BOUNDS,        RECT)
        /**
        * @brief Specifies whether non-client content is right-to-left (RTL) mirrored.
        * @param param The parameter refers to a value of TRUE if the non-client content is right-to-left (RTL) mirrored; otherwise, it points to FALSE.
        */
        DECLARE_SET_FUNCTION(SetNonClientRtlLayout,         DWMWA_NONCLIENT_RTL_LAYOUT,         BOOL)
        /**
        * @brief Forces the window to display an iconic thumbnail or peek representation (a static bitmap),
        * even if a live or snapshot representation of the window is available. This value normally is set
        * during a window's creation and not changed throughout the window's lifetime. Some scenarios, however,
        * might require the value to change over time.
        * @param param The parameter refers to a value of TRUE to require a iconic thumbnail or peek representation; otherwise, it points to FALSE.
        */
        DECLARE_SET_FUNCTION(SetForceIconicRepresentation,  DWMWA_FORCE_ICONIC_REPRESENTATION,  BOOL)
        /**
        * @brief Sets how Flip3D treats the window.
        * @param param The parameter refers to a value from the DWMFLIP3DWINDOWPOLICY enumeration
        */
        DECLARE_SET_FUNCTION(SetFlip3dPolicy,               DWMWA_FLIP3D_POLICY,                DWMFLIP3DWINDOWPOLICY)
        /**
        * @brief Retrieves the extended frame bounds rectangle in screen space.
        * @return The retrieved value is of type RECT.
        */
        DECLARE_GET_FUNCTION(GetExtendedFrameBounds,        DWMWA_EXTENDED_FRAME_BOUNDS,        RECT)
        /**
        * @brief The window will provide a bitmap for use by DWM as an iconic thumbnail or peek representation
        * (a static bitmap) for the window. DWMWA_HAS_ICONIC_BITMAP can be specified with DWMWA_FORCE_ICONIC_REPRESENTATION.
        * DWMWA_HAS_ICONIC_BITMAP normally is set during a window's creation and not changed throughout the window's lifetime.
        * Some scenarios, however, might require the value to change over time.
        * @note Windows Vista and earlier: This value is not supported.
        * @param param The pvAttribute parameter refers to a value of TRUE to inform DWM that the window will provide an iconic thumbnail or peek representation;
        * otherwise, it points to FALSE.
        */
        DECLARE_SET_FUNCTION(SetHasIconicBitmap,            DWMWA_HAS_ICONIC_BITMAP,            BOOL)
        /**
        * @brief Do not show peek preview for the window. The peek view shows a full-sized preview of the window when the mouse
        * hovers over the window's thumbnail in the taskbar. If this attribute is set, hovering the mouse pointer over the window's
        * thumbnail dismisses peek (in case another window in the group has a peek preview showing).
        * @note Windows Vista and earlier: This value is not supported.
        * @param param The parameter refers to a value of TRUE to prevent peek functionality or FALSE to allow it.
        */
        DECLARE_SET_FUNCTION(SetDisallowPeek,               DWMWA_DISALLOW_PEEK,                BOOL)
        /**
        * @brief Prevents a window from fading to a glass sheet when peek is invoked.
        * @note Windows Vista and earlier: This value is not supported.
        * @param param The parameter refers to a value of TRUE to prevent the window from fading during another window's peek or FALSE for normal behavior.
        */
        DECLARE_SET_FUNCTION(SetExcludedFromPeek,           DWMWA_EXCLUDED_FROM_PEEK,           BOOL)
        /**
        * @brief Cloaks the window such that it is not visible to the user. The window is still composed by DWM.
        * @details Using with DirectComposition: Use the DWMWA_CLOAK flag to cloak the layered child window when
        * animating a representation of the window's content via a DirectComposition visual which has been associated with the layered child window.
        * For more details on this usage case, see How to <a href="https://docs.microsoft.com/uk-ua/windows/desktop/directcomp/how-to--animate-the-bitmap-of-a-layered-child-window">How to animate the bitmap of a layered child window.</a>
        * @note Windows 7 and earlier:  This value is not supported.
        * @param param The parameter refers to a value of TRUE to prevent the window from fading during another window's peek or FALSE for normal behavior.
        */
        DECLARE_SET_FUNCTION(SetCloak,                      DWMWA_CLOAK,                        DWORD)
        /**
        * @brief If the window is cloaked, provides one of the following values explaining why:
        * @note Windows Vista and earlier: This value is not supported.
        * @param param The pvAttribute parameter refers to a value of TRUE to inform DWM that the window will provide an iconic thumbnail or peek representation;
        * otherwise, it points to FALSE.
        * @note Windows 7 and earlier:  This value is not supported.
        */
        DECLARE_GET_FUNCTION(GetCloaked,                    DWMWA_CLOAKED,                      DWORD)
        /**
        * @brief Freeze the window's thumbnail image with its current visuals. Do no further live updates on the thumbnail image to match the window's contents.
        * @note Windows 7 and earlier: This value is not supported.
        * @param param The parameter refers to a value of TRUE to freeze representation the window FALSE for normal behavior.
        */
        DECLARE_SET_FUNCTION(SetFreezeRepresentation,       DWMWA_FREEZE_REPRESENTATION,        BOOL)

    private:
        template <typename T>
        HRESULT GetWindowAttribute(DWMWINDOWATTRIBUTE attr, T& param) const
        {
            return DwmGetWindowAttribute(m_hWnd, attr, &param, sizeof(param));
        }

        template <typename T>
        HRESULT SetWindowAttribute(DWMWINDOWATTRIBUTE attr, const T& param) const
        {
            return DwmSetWindowAttribute(m_hWnd, attr, &param, sizeof(param));
        }
    private:
        HWND m_hWnd;
    };
}

