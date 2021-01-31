//
// Created by heersin on 1/31/21.
//

#ifndef SWARMRAY_PROCMANAGER_H
#define SWARMRAY_PROCMANAGER_H

#include "../Command/Command.h"

/**
 * Use Asio to read File before scan ?
 *
 */

class ProcManager {
public:
    ProcManager(BuiltInCommand &builtInCommand);
    ProcManager(ExternCommand &externCommand);
};


#endif //SWARMRAY_PROCMANAGER_H
