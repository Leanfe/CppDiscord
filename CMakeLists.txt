cmake_minimum_required (VERSION 3.6)
project(discord-bot)

if(NOT SLEEPY_DISCORD_CMAKE)
	add_subdirectory(../../ ${CMAKE_CURRENT_BINARY_DIR}/sleepy-discord)
endif()

add_executable(discord-bot
        discordBot.cpp
        EmbedHelper.h ServiceHelper.cpp ServiceHelper.h Settings.h Settings.cpp)

target_link_libraries(discord-bot
	sleepy-discord
)