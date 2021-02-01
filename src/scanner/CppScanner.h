//
// Created by heersin on 2/1/21.
//

#ifndef SWARMRAY_CPPSCANNER_H
#define SWARMRAY_CPPSCANNER_H

#include "BaseScanner.h"

class CppScanner : BaseScanner{
public:
    // TODO CPP Scanner
    bool scan(void *mem) override;
    bool scan(string filename) override;
    bool scan(char *filename) override;
};


#endif //SWARMRAY_CPPSCANNER_H
