#include "IWindowManager.h"
#include <iostream>

int main() {
    std::cout << "starting..." << std::endl;

    IWindowManager& windowManager = GetWindowManager(PAPI:: GLFW);
    int myWindowID = windowManager.CreateWindow(800, 600, "Glfw");

    if (myWindowID == -1) {
        std::cout << "window not managed to initialize" << std::endl;
        return -1;
    }

    std::cout << "window created" << std::endl;

    while (windowManager.IsWindowOpen(myWindowID)) {
        windowManager.PollEvents();
        windowManager.SwapBuffers(myWindowID);
    }

    std::cout << "closing" << std::endl;
    return 0;
}