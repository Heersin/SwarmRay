//
// Created by heersin on 1/26/21.
//

#ifndef SWARMRAY_CMDPARSER_H
#define SWARMRAY_CMDPARSER_H

#include <boost/program_options.hpp>
#include <cstring>
#include <iostream>
using namespace boost::program_options;
using namespace std;


class CmdParser {
public:
    string config_path;
    string scan_target;

    CmdParser();
    bool parse(int argc, char *argv[]);

private:
    options_description opts;
    variables_map vm;
};


#endif //SWARMRAY_CMDPARSER_H
