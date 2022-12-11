#include "sleepy_discord/sleepy_discord.h"
#include "../headers/EmbedHelper.h"

#include "../headers/Settings.h"

#include "../headers/service/ServiceHelper.h"

using namespace SleepyDiscord;

using namespace Service;
using namespace Options;

class MyClientClass : public SleepyDiscord::DiscordClient {
public:
    using SleepyDiscord::DiscordClient::DiscordClient;

    void onMessage(SleepyDiscord::Message message) override {
        if (!message.startsWith(options.prefix))
            return;

        message.content.replace(0, options.prefix.size(), "");
        if (message.content == "hello") {
            sendMessage(options.channelID, "Hello, " + message.author.username);
        }

        if (message.content == "information") {
            sendMessage(options.channelID, "", buildEmbed());
        }

        if (message.content == "rcon") {
            sendMessage(options.channelID, "Check available configs...", buildEmbed());
            sleep(300);

        }
    }

};

int main() {
    MyClientClass client("MTA0ODAwMjA1NTE5MDYyNjM0NQ.GfD8bX._nFDx6KOLDu8SHg8eS2TC0vwHJ5JiyVgmhbcGE", SleepyDiscord::USER_CONTROLED_THREADS);

    client.setIntents(SleepyDiscord::Intent::DIRECT_MESSAGES, SleepyDiscord::Intent::DIRECT_MESSAGE_REACTIONS);

    ServiceHelper helper = ServiceHelper();

    if (!helper.isServiceHas())
        helper.initService(&client);

    //client.run();

    return EXIT_SUCCESS;
}