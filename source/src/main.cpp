#include "IWindowManager.h"
#include <iostream>

int main() {
    std::cout << "starting..." << std::endl;

    // Choose the platform API to use for windowing
    PAPI desiredApi = PAPI::GLFW;

    IWindowManager& windowManager = GetWindowManager(desiredApi);
    int myWindowID = windowManager.CreateWindow(800, 600, "Glfw");

    if (myWindowID == -1) {
        return -1;
    }

    std::cout << "window created" << std::endl;

    while (windowManager.IsWindowOpen(myWindowID)) {
        windowManager.Update();
    }

    std::cout << "closing" << std::endl;
    return 0;
}