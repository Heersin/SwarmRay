//
// Created by heersin on 1/30/21.
//

#ifndef SWARMRAY_BASESCANNER_H
#define SWARMRAY_BASESCANNER_H

#include<string>
using namespace std;

enum BUILTIN_SCANNER_TYPE {SEARCH, SYNTAX};

enum BUILTIN_SCANNER_NAME {
    CPP_SEARCH_SCANNER = 0,
    CPP_SYNTAX_SCANNER,
    JAVASCRIPT_SEARCH_SCANNER,
    JAVASCRIPT_SYNTAX_SCANNER,
};

class BaseScanner {
public:
    virtual bool scan(string filename) = 0;
    virtual bool scan(char *filename) = 0;
    virtual bool scan(void *mem) = 0;
};

class JavascriptScanner : BaseScanner{
    // TODO JAVASCRIPT Scanner
    bool scan(char *filename) override;
    bool scan(string filename) override;
    bool scan(void *mem) override;
};

class CppScanner : BaseScanner{
    // TODO CPP Scanner
    bool scan(void *mem) override;
    bool scan(string filename) override;
    bool scan(char *filename) override;
};

#endif //SWARMRAY_BASESCANNER_H
