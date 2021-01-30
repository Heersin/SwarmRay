//
// Created by heersin on 1/30/21.
// C style code for pluging implement
//

#ifndef SWARMRAY_TASK_H
#define SWARMRAY_TASK_H
#include <string>

using namespace std;

// TODO Add more Lang Type
enum LANG_TYPE {C, CPP, PHP};

class Task {
public:
    Task();

    void addFileIntoQueue(char *filename);
    void addFileIntoQueue(string filename);

    char** getQueuedFiles();
    int getQueueLength();
    int getCurrentNo();

private:
    // record the number of current task queue
    char **file_paths;
    int file_path_len;
    int cur_file_num;

    LANG_TYPE lang_type;
};


#endif //SWARMRAY_TASK_H
