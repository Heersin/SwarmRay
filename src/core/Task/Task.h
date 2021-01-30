//
// Created by heersin on 1/30/21.
//

#ifndef SWARMRAY_TASK_H
#define SWARMRAY_TASK_H


class Task {
public:
    char** getFilePaths();

private:
    // record the number of current task queue
    int tsk_queue_len;
    int cur_tsk_num;
    int scanner_type;

};


#endif //SWARMRAY_TASK_H
