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
    string getString(const string &section, const string &keyname);
    long getInt(const string &section, const string &keyname);
    double getReal(const string &section, const string &keyname);
    bool getBool(const string &section, const string &keyname);

private:
    INIReader reader;
};


#endif //SWARMRAY_CONFIGREADER_H
