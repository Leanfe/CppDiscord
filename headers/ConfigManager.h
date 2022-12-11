//
// Created by leanfe on 11.12.22.
//

#pragma once

#ifndef DISCORD_BOT_CONFIGMANAGER_H
#define DISCORD_BOT_CONFIGMANAGER_H

#include <string>
#include "IConfiguration.h"
#include "ConfigurationTypes.h"

namespace Configuration {

    class ConfigManager {
    public:
        ConfigManager() = default;
        ~ConfigManager() = default;

        IConfiguration getConfiguration(ConfigurationType type, std::string id);
    };

} // Configuration

#endif //DISCORD_BOT_CONFIGMANAGER_H
