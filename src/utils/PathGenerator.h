//
// Created by heersin on 1/27/21.
// Recursive Explore A given path
// get all file's paths
//

#ifndef SWARMRAY_PATHGENERATOR_H
#define SWARMRAY_PATHGENERATOR_H
#include <boost/filesystem.hpp>
#include <cstring>
#include <iostream>
#include "ExtFilter.h"
using namespace boost::filesystem;
using namespace std;


class PathGenerator {
public:
    explicit PathGenerator(const string &path_name);
    PathGenerator();
    void create_unique_path(const string &path_name);
    bool collectAllFiles();

    const multimap<string, path> &getAllTargetFiles() const;

    const vector<path> &getAllFiles() const;

    const string &getTargetPathName() const;

private:
    multimap<string, path> all_target_files;
    vector<path> all_files;
    string target_path_name;
    path target_path;
    ExtFilter white_list;

    bool recur_search_add(const path& dir);
    bool build_target_files();
};



#endif //SWARMRAY_PATHGENERATOR_H
