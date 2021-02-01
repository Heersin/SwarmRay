//
// Created by heersin on 1/31/21.
//

#include "ProcManager.h"
void ProcManager::launchProc(EXTERN_COMMAND command, vector<string> &args) {
    switch (command)
    {
        case PYTHON_PLUGIN:
            this->launchPythonProc(args);
            break;

        case WEB_SERVER:
            this->launchWebProc(args);
            break;

        default:
            break;
    }
}