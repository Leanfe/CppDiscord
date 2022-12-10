//
// Created by leanfe on 10.12.22.
//

#include <utility>
#include <iostream>
#include <stdexcept>
#include <cstdio>
#include <string>
#include <sys/utsname.h>

#include "sleepy_discord/sleepy_discord.h"

#ifndef DISCORD_BOT_CREDITIANALS_H
#define DISCORD_BOT_CREDITIANALS_H

namespace Options {

    class OptionMemory {
    public:

        OptionMemory();

        ~OptionMemory() = default;

        // DISCORD API;
        const SleepyDiscord::Snowflake<SleepyDiscord::Channel> channelID = 1050385700614307930;
        const std::string prefix = "?";

        // Native (Get definition after SystemInformation work.)
        std::string systemName;
        std::string nodeName;
        std::string domain;

        std::string release;
        std::string version;
        std::string machine;

        std::string distributive = getDistro();
        std::string distroIcon = getDistroIcon();

    private:
        std::string cmd = R"(for f in $(find /etc -type f -maxdepth 1 \( ! -wholename /etc/os-release ! -wholename /etc/lsb-release -wholename /etc/\*release -o -wholename /etc/\*version \) 2> /dev/null); do echo ${f:5:${#f}-13}; done;)";
        [[nodiscard]] std::string getDistro() const;

        [[nodiscard]] std::string getDistroIcon() const;
    };

}

static Options::OptionMemory options = Options::OptionMemory();

#endif //DISCORD_BOT_CREDITIANALS_H
