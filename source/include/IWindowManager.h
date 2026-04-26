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
};

IWindowManager& GetWindowManager(PAPI api);