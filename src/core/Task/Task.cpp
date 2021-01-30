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

char ** Task::getQueuedFiles() {
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

void Task::addFileIntoQueue(string filename)
{
    if (cur_file_num < queue_len)
    {
        file_paths[cur_file_num] = (char *)filename.c_str();
        cur_file_num += 1;
    }
}

// not recommend
Task::Task() {
    file_paths = NULL;
    queue_len = 0;
    cur_file_num = 0;
    lang_type = UNKNOWN_LANG;
}

Task::Task(LANG_TYPE type, int queue_length)
{
    file_paths = (char **)malloc(queue_length * sizeof(char *));
    LOG(DEBUG) << "fail to init Task";

    queue_len = queue_length;
    cur_file_num = 0;

    lang_type = type;
}

Task::~Task()
{
    // do not free the string stored inside
    // they may be const
    if (file_paths != NULL)
        free(file_paths);

    cur_file_num = 0;
    file_paths = NULL;
    queue_len = 0;
}



