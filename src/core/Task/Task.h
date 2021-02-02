//
// Created by heersin on 1/30/21.
// C style code for pluging implement
//

#ifndef SWARMRAY_TASK_H
#define SWARMRAY_TASK_H
#include <string>
#include "../langs.h"
#include <vector>

using namespace std;


class Task {
public:
    Task();
    Task(LANG_TYPE type, int queue_length);

    void addFileIntoQueue(char *filename);
    void addFileIntoQueue(string filename);

    vector<string> getQueuedFiles();
    int getQueueLength();
    int getCurrentNo();
    LANG_TYPE getLangType();

private:
    // record the number of current task queue
    vector<string> file_paths;
    int queue_len;
    int cur_file_num;

    LANG_TYPE lang_type;
};


#endif //SWARMRAY_TASK_H
