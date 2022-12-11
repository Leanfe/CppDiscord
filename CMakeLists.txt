cmake_minimum_required (VERSION 3.6)
project(discord-bot)

if(NOT SLEEPY_DISCORD_CMAKE)
	add_subdirectory(../../ ${CMAKE_CURRENT_BINARY_DIR}/sleepy-discord)
endif()

add_executable(discord-bot
        discordBot.cpp
        EmbedHelper.h
		ServiceHelper.cpp ServiceHelper.h
		Settings.h Settings.cpp
		properties/Properties.h properties/Properties.cpp
		properties/PropertiesException.h properties/PropertyNotFoundException.h
		properties/PropertiesParser.h properties/PropertiesParser.cpp
		properties/PropertiesUtils.h properties/PropertiesUtils.cpp
		)

target_link_libraries(discord-bot
	sleepy-discord
)