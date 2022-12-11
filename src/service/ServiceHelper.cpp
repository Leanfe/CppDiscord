//
// Created by leanfe on 10.12.22.
//

#include "../../headers/service/ServiceHelper.h"
#include "../../headers/Settings.h"

namespace Service {

    void ServiceHelper::initService(SleepyDiscord::DiscordClient *client) {
        Daemon().daemon(client);
    }

    bool ServiceHelper::isServiceHas() const {
        return serviceHas;
    }

    [[noreturn]] void Daemon::doWork(SleepyDiscord::DiscordClient *client) {
        client->run();

        while (true) {
            if (!client->isReady()) {
                std::cout << "Starting.." << std::endl;
            }
            std::cout << "Started!" << std::endl;
        }
    }

    void Daemon::daemon(SleepyDiscord::DiscordClient *client) {
        bool result = setLogFile();
        if (!result)
            perror("Can't write to log file!");

        doWork(client);

    }

    bool Daemon::setLogFile() {
        out = fopen("/tmp/bot.log", "w");
        if (out == nullptr)
            return false;
        return true;
    }
} // Service