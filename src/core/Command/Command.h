//
// Created by heersin on 1/30/21.
//

#ifndef SWARMRAY_COMMAND_H
#define SWARMRAY_COMMAND_H

#include "../Task/Task.h"

enum BUILTIN_SCANNER_TYPE {REGEX, SONIC, SYNTAX};

class Command {
public:
    virtual void exec() = 0 ;
    virtual ~Command() = default;
};

class BuiltInCommand : public Command{
public:
    void exec() override;
    BuiltInCommand(BUILTIN_SCANNER_TYPE scannerType, Task &task);

private:
    // detect which type of scanner should be used
    BUILTIN_SCANNER_TYPE scanner_type;

    // TODO
    // other arguments may be required
};

class ExternCommand : public Command{
public:
    void exec() override;
    ExternCommand(string scanner_name, Task &task);
};

#endif //SWARMRAY_COMMAND_H
