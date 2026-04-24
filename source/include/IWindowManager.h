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
    virtual void SetWindowSize(int windowID, int width, int height) = 0;
    virtual void SetWindowPos(int windowID, int xpos, int ypos) = 0;
    virtual void GetWindowPos(int windowID, int& xpos, int& ypos) = 0;
    virtual int  GetWindowAttrib(int windowID, int attrib) = 0;
    virtual void RestoreWindow(int windowID) = 0;
    virtual void MaximizeWindow(int windowID) = 0;
};

IWindowManager& GetWindowManager(PAPI api);