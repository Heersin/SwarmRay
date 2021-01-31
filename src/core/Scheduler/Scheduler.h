//
// Created by heersin on 1/31/21.
//

#ifndef SWARMRAY_SCHEDULER_H
#define SWARMRAY_SCHEDULER_H

#include "../../conf/Config.h"
#include "../../scanner/ScannerFactory.h"
#include "../Task/TaskManger.h"
#include "../Command/Command.h"
#include "../ProcManager/ProcManager.h"

class Scheduler {
public:
    void schedule();
    Scheduler(Config &app_config);

private:
    Config &appConfig;
};


#endif //SWARMRAY_SCHEDULER_H
