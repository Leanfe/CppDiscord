#include "sleepy_discord/sleepy_discord.h"

using namespace SleepyDiscord;

class MyClientClass : public SleepyDiscord::DiscordClient {
public:
    using SleepyDiscord::DiscordClient::DiscordClient;

    void onMessage(SleepyDiscord::Message message) override {
        if (!message.startsWith(prefix))
            return;

        message.content.replace(0, prefix.size(), "");
        if (message.content == "hello") {
            sendMessage(channelID, "Hello, " + message.author.username);
        }

    }
private:
    Snowflake<Channel> channelID = 1050385700614307930;
    std::string prefix = "?";
};

int main() {
    MyClientClass client("MTA0ODAwMjA1NTE5MDYyNjM0NQ.GHFeoL.YUUAa2e07vJJJzAMurU2qTvEUDtwmH8QKmgqSQ", SleepyDiscord::USER_CONTROLED_THREADS);

    client.setIntents(SleepyDiscord::Intent::DIRECT_MESSAGES, SleepyDiscord::Intent::DIRECT_MESSAGE_REACTIONS);
    client.run();
}