//
// Created by heersin on 1/27/21.
//

#ifndef SWARMRAY_EXTFILTER_H
#define SWARMRAY_EXTFILTER_H

#include <map>
#include <string>
#include <iostream>
#include "../langs.h"

using namespace std;

class ExtFilter {
public:
    ExtFilter();
    // explicit ExtFilter(const string &conf);     // use boost to parse config

    bool is_in_accept(const string &path_ext);
    LANG_TYPE get_class(const string &path_ext);

private:
    map<string, LANG_TYPE> filter_accept;
};


#endif //SWARMRAY_EXTFILTER_H
