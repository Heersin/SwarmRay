//
// Created by heersin on 1/31/21.
//

#include "ProcManager.h"

namespace bp = boost::process;

void ProcManager::launchProc(EXTERN_COMMAND command, vector<string> &args) {
    switch (command)
    {
        case PYTHON_PLUGIN:
            this->launchPythonProc(args);
            break;

        case WEB_SERVER:
            this->launchWebProc();
            break;

        default:
            break;
    }
}

void ProcManager::launchPythonProc(vector<string> &args)
{
    // leave it to network communication
    bp::spawn(bp::search_path("python"), args);
}



void ProcManager::launchTread(BuiltInCommand &command)
{
    printf("launch a thread of builtin Command\n");
    command.exec();
}

void ProcManager::launchWebProc() {
    bp::spawn(bp::search_path("python"), "test_server.py")
}