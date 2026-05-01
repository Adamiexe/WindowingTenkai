#include "glfw/GLFWWindowManager.h"
#include <GLFW/glfw3.h>
#include <iostream>
#include <stdexcept>

IWindowManager& GetWindowManager(PAPI api) {
    switch (api) {
        case PAPI::GLFW:
            return GLFWWindowManager::GetInstance();
        case PAPI::SDL:
        default:
            throw std::runtime_error("Selected PAPI is not implemented yet");
    }
}

GLFWWindowManager& GLFWWindowManager::GetInstance() {
    static GLFWWindowManager instance;
    return instance;
}

GLFWWindowManager::GLFWWindowManager() {
    if (!glfwInit()) {
        throw std::runtime_error("cant initialize glfw");
    }
}

GLFWWindowManager::~GLFWWindowManager() {
    for (GLFWwindow* window :windows) {
        if (window != nullptr) {
            glfwDestroyWindow(window);
        }
    }
    glfwTerminate();
}

int GLFWWindowManager::CreateWindow(int width, int height, const std::string& title) {
    GLFWwindow* window = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);

    if (!window) {
        std::cerr << "failed creating glfw window" << std::endl;
        return -1;
    }

    glfwMakeContextCurrent(window);
    windows.push_back(window);
    windowCallbacks.push_back({});

    return static_cast<int>(windows.size() - 1);
}

void GLFWWindowManager::DestroyWindow(int windowID) {
    if (windowID >= 0 && windowID < static_cast<int>(windows.size()) && windows[windowID] != nullptr) {
        glfwDestroyWindow(windows[windowID]);
        windows[windowID] = nullptr;
    }
}

bool GLFWWindowManager::IsWindowOpen(int windowID) {
    if (windowID >= 0 && windowID < static_cast<int>(windows.size()) && windows[windowID] != nullptr) {
        return !glfwWindowShouldClose(windows[windowID]);
    }
    return false;
}

void GLFWWindowManager::SetWindowSize(int windowID, int width, int height) {
    if (windowID >= 0 && windowID < windows.size() && windows[windowID] != nullptr) {
        glfwSetWindowSize(windows[windowID], width, height);
    }
}

void GLFWWindowManager::SetWindowPos(int windowID, int xpos, int ypos) {
    if (windowID >= 0 && windowID < windows.size() && windows[windowID] != nullptr) {
        glfwSetWindowPos(windows[windowID], xpos, ypos);
    }
}

void GLFWWindowManager::GetWindowPos(int windowID, int& xpos, int& ypos) {
    if (windowID >= 0 && windowID < windows.size() && windows[windowID] != nullptr) {
        glfwGetWindowPos(windows[windowID], &xpos, &ypos);
    }
    else {
        xpos = 0;
        ypos = 0;
    }
}

int GLFWWindowManager::GetWindowAttrib(int windowID, int attrib) {
    if (windowID >= 0 && windowID < windows.size() && windows[windowID] != nullptr) {
        return glfwGetWindowAttrib(windows[windowID], attrib);
    }
    return 0;
}

void GLFWWindowManager::RestoreWindow(int windowID) {
    if (windowID >= 0 && windowID < windows.size() && windows[windowID] != nullptr) {
        glfwRestoreWindow(windows[windowID]);
    }
}

void GLFWWindowManager::MaximizeWindow(int windowID) {
    if (windowID >= 0 && windowID < windows.size() && windows[windowID] != nullptr) {
        glfwMaximizeWindow(windows[windowID]);
    }
}

void GLFWWindowManager::SetErrorCallback() {
    glfwSetErrorCallback([](int error, const char* description) {
        std::cerr << "GLFW Error (" << error << "): " << description << std::endl;
        });
}

void GLFWWindowManager::WindowHint(int hint, int value) {
    glfwWindowHint(hint, value);
}

void* GLFWWindowManager::GetPrimaryMonitor() {
    return glfwGetPrimaryMonitor();
}

void GLFWWindowManager::GetVideoMode(void* monitor, int& width, int& height, int& refreshRate) {
    if (!monitor) {
        width = 0; height = 0; refreshRate = 0;
        return;
    }

    const GLFWvidmode* mode = glfwGetVideoMode(static_cast<GLFWmonitor*>(monitor));

    if (mode) {
        width = mode->width;
        height = mode->height;
        refreshRate = mode->refreshRate;
    }
    else {
        width = 0; height = 0; refreshRate = 0;
    }
}

void GLFWWindowManager::PollEvents() {
    glfwPollEvents();
}

void GLFWWindowManager::SwapBuffers(int windowID) {
    if (windowID >= 0 && windowID < windows.size() && windows[windowID] != nullptr) {
        glfwSwapBuffers(windows[windowID]);
    }
}

double GLFWWindowManager::GetTime() {
    return glfwGetTime();
}

void GLFWWindowManager::GetFramebufferSize(int windowID, int& width, int& height) {
    if (windowID >= 0 && windowID < windows.size() && windows[windowID] != nullptr) {
        glfwGetFramebufferSize(windows[windowID], &width, &height);
    }
    else {
        width = 0; height = 0;
    }
}

void* GLFWWindowManager::GetNativeWindow(int windowID) {
    if (windowID >= 0 && windowID < windows.size()) return windows[windowID];
    return nullptr;
}

void* GLFWWindowManager::GetCurrentContext() {
    return glfwGetCurrentContext();
}

void GLFWWindowManager::MakeContextCurrent(void* context) {
    glfwMakeContextCurrent(static_cast<GLFWwindow*>(context));
}

void GLFWWindowManager::SetKeyCallback(int windowID, KeyCallbackFn callback) {
    if (windowID < 0 || windowID >= windows.size() || !windows[windowID]) return;
    windowCallbacks[windowID].key = callback;

    glfwSetWindowUserPointer(windows[windowID], (void*)(intptr_t)windowID);

    glfwSetKeyCallback(windows[windowID], [](GLFWwindow* w, int key, int scancode, int action, int mods) {
        int id = (int)(intptr_t)glfwGetWindowUserPointer(w);
        auto& cb = GetInstance().windowCallbacks[id].key;
        if (cb) cb(key, action);
        });
}

void GLFWWindowManager::SetMouseButtonCallback(int windowID, MouseBtnCallbackFn callback) {
    if (windowID < 0 || windowID >= windows.size() || !windows[windowID]) return;
    windowCallbacks[windowID].mouse = callback;

    glfwSetWindowUserPointer(windows[windowID], (void*)(intptr_t)windowID);
    glfwSetMouseButtonCallback(windows[windowID], [](GLFWwindow* w, int button, int action, int mods) {
        int id = (int)(intptr_t)glfwGetWindowUserPointer(w);
        auto& cb = GetInstance().windowCallbacks[id].mouse;
        if (cb) cb(button, action);
        });
}

void GLFWWindowManager::SetCursorPosCallback(int windowID, CursorPosCallbackFn callback) {
    if (windowID < 0 || windowID >= windows.size() || !windows[windowID]) return;
    windowCallbacks[windowID].cursor = callback;

    glfwSetWindowUserPointer(windows[windowID], (void*)(intptr_t)windowID);
    glfwSetCursorPosCallback(windows[windowID], [](GLFWwindow* w, double xpos, double ypos) {
        int id = (int)(intptr_t)glfwGetWindowUserPointer(w);
        auto& cb = GetInstance().windowCallbacks[id].cursor;
        if (cb) cb(xpos, ypos);
        });
}

void GLFWWindowManager::SetWindowShouldClose(int windowID, int value) {
    glfwSetWindowShouldClose(windows[windowID],value);
}

void GLFWWindowManager::IconifyWindow(int windowID) {
    glfwIconifyWindow(windows[windowID]);
}

void GLFWWindowManager::GetWindowSize(int windowID, int& width, int& height) {
    glfwGetWindowSize(windows[windowID], &width, &height);
}