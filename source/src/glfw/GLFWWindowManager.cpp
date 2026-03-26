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
    for (GLFWwindow* window : m_windows) {
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
    m_windows.push_back(window);
    return static_cast<int>(m_windows.size() - 1);
}

void GLFWWindowManager::DestroyWindow(int windowID) {
    if (windowID >= 0 && windowID < static_cast<int>(m_windows.size()) && m_windows[windowID] != nullptr) {
        glfwDestroyWindow(m_windows[windowID]);
        m_windows[windowID] = nullptr;
    }
}

void GLFWWindowManager::Update() {
    glfwPollEvents();
    for (GLFWwindow* window : m_windows) {
        if (window != nullptr) {
            glfwSwapBuffers(window);
        }
    }
}

bool GLFWWindowManager::IsWindowOpen(int windowID) {
    if (windowID >= 0 && windowID < static_cast<int>(m_windows.size()) && m_windows[windowID] != nullptr) {
        return !glfwWindowShouldClose(m_windows[windowID]);
    }
    return false;
}