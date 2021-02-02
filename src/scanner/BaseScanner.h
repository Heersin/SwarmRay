//
// Created by heersin on 1/30/21.
//

#ifndef SWARMRAY_BASESCANNER_H
#define SWARMRAY_BASESCANNER_H

#include<string>
using namespace std;

enum BUILTIN_SCANNER_TYPE {SEARCH, SYNTAX};

class BaseScanner {
public:
    virtual bool scan(string filename) = 0;
    virtual bool scan(char *filename) = 0;
    virtual bool scan(void *mem) = 0;
};


class CppScanner : BaseScanner{
public:
    // TODO CPP Scanner
    bool scan(void *mem) override;
    bool scan(string filename) override;
    bool scan(char *filename) override;
};

class JavascriptScanner : BaseScanner{
    // TODO JAVASCRIPT Scanner
public:
    bool scan(char *filename) override;
    bool scan(string filename) override;
    bool scan(void *mem) override;
};

#endif //SWARMRAY_BASESCANNER_H
