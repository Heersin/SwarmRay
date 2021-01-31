//
// Created by heersin on 1/31/21.
//

#include "TaskManger.h"
TaskManger::TaskManger(string &target_path) : white_list(), pathGenerator(target_path)
{
    string extension;
    const vector<path> &all_files = pathGenerator.getAllFilePaths();

    for(auto i = all_files.begin(); i != all_files.end(); ++i)
    {
        // get the extension of current file
        extension = (*i).extension().string();

        // not the extension we r searching for
        if (!white_list.is_in_accept(extension))
            continue;

        // store the full file path in multimap
        // key: <LANG_TYPE> value: <file path string>
        target_files.insert(
                make_pair(
                        white_list.get_class(extension),
                        (*i).string()));
    }
}

bool TaskManger::createTaskQueue()
{
    // TODO traverse map to dispatch paths to different tasks
}

bool TaskManger::no_more_task()
{
    if (task_queue.empty())
        return true;
    return false;
}

Task & TaskManger::fetch_one_task()
{
    // TODO more exception
    if (task_queue.empty())
        throw exception();

    Task &cur_task = task_queue.front();
    task_queue.pop();
    return cur_task;
}