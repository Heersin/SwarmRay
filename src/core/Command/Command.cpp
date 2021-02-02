//
// Created by heersin on 1/30/21.
//

#include "Command.h"

BuiltInCommand::BuiltInCommand(SearchScannerFactory &src_scanner_factory, Task &task) :
command_task(task), factory(src_scanner_factory)
{
    scanner_type = SEARCH;
    lang_type = task.getLangType();
}

BuiltInCommand::BuiltInCommand(SyntaxScannerFactory &syn_scanner_factory, Task &task) :
command_task(task), factory(syn_scanner_factory)
{
    scanner_type = SYNTAX;
    lang_type = task.getLangType();
}

void BuiltInCommand::exec()
{
    int queue_len = command_task.getCurrentNo();
    vector<string> queue = command_task.getQueuedFiles();
    printf("execting command\n");
    for (int i = 0; i < queue_len; ++i)
    {
        switch (lang_type)
        {
            case CPP:
                factory.createCppScanner().scan(queue[i]);
                break;
            case JAVASCRIPT:
                factory.createJsScanner().scan(queue[i]);
                break;
            case UNKNOWN_LANG:
                break;
            default:
                break;
        }
    }
}

