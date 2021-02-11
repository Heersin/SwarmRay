//
// Created by heersin on 1/31/21.
//

#include "Config.h"

Config::Config(string &conf_path)
{
    ConfigReader conf_reader(conf_path);

    // An example
    config_name = conf_reader.getString("basic", "name");
    config_name = "fake";

    // TODO getBool from config file
    switch_syntax_on = true;
    switch_search_on = true;
    switch_extern_on = true;

}

Config::Config() : target_path("code_files")
{
    switch_syntax_on = false;
    switch_search_on = false;
    switch_extern_on = true;
    plugin_sys_name = "plugin_sys_main.py";
}

const string &Config::getConfigName() const {
    return config_name;
}

const string & Config::getTargetPath() const {
    return target_path;
}

const string & Config::getPluginSysName() const {
    return plugin_sys_name;
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

