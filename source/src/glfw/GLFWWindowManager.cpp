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
    return static_cast<int>(windows.size() - 1);
}

void GLFWWindowManager::DestroyWindow(int windowID) {
    if (windowID >= 0 && windowID < static_cast<int>(windows.size()) && windows[windowID] != nullptr) {
        glfwDestroyWindow(windows[windowID]);
        windows[windowID] = nullptr;
    }
}

void GLFWWindowManager::Update() {
    glfwPollEvents();
    for (GLFWwindow* window : windows) {
        if (window != nullptr) {
            glfwSwapBuffers(window);
        }
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