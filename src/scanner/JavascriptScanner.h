//
// Created by heersin on 2/1/21.
//

#ifndef SWARMRAY_JSSCANNER_H
#define SWARMRAY_JSSCANNER_H

#include "BaseScanner.h"

class JavascriptScanner : BaseScanner{
    // TODO JAVASCRIPT Scanner
public:
    bool scan(char *filename) override;
    bool scan(string filename) override;
    bool scan(void *mem) override;
};


#endif //SWARMRAY_JSSCANNER_H
