//
// Created by heersin on 1/27/21.
//

#ifndef SWARMRAY_EXTFILTER_H
#define SWARMRAY_EXTFILTER_H

#include <map>
#include <string>
#include <iostream>

using namespace std;

class ExtFilter {
public:
    ExtFilter();
    explicit ExtFilter(const string &conf);     // use boost to parse config

    bool is_in_accept(string &path_ext);
    string get_class(string &path_ext);

private:
    map<string, string> filter_accept;
};


#endif //SWARMRAY_EXTFILTER_H
