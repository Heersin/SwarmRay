//
// Created by heersin on 1/28/21.
//

#include "ConfigReader.h"

ConfigReader::ConfigReader(string &conf_path) : reader(conf_path)
{
    if (reader.ParseError() < 0)
    {
        cerr << "can't load init file" << endl;
        exit(-1);
    }
}

bool ConfigReader::getBool(string &section, string &keyname)
{
    return reader.GetBoolean(section, keyname, false);
}

long ConfigReader::getInt(string &section, string &keyname)
{
    return reader.GetInteger(section, keyname, -1);
}

double ConfigReader::getReal(string &section, string &keyname)
{
    return reader.GetReal(section, keyname, -1);
}

string ConfigReader::getString(string &section, string &keyname)
{
    return reader.Get(section, keyname, "UNKNOWN");
}