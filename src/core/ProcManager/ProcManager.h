//
// Created by heersin on 1/31/21.
//

#ifndef SWARMRAY_PROCMANAGER_H
#define SWARMRAY_PROCMANAGER_H

#include "../Command/Command.h"

class ProcManager {
public:
    ProcManager(BuiltInCommand &builtInCommand);
    ProcManager(ExternCommand &externCommand);
};


#endif //SWARMRAY_PROCMANAGER_H
