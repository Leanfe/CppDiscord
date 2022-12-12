//
// Created by leanfe on 11.12.22.
//
#include "../../headers/RconConfiguration.h"

#include "../../headers/properties/Properties.h"

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

    void RconConfiguration::declareValues() {
        // Лезем в пропертиес.
    }

}