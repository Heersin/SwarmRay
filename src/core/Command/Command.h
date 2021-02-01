//
// Created by heersin on 1/30/21.
//

#ifndef SWARMRAY_COMMAND_H
#define SWARMRAY_COMMAND_H

#include "../Task/Task.h"
#include "../langs.h"
#include "../../scanner/ScannerFactory.h"
#include <map>

class Command {
public:
    virtual void exec() = 0 ;
    virtual ~Command() = default;
};

class BuiltInCommand : public Command{
public:
    void exec() override;
    BuiltInCommand(SearchScannerFactory &src_scanner_factory, Task &task);
    BuiltInCommand(SyntaxScannerFactory &syn_scanner_factory, Task &task);


private:
    // detect which type of scanner should be used
    BUILTIN_SCANNER_TYPE scanner_type;
    LANG_TYPE lang_type;
    Task &command_task;
    AbsScannerFactory &factory;

    // TODO
    // other arguments may be required
};


#endif //SWARMRAY_COMMAND_H
