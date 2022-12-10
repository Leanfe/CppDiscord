//
// Created by leanfe on 10.12.22.
//

#ifndef DISCORD_BOT_SERVICEHELPER_H
#define DISCORD_BOT_SERVICEHELPER_H

#include <string>
#include <sleepy_discord/websocketpp_websocket.h>

namespace Service {

    class Daemon {
    public:
        Daemon() = default;
        ~Daemon() = default;

        [[noreturn]] static void doWork(SleepyDiscord::DiscordClient *client);

        void daemon(SleepyDiscord::DiscordClient *client);
    private:
        FILE *out;
        bool setLogFile();
    };

    class ServiceHelper {
    public:
        ServiceHelper() = default;
        ~ServiceHelper() = default;

        void initService(SleepyDiscord::DiscordClient *client);

        [[nodiscard]] bool isServiceHas() const;
    private:
        bool serviceHas = false;
    };

} // Service

#endif //DISCORD_BOT_SERVICEHELPER_H
