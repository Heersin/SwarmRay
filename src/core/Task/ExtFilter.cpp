//
// Created by heersin on 1/27/21.
//

#include "ExtFilter.h"

ExtFilter::ExtFilter() {
    // TODO
    // conf parser
    // assume we have parsed it
    filter_accept.insert(pair<string, LANG_TYPE>(".c", CPP));
    filter_accept.insert(pair<string, LANG_TYPE>(".cpp", CPP));
    filter_accept.insert(pair<string, LANG_TYPE>(".js", JAVASCRIPT));
}

bool ExtFilter::is_in_accept(const string &path_ext) {
    if (filter_accept.count(path_ext) == 0)
        return false;
    else
        return true;
}

LANG_TYPE ExtFilter::get_class(const string &path_ext) {
    return filter_accept[path_ext];
}