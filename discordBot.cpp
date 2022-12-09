#include "sleepy_discord/sleepy_discord.h"
#include "Information.h"

using namespace SleepyDiscord;

Embed buildEmbed();

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

        if (message.content == "information") {

            sendMessage(channelID, "", buildEmbed());
        }
    }

private:
    Snowflake<Channel> channelID = 1050385700614307930;
    std::string prefix = "?";
};

int main() {
    initUTS();
    MyClientClass client("MTA0ODAwMjA1NTE5MDYyNjM0NQ.GTTh7U.fFYB1ybCD3-uJmO6SsHh1TAUe5nTL6nj99MIOo", SleepyDiscord::USER_CONTROLED_THREADS);

    client.setIntents(SleepyDiscord::Intent::DIRECT_MESSAGES, SleepyDiscord::Intent::DIRECT_MESSAGE_REACTIONS);
    client.run();
}

Embed buildEmbed() {
    SleepyDiscord::Embed embed;
    SleepyDiscord::EmbedField systemEmbed;
    SleepyDiscord::EmbedField nodeEmbed;

    SleepyDiscord::EmbedField releaseEmbed;
    SleepyDiscord::EmbedField versionEmbed;
    SleepyDiscord::EmbedField machineEmbed;

    SleepyDiscord::EmbedImage embedImage;

    embedImage.url = "";
    embedImage.width = 128;
    embedImage.height = 128;


    embed.title = "Информация о системе.";
    embed.description += "Дистрибутив: " + getDistro();
    embed.image = embedImage;

    embed.fields.clear();

    systemEmbed.isInline = false;
    systemEmbed.name = "Тип системы:";
    systemEmbed.value += systemName;

    nodeEmbed.isInline = false;
    nodeEmbed.name = "Имя пользователя:";
    nodeEmbed.value += nodeName;

    releaseEmbed.isInline = false;
    releaseEmbed.name = "Версия Kernel:";
    releaseEmbed.value += release;

    versionEmbed.isInline = false;
    versionEmbed.name = "Версия ядра:";
    versionEmbed.value += version;

    machineEmbed.isInline = false;
    machineEmbed.name = "Битность:";
    machineEmbed.value += machine;

    embed.fields.push_back(systemEmbed);
    embed.fields.push_back(nodeEmbed);
    embed.fields.push_back(releaseEmbed);
    embed.fields.push_back(versionEmbed);
    embed.fields.push_back(machineEmbed);

    return embed;
}