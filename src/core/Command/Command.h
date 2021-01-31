//
// Created by heersin on 1/30/21.
//

#ifndef SWARMRAY_COMMAND_H
#define SWARMRAY_COMMAND_H

#include "../Task/Task.h"
#include "../langs.h"

class Command {
public:
    virtual void exec() = 0 ;
    virtual ~Command() = default;
};

class BuiltInCommand : public Command{
public:
    void exec() override;
    BuiltInCommand(BUILTIN_SCANNER_TYPE scannerType, Task &task);

    BUILTIN_SCANNER_NAME getScannerName() const;

    Task &getCommandTask() const;

    BUILTIN_SCANNER_TYPE getScannerType() const;

private:
    // detect which type of scanner should be used
    BUILTIN_SCANNER_TYPE scanner_type;
    LANG_TYPE lang_type;
    BUILTIN_SCANNER_NAME scanner_name;
    Task &command_task;

    // TODO
    // other arguments may be required
};

class ExternCommand : public Command{
public:
    void exec() override;
    ExternCommand(string scanner_name, Task &task);
};

#endif //SWARMRAY_COMMAND_H
