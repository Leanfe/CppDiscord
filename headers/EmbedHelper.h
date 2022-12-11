//
// Created by leanfe on 10.12.22.
//

#include <sleepy_discord/embed.h>
#include "Settings.h"

#ifndef DISCORD_BOT_EMBEDHELPER_H
#define DISCORD_BOT_EMBEDHELPER_H

SleepyDiscord::Embed buildEmbed() {
    SleepyDiscord::Embed embed;
    SleepyDiscord::EmbedField systemEmbed;
    SleepyDiscord::EmbedField nodeEmbed;

    SleepyDiscord::EmbedField releaseEmbed;
    SleepyDiscord::EmbedField versionEmbed;
    SleepyDiscord::EmbedField machineEmbed;

    SleepyDiscord::EmbedImage embedImage;


    std::string distroName = options.getDistro();

    embed.thumbnail.url = options.getDistroIcon();
    embed.thumbnail.width = 64;
    embed.thumbnail.height = 64;


    embed.title = "Информация о системе.";
    embed.description += "Дистрибутив: " + distroName;
    embed.image = embedImage;
    embed.fields.clear();

    systemEmbed.isInline = false;
    systemEmbed.name = "Тип системы:";
    systemEmbed.value += options.systemName;

    nodeEmbed.isInline = false;
    nodeEmbed.name = "Имя пользователя:";
    nodeEmbed.value += options.nodeName;

    releaseEmbed.isInline = false;
    releaseEmbed.name = "Версия Kernel:";
    releaseEmbed.value += options.release;

    versionEmbed.isInline = false;
    versionEmbed.name = "Версия ядра:";
    versionEmbed.value += options.version;

    machineEmbed.isInline = false;
    machineEmbed.name = "Битность:";
    machineEmbed.value += options.machine;

    embed.fields.push_back(systemEmbed);
    embed.fields.push_back(nodeEmbed);
    embed.fields.push_back(releaseEmbed);
    embed.fields.push_back(versionEmbed);
    embed.fields.push_back(machineEmbed);

    return embed;
}

#endif //DISCORD_BOT_EMBEDHELPER_H
