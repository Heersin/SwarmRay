//
// Created by heersin on 1/31/21.
//

#include "Config.h"

Config::Config(string &conf_path)
{
    ConfigReader conf_reader(conf_path);

    // An example
    config_name = conf_reader.getString("basic", "name");

    // TODO getBool from config file
    switch_syntax_on = true;
    switch_search_on = true;
    switch_extern_on = true;

    // TODO construct extern map from config file
}

const string &Config::getConfigName() const {
    return config_name;
}

const string & Config::getTargetPath() const {
    return target_path;
}

bool Config::use_extern_scan() {
    return switch_extern_on;
}

bool Config::use_search_scan() {
    return switch_search_on;
}

bool Config::use_syntax_scan() {
    return switch_syntax_on;
}

const map<LANG_TYPE, string> &Config::getExternProgMap() const {
    return extern_prog_map;
}
