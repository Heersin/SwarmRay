//
// Created by heersin on 1/28/21.
//

#ifndef SWARMRAY_CONFIGREADER_H
#define SWARMRAY_CONFIGREADER_H

#include <iostream>
#include <cstring>
#include "../libs/inih/INIReader.h"
using namespace std;

class ConfigReader {
public:
    explicit ConfigReader(string &conf_path);
    string getString(string &section, string &keyname);
    long getInt(string &section, string &keyname);
    double getReal(string &section, string &keyname);
    bool getBool(string &section, string &keyname);

private:
    INIReader reader;
};


#endif //SWARMRAY_CONFIGREADER_H
