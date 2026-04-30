#pragma once
#include <string>
#include <functional>

enum class PAPI {
    SDL,
    GLFW
};

class IWindowManager {
public:
    using KeyCallbackFn = std::function<void(int key, int action)>;
    using MouseBtnCallbackFn = std::function<void(int button, int action)>;
    using CursorPosCallbackFn = std::function<void(double xpos, double ypos)>;

    virtual ~IWindowManager() = default;

    virtual int CreateWindow(int width, int height, const std::string& title) = 0;
    virtual void DestroyWindow(int windowID) = 0;
    virtual void PollEvents() = 0;
    virtual void SwapBuffers(int windowID) = 0;
    virtual bool IsWindowOpen(int windowID) = 0;
    virtual void SetWindowSize(int windowID, int width, int height) = 0;
    virtual void SetWindowPos(int windowID, int xpos, int ypos) = 0;
    virtual void GetWindowPos(int windowID, int& xpos, int& ypos) = 0;
    virtual int  GetWindowAttrib(int windowID, int attrib) = 0;
    virtual void RestoreWindow(int windowID) = 0;
    virtual void MaximizeWindow(int windowID) = 0;
    virtual void SetErrorCallback() = 0;
    virtual void WindowHint(int hint, int value) = 0;
    virtual void* GetPrimaryMonitor() = 0;
    virtual void GetVideoMode(void* monitor, int& width, int& height, int& refreshRate) = 0;
    virtual double GetTime() = 0;
    virtual void GetFramebufferSize(int windowID, int& width, int& height) = 0;
    virtual void* GetNativeWindow(int windowID) = 0;
    virtual void* GetCurrentContext() = 0;
    virtual void MakeContextCurrent(void* context) = 0;
    virtual void SetKeyCallback(int windowID, KeyCallbackFn callback) = 0;
    virtual void SetMouseButtonCallback(int windowID, MouseBtnCallbackFn callback) = 0;
    virtual void SetCursorPosCallback(int windowID, CursorPosCallbackFn callback) = 0;
    virtual void SetWindowShouldClose(int windowID, int value) = 0;
    virtual void IconifyWindow(int windowID) = 0;
};

IWindowManager& GetWindowManager(PAPI api);

#define WTG_VERSION_MAJOR          3
#define WTG_VERSION_MINOR          5
#define WTG_VERSION_REVISION       0

#define WTG_TRUE                   1
#define WTG_FALSE                  0

#define WTG_RELEASE                0
#define WTG_PRESS                  1
#define WTG_REPEAT                 2

#define WTG_HAT_CENTERED           0
#define WTG_HAT_UP                 1
#define WTG_HAT_RIGHT              2
#define WTG_HAT_DOWN               4
#define WTG_HAT_LEFT               8
#define WTG_HAT_RIGHT_UP           (WTG_HAT_RIGHT | WTG_HAT_UP)
#define WTG_HAT_RIGHT_DOWN         (WTG_HAT_RIGHT | WTG_HAT_DOWN)
#define WTG_HAT_LEFT_UP            (WTG_HAT_LEFT  | WTG_HAT_UP)
#define WTG_HAT_LEFT_DOWN          (WTG_HAT_LEFT  | WTG_HAT_DOWN)

#define WTG_KEY_UNKNOWN            -1
#define WTG_KEY_SPACE              32
#define WTG_KEY_APOSTROPHE         39  /* ' */
#define WTG_KEY_COMMA              44  /* , */
#define WTG_KEY_MINUS              45  /* - */
#define WTG_KEY_PERIOD             46  /* . */
#define WTG_KEY_SLASH              47  /* / */
#define WTG_KEY_0                  48
#define WTG_KEY_1                  49
#define WTG_KEY_2                  50
#define WTG_KEY_3                  51
#define WTG_KEY_4                  52
#define WTG_KEY_5                  53
#define WTG_KEY_6                  54
#define WTG_KEY_7                  55
#define WTG_KEY_8                  56
#define WTG_KEY_9                  57
#define WTG_KEY_SEMICOLON          59  /* ; */
#define WTG_KEY_EQUAL              61  /* = */
#define WTG_KEY_A                  65
#define WTG_KEY_B                  66
#define WTG_KEY_C                  67
#define WTG_KEY_D                  68
#define WTG_KEY_E                  69
#define WTG_KEY_F                  70
#define WTG_KEY_G                  71
#define WTG_KEY_H                  72
#define WTG_KEY_I                  73
#define WTG_KEY_J                  74
#define WTG_KEY_K                  75
#define WTG_KEY_L                  76
#define WTG_KEY_M                  77
#define WTG_KEY_N                  78
#define WTG_KEY_O                  79
#define WTG_KEY_P                  80
#define WTG_KEY_Q                  81
#define WTG_KEY_R                  82
#define WTG_KEY_S                  83
#define WTG_KEY_T                  84
#define WTG_KEY_U                  85
#define WTG_KEY_V                  86
#define WTG_KEY_W                  87
#define WTG_KEY_X                  88
#define WTG_KEY_Y                  89
#define WTG_KEY_Z                  90
#define WTG_KEY_LEFT_BRACKET       91  /* [ */
#define WTG_KEY_BACKSLASH          92  /* \ */
#define WTG_KEY_RIGHT_BRACKET      93  /* ] */
#define WTG_KEY_GRAVE_ACCENT       96  /* ` */
#define WTG_KEY_WORLD_1            161 /* non-US #1 */
#define WTG_KEY_WORLD_2            162 /* non-US #2 */

/* Function keys */
#define WTG_KEY_ESCAPE             256
#define WTG_KEY_ENTER              257
#define WTG_KEY_TAB                258
#define WTG_KEY_BACKSPACE          259
#define WTG_KEY_INSERT             260
#define WTG_KEY_DELETE             261
#define WTG_KEY_RIGHT              262
#define WTG_KEY_LEFT               263
#define WTG_KEY_DOWN               264
#define WTG_KEY_UP                 265
#define WTG_KEY_PAGE_UP            266
#define WTG_KEY_PAGE_DOWN          267
#define WTG_KEY_HOME               268
#define WTG_KEY_END                269
#define WTG_KEY_CAPS_LOCK          280
#define WTG_KEY_SCROLL_LOCK        281
#define WTG_KEY_NUM_LOCK           282
#define WTG_KEY_PRINT_SCREEN       283
#define WTG_KEY_PAUSE              284
#define WTG_KEY_F1                 290
#define WTG_KEY_F2                 291
#define WTG_KEY_F3                 292
#define WTG_KEY_F4                 293
#define WTG_KEY_F5                 294
#define WTG_KEY_F6                 295
#define WTG_KEY_F7                 296
#define WTG_KEY_F8                 297
#define WTG_KEY_F9                 298
#define WTG_KEY_F10                299
#define WTG_KEY_F11                300
#define WTG_KEY_F12                301
#define WTG_KEY_F13                302
#define WTG_KEY_F14                303
#define WTG_KEY_F15                304
#define WTG_KEY_F16                305
#define WTG_KEY_F17                306
#define WTG_KEY_F18                307
#define WTG_KEY_F19                308
#define WTG_KEY_F20                309
#define WTG_KEY_F21                310
#define WTG_KEY_F22                311
#define WTG_KEY_F23                312
#define WTG_KEY_F24                313
#define WTG_KEY_F25                314
#define WTG_KEY_KP_0               320
#define WTG_KEY_KP_1               321
#define WTG_KEY_KP_2               322
#define WTG_KEY_KP_3               323
#define WTG_KEY_KP_4               324
#define WTG_KEY_KP_5               325
#define WTG_KEY_KP_6               326
#define WTG_KEY_KP_7               327
#define WTG_KEY_KP_8               328
#define WTG_KEY_KP_9               329
#define WTG_KEY_KP_DECIMAL         330
#define WTG_KEY_KP_DIVIDE          331
#define WTG_KEY_KP_MULTIPLY        332
#define WTG_KEY_KP_SUBTRACT        333
#define WTG_KEY_KP_ADD             334
#define WTG_KEY_KP_ENTER           335
#define WTG_KEY_KP_EQUAL           336
#define WTG_KEY_LEFT_SHIFT         340
#define WTG_KEY_LEFT_CONTROL       341
#define WTG_KEY_LEFT_ALT           342
#define WTG_KEY_LEFT_SUPER         343
#define WTG_KEY_RIGHT_SHIFT        344
#define WTG_KEY_RIGHT_CONTROL      345
#define WTG_KEY_RIGHT_ALT          346
#define WTG_KEY_RIGHT_SUPER        347
#define WTG_KEY_MENU               348

#define WTG_KEY_LAST               WTG_KEY_MENU

#define WTG_MOD_SHIFT           0x0001
#define WTG_MOD_CONTROL         0x0002
#define WTG_MOD_ALT             0x0004
#define WTG_MOD_SUPER           0x0008
#define WTG_MOD_CAPS_LOCK       0x0010
#define WTG_MOD_NUM_LOCK        0x0020

#define WTG_MOUSE_BUTTON_1         0
#define WTG_MOUSE_BUTTON_2         1
#define WTG_MOUSE_BUTTON_3         2
#define WTG_MOUSE_BUTTON_4         3
#define WTG_MOUSE_BUTTON_5         4
#define WTG_MOUSE_BUTTON_6         5
#define WTG_MOUSE_BUTTON_7         6
#define WTG_MOUSE_BUTTON_8         7
#define WTG_MOUSE_BUTTON_LAST      WTG_MOUSE_BUTTON_8
#define WTG_MOUSE_BUTTON_LEFT      WTG_MOUSE_BUTTON_1
#define WTG_MOUSE_BUTTON_RIGHT     WTG_MOUSE_BUTTON_2
#define WTG_MOUSE_BUTTON_MIDDLE    WTG_MOUSE_BUTTON_3

#define WTG_JOYSTICK_1             0
#define WTG_JOYSTICK_2             1
#define WTG_JOYSTICK_3             2
#define WTG_JOYSTICK_4             3
#define WTG_JOYSTICK_5             4
#define WTG_JOYSTICK_6             5
#define WTG_JOYSTICK_7             6
#define WTG_JOYSTICK_8             7
#define WTG_JOYSTICK_9             8
#define WTG_JOYSTICK_10            9
#define WTG_JOYSTICK_11            10
#define WTG_JOYSTICK_12            11
#define WTG_JOYSTICK_13            12
#define WTG_JOYSTICK_14            13
#define WTG_JOYSTICK_15            14
#define WTG_JOYSTICK_16            15
#define WTG_JOYSTICK_LAST          WTG_JOYSTICK_16

#define WTG_GAMEPAD_BUTTON_A               0
#define WTG_GAMEPAD_BUTTON_B               1
#define WTG_GAMEPAD_BUTTON_X               2
#define WTG_GAMEPAD_BUTTON_Y               3
#define WTG_GAMEPAD_BUTTON_LEFT_BUMPER     4
#define WTG_GAMEPAD_BUTTON_RIGHT_BUMPER    5
#define WTG_GAMEPAD_BUTTON_BACK            6
#define WTG_GAMEPAD_BUTTON_START           7
#define WTG_GAMEPAD_BUTTON_GUIDE           8
#define WTG_GAMEPAD_BUTTON_LEFT_THUMB      9
#define WTG_GAMEPAD_BUTTON_RIGHT_THUMB     10
#define WTG_GAMEPAD_BUTTON_DPAD_UP         11
#define WTG_GAMEPAD_BUTTON_DPAD_RIGHT      12
#define WTG_GAMEPAD_BUTTON_DPAD_DOWN       13
#define WTG_GAMEPAD_BUTTON_DPAD_LEFT       14
#define WTG_GAMEPAD_BUTTON_LAST            WTG_GAMEPAD_BUTTON_DPAD_LEFT

#define WTG_GAMEPAD_BUTTON_CROSS       WTG_GAMEPAD_BUTTON_A
#define WTG_GAMEPAD_BUTTON_CIRCLE      WTG_GAMEPAD_BUTTON_B
#define WTG_GAMEPAD_BUTTON_SQUARE      WTG_GAMEPAD_BUTTON_X
#define WTG_GAMEPAD_BUTTON_TRIANGLE    WTG_GAMEPAD_BUTTON_Y

#define WTG_GAMEPAD_AXIS_LEFT_X        0
#define WTG_GAMEPAD_AXIS_LEFT_Y        1
#define WTG_GAMEPAD_AXIS_RIGHT_X       2
#define WTG_GAMEPAD_AXIS_RIGHT_Y       3
#define WTG_GAMEPAD_AXIS_LEFT_TRIGGER  4
#define WTG_GAMEPAD_AXIS_RIGHT_TRIGGER 5
#define WTG_GAMEPAD_AXIS_LAST          WTG_GAMEPAD_AXIS_RIGHT_TRIGGER

#define WTG_NO_ERROR               0
#define WTG_NOT_INITIALIZED        0x00010001
#define WTG_NO_CURRENT_CONTEXT     0x00010002
#define WTG_INVALID_ENUM           0x00010003
#define WTG_INVALID_VALUE          0x00010004
#define WTG_OUT_OF_MEMORY          0x00010005
#define WTG_API_UNAVAILABLE        0x00010006
#define WTG_VERSION_UNAVAILABLE    0x00010007
#define WTG_PLATFORM_ERROR         0x00010008
#define WTG_FORMAT_UNAVAILABLE     0x00010009
#define WTG_NO_WINDOW_CONTEXT      0x0001000A
#define WTG_CURSOR_UNAVAILABLE     0x0001000B
#define WTG_FEATURE_UNAVAILABLE    0x0001000C
#define WTG_FEATURE_UNIMPLEMENTED  0x0001000D
#define WTG_PLATFORM_UNAVAILABLE   0x0001000E
#define WTG_FOCUSED                0x00020001
#define WTG_ICONIFIED              0x00020002
#define WTG_RESIZABLE              0x00020003
#define WTG_VISIBLE                0x00020004
#define WTG_DECORATED              0x00020005
#define WTG_AUTO_ICONIFY           0x00020006
#define WTG_FLOATING               0x00020007
#define WTG_MAXIMIZED              0x00020008
#define WTG_CENTER_CURSOR          0x00020009
#define WTG_TRANSPARENT_FRAMEBUFFER 0x0002000A
#define WTG_HOVERED                0x0002000B
#define WTG_FOCUS_ON_SHOW          0x0002000C
#define WTG_MOUSE_PASSTHROUGH      0x0002000D
#define WTG_POSITION_X             0x0002000E
#define WTG_POSITION_Y             0x0002000F
#define WTG_RED_BITS               0x00021001
#define WTG_GREEN_BITS             0x00021002
#define WTG_BLUE_BITS              0x00021003
#define WTG_ALPHA_BITS             0x00021004
#define WTG_DEPTH_BITS             0x00021005
#define WTG_STENCIL_BITS           0x00021006
#define WTG_ACCUM_RED_BITS         0x00021007
#define WTG_ACCUM_GREEN_BITS       0x00021008
#define WTG_ACCUM_BLUE_BITS        0x00021009
#define WTG_ACCUM_ALPHA_BITS       0x0002100A
#define WTG_AUX_BUFFERS            0x0002100B
#define WTG_STEREO                 0x0002100C
#define WTG_SAMPLES                0x0002100D
#define WTG_SRGB_CAPABLE           0x0002100E
#define WTG_REFRESH_RATE           0x0002100F
#define WTG_DOUBLEBUFFER           0x00021010
#define WTG_CLIENT_API             0x00022001
#define WTG_CONTEXT_VERSION_MAJOR  0x00022002
#define WTG_CONTEXT_VERSION_MINOR  0x00022003
#define WTG_CONTEXT_REVISION       0x00022004
#define WTG_CONTEXT_ROBUSTNESS     0x00022005
#define WTG_OPENGL_FORWARD_COMPAT  0x00022006
#define WTG_CONTEXT_DEBUG          0x00022007
#define WTG_OPENGL_DEBUG_CONTEXT   WTG_CONTEXT_DEBUG
#define WTG_OPENGL_PROFILE         0x00022008
#define WTG_CONTEXT_RELEASE_BEHAVIOR 0x00022009
#define WTG_CONTEXT_NO_ERROR       0x0002200A
#define WTG_CONTEXT_CREATION_API   0x0002200B
#define WTG_SCALE_TO_MONITOR       0x0002200C
#define WTG_SCALE_FRAMEBUFFER      0x0002200D
#define WTG_COCOA_RETINA_FRAMEBUFFER 0x00023001
#define WTG_COCOA_FRAME_NAME         0x00023002
#define WTG_COCOA_GRAPHICS_SWITCHING 0x00023003
#define WTG_X11_CLASS_NAME         0x00024001
#define WTG_X11_INSTANCE_NAME      0x00024002
#define WTG_WIN32_KEYBOARD_MENU    0x00025001
#define WTG_WIN32_SHOWDEFAULT      0x00025002
#define WTG_WAYLAND_APP_ID         0x00026001

#define WTG_NO_API                          0
#define WTG_OPENGL_API             0x00030001
#define WTG_OPENGL_ES_API          0x00030002

#define WTG_NO_ROBUSTNESS                   0
#define WTG_NO_RESET_NOTIFICATION  0x00031001
#define WTG_LOSE_CONTEXT_ON_RESET  0x00031002

#define WTG_OPENGL_ANY_PROFILE              0
#define WTG_OPENGL_CORE_PROFILE    0x00032001
#define WTG_OPENGL_COMPAT_PROFILE  0x00032002

#define WTG_CURSOR                  0x00033001
#define WTG_STICKY_KEYS             0x00033002
#define WTG_STICKY_MOUSE_BUTTONS    0x00033003
#define WTG_LOCK_KEY_MODS           0x00033004
#define WTG_RAW_MOUSE_MOTION        0x00033005
#define WTG_UNLIMITED_MOUSE_BUTTONS 0x00033006

#define WTG_CURSOR_NORMAL          0x00034001
#define WTG_CURSOR_HIDDEN          0x00034002
#define WTG_CURSOR_DISABLED        0x00034003
#define WTG_CURSOR_CAPTURED        0x00034004

#define WTG_ANY_RELEASE_BEHAVIOR            0
#define WTG_RELEASE_BEHAVIOR_FLUSH 0x00035001
#define WTG_RELEASE_BEHAVIOR_NONE  0x00035002

#define WTG_NATIVE_CONTEXT_API     0x00036001
#define WTG_EGL_CONTEXT_API        0x00036002
#define WTG_OSMESA_CONTEXT_API     0x00036003

#define WTG_ANGLE_PLATFORM_TYPE_NONE    0x00037001
#define WTG_ANGLE_PLATFORM_TYPE_OPENGL  0x00037002
#define WTG_ANGLE_PLATFORM_TYPE_OPENGLES 0x00037003
#define WTG_ANGLE_PLATFORM_TYPE_D3D9    0x00037004
#define WTG_ANGLE_PLATFORM_TYPE_D3D11   0x00037005
#define WTG_ANGLE_PLATFORM_TYPE_VULKAN  0x00037007
#define WTG_ANGLE_PLATFORM_TYPE_METAL   0x00037008

#define WTG_WAYLAND_PREFER_LIBDECOR    0x00038001
#define WTG_WAYLAND_DISABLE_LIBDECOR   0x00038002

#define WTG_ANY_POSITION           0x80000000
#define WTG_ARROW_CURSOR           0x00036001
#define WTG_IBEAM_CURSOR           0x00036002
#define WTG_CROSSHAIR_CURSOR       0x00036003
#define WTG_POINTING_HAND_CURSOR   0x00036004
#define WTG_RESIZE_EW_CURSOR       0x00036005
#define WTG_RESIZE_NS_CURSOR       0x00036006
#define WTG_RESIZE_NWSE_CURSOR     0x00036007
#define WTG_RESIZE_NESW_CURSOR     0x00036008
#define WTG_RESIZE_ALL_CURSOR      0x00036009
#define WTG_NOT_ALLOWED_CURSOR     0x0003600A
#define WTG_HRESIZE_CURSOR         WTG_RESIZE_EW_CURSOR
#define WTG_VRESIZE_CURSOR         WTG_RESIZE_NS_CURSOR
#define WTG_HAND_CURSOR            WTG_POINTING_HAND_CURSOR
#define WTG_CONNECTED              0x00040001
#define WTG_DISCONNECTED           0x00040002
#define WTG_JOYSTICK_HAT_BUTTONS   0x00050001
#define WTG_ANGLE_PLATFORM_TYPE    0x00050002
#define WTG_PLATFORM               0x00050003
#define WTG_COCOA_CHDIR_RESOURCES  0x00051001
#define WTG_COCOA_MENUBAR          0x00051002
#define WTG_X11_XCB_VULKAN_SURFACE 0x00052001
#define WTG_WAYLAND_LIBDECOR       0x00053001
#define WTG_ANY_PLATFORM           0x00060000
#define WTG_PLATFORM_WIN32         0x00060001
#define WTG_PLATFORM_COCOA         0x00060002
#define WTG_PLATFORM_WAYLAND       0x00060003
#define WTG_PLATFORM_X11           0x00060004
#define WTG_PLATFORM_NULL          0x00060005