//
// Created by heersin on 2/1/21.
//

#include "BaseScanner.h"
// TODO Finish scan method
bool JavascriptScanner::scan(void *mem) {
    return true;
}

bool JavascriptScanner::scan(char *filename) {
    return true;
}

bool JavascriptScanner::scan(string filename) {
    printf("Scanning file %s\n", filename.c_str());
    return true;
}
