//
// Created by heersin on 1/31/21.
//

#ifndef SWARMRAY_PROCMANAGER_H
#define SWARMRAY_PROCMANAGER_H

#include "../Command/Command.h"
#include <vector>
#include <boost/process.hpp>

/**
 * Use Asio to read File before scan ?
 *
 */

class ProcManager {
public:
    void launchTread(BuiltInCommand &command);
    void launchProc(EXTERN_COMMAND command, vector<string> &args);

private:
    void launchPythonProc(vector<string> &args);
    void launchWebProc();
};


#endif //SWARMRAY_PROCMANAGER_H
