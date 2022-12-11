//
// Created by leanfe on 11.12.22.
//

#include <utility>

#include "../../headers/ConfigManager.h"

namespace Configuration {

    IConfiguration ConfigManager::getConfiguration(ConfigurationType type, std::string id) {
        return {type, std::move(id)};
    }
} // Configuration