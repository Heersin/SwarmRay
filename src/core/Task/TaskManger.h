//
// Created by heersin on 1/31/21.
//

#ifndef SWARMRAY_TASKMANGER_H
#define SWARMRAY_TASKMANGER_H

#include "Task.h"

#include <string>
#include <vector>
#include "ExtFilter.h"
#include "../../utils/PathGenerator.h"
#include "../langs.h"
#include <queue>
#include <exception>
using namespace std;

// single instance Task Manager

class TaskManger {
public:
    TaskManger(string &target_path);
    bool no_more_task();
    Task &fetch_one_task();

private:
    ExtFilter white_list;
    PathGenerator pathGenerator;
    queue<Task> task_queue;
    multimap<LANG_TYPE, string> target_files;

    bool createTaskQueue();

};


#endif //SWARMRAY_TASKMANGER_H
