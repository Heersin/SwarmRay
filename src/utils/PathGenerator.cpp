//
// Created by heersin on 1/27/21.
//

#include "PathGenerator.h"
PathGenerator::PathGenerator() {
    target_path_name = nullptr;
    total_filenum = 0;
}

PathGenerator::PathGenerator(const string &path_name) : target_path(path_name) {
    target_path_name = path_name;
    recur_search_add(target_path);
}

void PathGenerator::create_unique_path(const string &path_name) {
    target_path_name = path_name;
    target_path = path(target_path_name);
}

bool PathGenerator::recur_search_add(const path &dir) {
    directory_iterator end;
    for (directory_iterator pos(dir); pos != end; ++pos)
    {
        if (is_directory(*pos))
            recur_search_add((*pos).path());
        else{
            cout << (*pos).path() << endl;
            all_file_paths.push_back((*pos).path());
            total_filenum += 1;
        }
    }
    return true;
}


const string &PathGenerator::getTargetPathName() const {
    return target_path_name;
}

vector<path> &PathGenerator::getAllFilePaths(){
    return all_file_paths;
}

int PathGenerator::getTotalFilenum() const {
    return total_filenum;
}
