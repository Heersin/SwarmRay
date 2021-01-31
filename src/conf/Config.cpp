//
// Created by heersin on 1/31/21.
//

#include "Config.h"

Config::Config(string &conf_path)
{
    ConfigReader conf_reader(conf_path);

    // An example
    config_name = conf_reader.getString("basic", "name");
}

const string &Config::getConfigName() const {
    return config_name;
}