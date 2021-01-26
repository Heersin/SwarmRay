//
// Created by heersin on 1/26/21.
//

#include "App.h"
#include <iostream>

App::App() {
    runState = false;
}

void App::run() {
    std::cout << "[*] Run State - " << (runState ? "On" : "Off");
}