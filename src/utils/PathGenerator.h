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
#include "../core/Task/ExtFilter.h"
using namespace boost::filesystem;
using namespace std;


class PathGenerator {
public:
    explicit PathGenerator(const string &path_name);
    PathGenerator();
    void create_unique_path(const string &path_name);

    vector<path> &getAllFilePaths();
    const string &getTargetPathName() const;

private:
    vector<path> all_file_paths;
    string target_path_name;
    path target_path;
    int total_filenum;
public:
    int getTotalFilenum() const;

private:

    bool recur_search_add(const path& dir);
};



#endif //SWARMRAY_PATHGENERATOR_H
