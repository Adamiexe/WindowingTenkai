#pragma once
#include "IWindowManager.h"
#include <vector>

struct GLFWwindow;

class GLFWWindowManager : public IWindowManager {
private:
    std::vector<GLFWwindow*> windows;
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
    void Update() override;
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
};