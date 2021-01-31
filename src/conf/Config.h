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

private:
    // TODO design Config
    string config_name;
};


#endif //SWARMRAY_CONFIG_H
