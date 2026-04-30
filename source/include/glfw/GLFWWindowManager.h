#pragma once
#include "IWindowManager.h"
#include <vector>

struct GLFWwindow;

class GLFWWindowManager : public IWindowManager {
private:
    struct WindowCallbacks {
        KeyCallbackFn key;
        MouseBtnCallbackFn mouse;
        CursorPosCallbackFn cursor;
    };
    std::vector<GLFWwindow*> windows;
    std::vector<WindowCallbacks> windowCallbacks;
    GLFWWindowManager();
    GLFWWindowManager(const GLFWWindowManager&) = delete;
    GLFWWindowManager& operator=(const GLFWWindowManager&) = delete;
    GLFWWindowManager(GLFWWindowManager&&) = delete;
    GLFWWindowManager& operator=(GLFWWindowManager&&) = delete;

public:
    static GLFWWindowManager& GetInstance();
    ~GLFWWindowManager() override;

    int CreateWindow(int width, int height, const std::string& title) override;
    void DestroyWindow(int windowID) override;
    void PollEvents() override;
    void SwapBuffers(int windowID) override;
    bool IsWindowOpen(int windowID) override;
    virtual void SetWindowSize(int windowID, int width, int height)override;
    virtual void SetWindowPos(int windowID, int xpos, int ypos) override;
    virtual void GetWindowPos(int windowID, int& xpos, int& ypos) override;
    virtual int  GetWindowAttrib(int windowID, int attrib) override;
    virtual void RestoreWindow(int windowID) override;
    virtual void MaximizeWindow(int windowID) override;
    void SetErrorCallback() override;
    void WindowHint(int hint, int value) override;
    void* GetPrimaryMonitor() override;
    void GetVideoMode(void* monitor, int& width, int& height, int& refreshRate) override;
    double GetTime() override;
    void GetFramebufferSize(int windowID, int& width, int& height) override;
    void* GetNativeWindow(int windowID) override;
    void* GetCurrentContext() override;
    void MakeContextCurrent(void* context) override;
    void SetKeyCallback(int windowID, KeyCallbackFn callback) override;
    void SetMouseButtonCallback(int windowID, MouseBtnCallbackFn callback) override;
    void SetCursorPosCallback(int windowID, CursorPosCallbackFn callback) override;
    void SetWindowShouldClose(int windowID, int value) override;
    void IconifyWindow(int windowID)override;
};