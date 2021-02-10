//
// Created by heersin on 1/26/21.
//

#include "App.h"
#include <iostream>

App::App() : appConfig(), global_scheduler(appConfig){
    run_state = false;
}

void App::run() {
    std::cout << "[*] Run State - " << (run_state ? "On" : "Off") << endl;
    global_scheduler.schedule();
}