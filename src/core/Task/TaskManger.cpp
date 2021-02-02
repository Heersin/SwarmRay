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

    int number_of_current_lang_files;
    int tmp_cnt;                            // count number of files of current task
    for (int lang = CPP; lang != UNKNOWN_LANG; ++lang)
    {
        LANG_TYPE current_lang = static_cast<LANG_TYPE>(lang);
        number_of_current_lang_files = target_files.count(current_lang);

        // traverse the target file specified by CURRENT LANGUAGE TYPE
        pair<TARGET_FILE_ITER, TARGET_FILE_ITER> ret = target_files.equal_range(current_lang);
        Task current_task(current_lang, MAX_WORKER);
        printf("init Done\n");
        for(auto iter=ret.first; iter != ret.second; ++iter)
        {
            // task should contain [MAX_WORKER] files // aka 5 files now
            if (current_task.getCurrentNo() < MAX_WORKER)
            {
                printf("Start Add File\n");
                current_task.addFileIntoQueue((*iter).second);
                printf("Add One File Into Current Task\n");
            }
        }

        // add task to TaskManager's queue
        task_queue.push(current_task);
    }
    return true;
}

bool TaskManger::no_more_task()
{
    if (!task_queue.size())
    {
        printf("mo more task\n");
        return true;
    }

    printf("still have task\n");
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

    printf("ok to get front\n");

    // task_queue.pop();

    printf("pop this\n");
    return cur_task;
}

void TaskManger::pop_one_task() {
    task_queue.pop();
}

void TaskManger::echo()
{
    printf("I'm still here\n");
}