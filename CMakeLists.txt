cmake_minimum_required (VERSION 3.6)
project(discord-bot)

if(NOT SLEEPY_DISCORD_CMAKE)
	add_subdirectory(../../ ${CMAKE_CURRENT_BINARY_DIR}/sleepy-discord)
endif()

add_executable(discord-bot
		src/discordBot.cpp
		headers/EmbedHelper.h
		src/ServiceHelper.cpp headers/service/ServiceHelper.h
		headers/Settings.h src/Settings.cpp
		headers/properties/Properties.h utils/properties/Properties.cpp
		headers/properties/PropertiesException.h headers/properties/PropertyNotFoundException.h
		headers/properties/PropertiesParser.h utils/properties/PropertiesParser.cpp
		headers/properties/PropertiesUtils.h utils/properties/PropertiesUtils.cpp
		)

target_link_libraries(discord-bot
	sleepy-discord
)