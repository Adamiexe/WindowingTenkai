#pragma once
#include "IWindowManager.h"
#include <vector>

struct GLFWwindow;

class GLFWWindowManager : public IWindowManager {
private:
    std::vector<GLFWwindow*> m_windows;
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
};