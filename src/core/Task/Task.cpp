//
// Created by heersin on 1/30/21.
//

#include "Task.h"
#include <cstdlib>
#include "../../log/ezlog.h"

int Task::getCurrentNo() {
    return cur_file_num;
}

int Task::getQueueLength() {
    return queue_len;
}

vector<string> Task::getQueuedFiles() {
    return file_paths;
}

LANG_TYPE Task::getLangType() {
    return lang_type;
}

void Task::addFileIntoQueue(char *filename)
{
    // TODO Exception ?
    if (cur_file_num < queue_len)
    {
        file_paths[cur_file_num] = filename;
        cur_file_num += 1;
    }
    LOG(DEBUG) << "Cannot Add More";
}

void Task::addFileIntoQueue(const string &filename)
{
    if (cur_file_num < queue_len)
    {
        file_paths.push_back(filename);
        cur_file_num += 1;
    }
}

// not recommend
Task::Task() {
    queue_len = 0;
    cur_file_num = 0;
    lang_type = UNKNOWN_LANG;
}

Task::Task(LANG_TYPE type, int queue_length)
{
    LOG(DEBUG) << "init A task";

    queue_len = queue_length;
    cur_file_num = 0;

    lang_type = type;
}




