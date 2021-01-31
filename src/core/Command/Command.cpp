//
// Created by heersin on 1/30/21.
//

#include "Command.h"
BuiltInCommand::BuiltInCommand(BUILTIN_SCANNER_TYPE scannerType, Task &task) : command_task(task) {
    scanner_type = scannerType;
    lang_type = task.getLangType();

    // choose scanner
    scanner_name = get_scanner_name_by_lang_scanner_type(lang_type, scannerType);
}

BUILTIN_SCANNER_TYPE BuiltInCommand::getScannerType() const {
    return scanner_type;
}

BUILTIN_SCANNER_NAME BuiltInCommand::getScannerName() const {
    return scanner_name;
}

Task &BuiltInCommand::getCommandTask() const {
    return command_task;
}
