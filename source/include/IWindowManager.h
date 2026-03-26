#pragma once
#include <string>

enum class PAPI {
    SDL,
    GLFW
};

class IWindowManager {
public:
    virtual ~IWindowManager() = default;

    virtual int CreateWindow(int width, int height, const std::string& title) = 0;
    virtual void DestroyWindow(int windowID) = 0;
    virtual void Update() = 0;
    virtual bool IsWindowOpen(int windowID) = 0;
};

IWindowManager& GetWindowManager(PAPI api);