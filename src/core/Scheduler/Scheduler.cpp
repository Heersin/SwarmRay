//
// Created by heersin on 1/31/21.
//

#include "Scheduler.h"

Scheduler::Scheduler(Config &app_config) : appConfig(app_config)
{}

// TODO Schedule these ProcManager
// and manage them
void Scheduler::schedule()
{
    SearchScannerFactory srh_factory;
    SyntaxScannerFactory syn_factory;
    TaskManger task_manager(appConfig.getTargetPath());

    while (!task_manager.no_more_task())
    {
        Task &current_task = task_manager.fetch_one_task();

        // USE BUILTIN SCAN
        if (appConfig.use_search_scan())
        {
            BuiltInCommand command(srh_factory, current_task);
            ProcManager procManager(command);
        }

        if (appConfig.use_syntax_scan())
        {
            BuiltInCommand command(syn_factory, current_task);
            ProcManager procManager(command);
        }

        if (appConfig.use_extern_scan())
        {
            ExternCommand command(appConfig.getExternScannerName(), current_task);
            ProcManager procManager(command);
        }
    }
}