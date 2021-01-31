//
// Created by heersin on 1/31/21.
//

#ifndef SWARMRAY_CONFIG_H
#define SWARMRAY_CONFIG_H

#include "ConfigReader.h"

class Config {
public:
    Config(string &conf_path);

    const string &getConfigName() const;
    const string &getTargetPath() const;

    bool use_search_scan();
    bool use_syntax_scan();
    bool use_extern_scan();

    const string &getExternScannerName() const;

private:
    // TODO design Config
    string config_name;
    string target_path;

    bool switch_search_on;
    bool switch_syntax_on;
    bool switch_extern_on;

    string extern_prog;
};


#endif //SWARMRAY_CONFIG_H
