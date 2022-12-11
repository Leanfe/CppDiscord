//
// Created by leanfe on 11.12.22.
//

#pragma once

#ifndef DISCORD_BOT_RCONCONFIGURATION_H
#define DISCORD_BOT_RCONCONFIGURATION_H

#include <utility>

#include "IConfiguration.h"

namespace Configuration {
    class RconConfiguration : IConfiguration {
    public:
        explicit RconConfiguration(std::string id) : IConfiguration(RCON, std::move(id)) {
            readValues();
        }

        std::string getHost();
        std::string getPort();
        std::string getPassword();

    private:
        std::string host;
        std::string port;
        std::string password;

        void readValues();
    };
}

#endif //DISCORD_BOT_RCONCONFIGURATION_H
