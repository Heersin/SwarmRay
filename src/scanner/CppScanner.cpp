//
// Created by heersin on 2/1/21.
//

#include "BaseScanner.h"
bool CppScanner::scan(void *mem) {
    return true;
}

bool CppScanner::scan(string filename) {
    printf("Scanning file %s\n", filename.c_str());
    return true;
}

bool CppScanner::scan(char *filename) {
    return true;
}