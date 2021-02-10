//
// Created by heersin on 1/31/21.
//

#include "TaskManger.h"
TaskManger::TaskManger(const string &target_path) : white_list(), pathGenerator(target_path)
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

        printf("[*]Accept %s\n", (*i).c_str());
        // store the full file path in multimap
        // key: <LANG_TYPE> value: <file path string>
        target_files.insert(
                make_pair(
                        white_list.get_class(extension),
                        (*i).string()));
    }

    // TODO exception handle
    createTaskQueue();
}


// traverse over map to create a task queue
bool TaskManger::createTaskQueue()
{
    // TODO Exception Handle
    // TODO config control
    // maximum threads
    const int MAX_WORKER = 5;
    // iterate over different language type

    for (int lang = CPP; lang != UNKNOWN_LANG; ++lang)
    {
        LANG_TYPE current_lang = static_cast<LANG_TYPE>(lang);

        // traverse the target file specified by CURRENT LANGUAGE TYPE
        pair<TARGET_FILE_ITER, TARGET_FILE_ITER> ret = target_files.equal_range(current_lang);
        Task current_task(current_lang, MAX_WORKER);
        printf("init Done\n");
        for(auto iter=ret.first; iter != ret.second; ++iter)
        {
            // task can contain [MAX_WORKER] files at most
            // aka 5 files now
            printf("LANG : %d, FILENAME: %s\n", (*iter).first, (*iter).second.c_str());

            if (current_task.getCurrentNo() >= MAX_WORKER)
            {
                task_queue.push(current_task);
                current_task = Task(current_lang, MAX_WORKER);
                continue;
            }

            current_task.addFileIntoQueue((*iter).second);
        }

        // if the last task contains less than MAX_WORKER files
        // push it
        if (current_task.getCurrentNo() != 0)
            task_queue.push(current_task);
    }
    return true;
}

bool TaskManger::no_more_task()
{
    if (!task_queue.size())
        return true;

    return false;
}

Task TaskManger::fetch_one_task()
{
    // TODO more exception
    if (task_queue.empty())
    {
        printf("Empty Task Queue!!!\n");
        throw exception();
    }


    Task cur_task = task_queue.front();
    task_queue.pop();
    return cur_task;
}

void TaskManger::pop_one_task() {
    task_queue.pop();
}
