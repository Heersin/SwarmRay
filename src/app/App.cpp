//
// Created by heersin on 1/26/21.
//

#include "App.h"
#include <iostream>

App::App() {
    run_state = false;
}

void App::run() {
    std::cout << "[*] Run State - " << (run_state ? "On" : "Off");
}