//
// Created by heersin on 1/27/21.
//

#include "PathGenerator.h"
PathGenerator::PathGenerator() {
    target_path_name = nullptr;
}

PathGenerator::PathGenerator(const string &path_name) : target_path(path_name) {
    target_path_name = path_name;
}

void PathGenerator::create_unique_path(const string &path_name) {
    target_path_name = path_name;
    target_path = path(path_name);
}

bool PathGenerator::recur_search_add(const path &dir) {
    directory_iterator end;
    for (directory_iterator pos(dir); pos != end; ++pos)
    {
        if (is_directory(*pos))
            recur_search_add((*pos).path());
        else{
            cout << (*pos).path() << endl;
            all_files.push_back((*pos).path());
        }
    }
    return true;
}

bool PathGenerator::build_target_files(ExtFilter &white_list) {
    vector<path>::iterator i;
    string extension;

    for(i = all_files.begin(); i != all_files.end(); ++i)
    {
        // get the extension of current file
        extension = (*i).extension().string();

        // not the extension we r searching for
        if (!white_list.is_in_accept(extension))
            continue;

        // store the full file path in multimap
        // key: <extension name> value: <file paths>
        all_target_files.insert(make_pair(extension, (*i)));
    }
    return true;
}