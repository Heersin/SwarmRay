//
// Created by heersin on 1/26/21.
//

#ifndef SWARMRAY_APP_H
#define SWARMRAY_APP_H

#include "../core/Scheduler/Scheduler.h"

class App {
public:
    App();
    void run();

private:
    bool run_state;
    Config appConfig;
    Scheduler global_scheduler;
};


#endif //SWARMRAY_APP_H
