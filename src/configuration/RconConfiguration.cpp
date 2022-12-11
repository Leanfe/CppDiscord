//
// Created by leanfe on 11.12.22.
//
#include "../../headers/RconConfiguration.h"

namespace Configuration {

    std::string RconConfiguration::getHost() {
        return host;
    }

    std::string RconConfiguration::getPort() {
        return port;
    }

    std::string RconConfiguration::getPassword() {
        return password;
    }

    void RconConfiguration::readValues() {
        // TODO
    }
}