cmake_minimum_required (VERSION 3.6)
project(discord-bot)

if(NOT SLEEPY_DISCORD_CMAKE)
	add_subdirectory(../../ ${CMAKE_CURRENT_BINARY_DIR}/sleepy-discord)
endif()

add_executable(discord-bot
		src/discordBot.cpp
		headers/EmbedHelper.h
		src/service/ServiceHelper.cpp headers/service/ServiceHelper.h
		headers/Settings.h src/Settings.cpp
		headers/properties/Properties.h src/utils/properties/Properties.cpp
		headers/properties/PropertiesException.h headers/properties/PropertyNotFoundException.h
		headers/properties/PropertiesParser.h src/utils/properties/PropertiesParser.cpp
		headers/properties/PropertiesUtils.h src/utils/properties/PropertiesUtils.cpp
		headers/IConfiguration.h headers/ConfigurationTypes.h headers/RconConfiguration.h)

target_link_libraries(discord-bot
	sleepy-discord
)