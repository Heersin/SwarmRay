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
    ProcManager externManager;
    ProcManager threadManager;

    // USE EXTERN TOOL
    if (appConfig.use_extern_scan())
    {
        vector<string> py_args;
        py_args.push_back(appConfig.getPluginSysName());
        py_args.push_back(appConfig.getTargetPath());       // target path
        externManager.launchProc(PYTHON_PLUGIN, py_args);
    }

    // USE BUILTIN TECHNIQUE
    SearchScannerFactory srh_factory;
    SyntaxScannerFactory syn_factory;
    TaskManger task_manager(appConfig.getTargetPath());

    int tmp = 0;

    while (!task_manager.no_more_task())
    {
        LOG(DEBUG) << "process task ... ";
        Task current_task = task_manager.fetch_one_task();

        for (int i = 0; i < current_task.getCurrentNo(); ++i)
            printf("[Run %d] Task File [%d]: %s\n",tmp, i, (current_task.getQueuedFiles())[i].c_str());

        // USE BUILTIN SCAN
        if (appConfig.use_search_scan())
        {
            LOG(DEBUG) << "search scan";
            BuiltInCommand command(srh_factory, current_task);
            threadManager.launchTread(command);
        }

        if (appConfig.use_syntax_scan())
        {
            LOG(DEBUG) << "Syntax scan";
            BuiltInCommand command(syn_factory, current_task);
            threadManager.launchTread(command);
        }

        LOG(DEBUG) << "One Task Done";

        tmp += 1;

        //task_manager.pop_one_task();
    }
}