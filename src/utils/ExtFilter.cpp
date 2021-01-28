//
// Created by heersin on 1/27/21.
//

#include "ExtFilter.h"
ExtFilter::ExtFilter() {}

ExtFilter::ExtFilter(string &conf) {
    // TODO
    // conf parser
    // assume we have parsed it

    filter_accept.insert(pair<string, string>(".php", ".php"));
    filter_accept.insert(pair<string, string>(".php5", ".php"));
    filter_accept.insert(pair<string, string>(".c", ".cpp"));
    filter_accept.insert(pair<string, string>(".cpp", ".cpp"));
    filter_accept.insert(pair<string, string>(".java", ".java"));
}

bool ExtFilter::is_in_accept(string &path_ext) {
    if (filter_accept.count(path_ext) == 0)
        return false;
    else
        return true;
}

string ExtFilter::get_class(string &path_ext) {
    return filter_accept[path_ext];
}