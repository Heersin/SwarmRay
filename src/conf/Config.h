//
// Created by heersin on 1/31/21.
//

#ifndef SWARMRAY_CONFIG_H
#define SWARMRAY_CONFIG_H

#include "ConfigReader.h"
#include "../core/langs.h"

class Config {
public:
    Config(string &conf_path);
    Config(); // test only

    const string &getConfigName() const;
    const string &getTargetPath() const;
    const string &getPluginSysName() const;

    bool use_search_scan();
    bool use_syntax_scan();
    bool use_extern_scan();



private:
    // TODO design Config
    string config_name;
    string target_path;

    string plugin_sys_name;

    bool switch_search_on;
    bool switch_syntax_on;
    bool switch_extern_on;

};


#endif //SWARMRAY_CONFIG_H
