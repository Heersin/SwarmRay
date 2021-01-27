//
// Created by heersin on 1/27/21.
//

#ifndef SWARMRAY_PATHGENERATOR_H
#define SWARMRAY_PATHGENERATOR_H
#include <boost/filesystem.hpp>
#include <cstring>
#include <iostream>
#include "extFilter.h"
using namespace boost::filesystem;
using namespace std;


class PathGenerator {
public:
    PathGenerator(string path_name);
    PathGenerator();
    void create_unique_path(string path_name);

private:
    map<string , vector<path>> all_target_files;
    vector<path> all_files;
    string target_path_name;
    path target_path;

    bool recur_search_add(const path& dir);
    bool build_target_files(extFilter &white_list);
};



#endif //SWARMRAY_PATHGENERATOR_H
