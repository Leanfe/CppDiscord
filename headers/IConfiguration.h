//
// Created by leanfe on 11.12.22.
//

#pragma once

#ifndef DISCORD_BOT_ICONFIGURATION_H
#define DISCORD_BOT_ICONFIGURATION_H

#include <string>
#include <filesystem>
#include <utility>
#include "ConfigManager.h"
#include "ConfigurationTypes.h"

namespace Configuration {
    class IConfiguration {
    public:
        IConfiguration(ConfigurationType type, std::string id) {
            this->type = type;
            this->id = std::move(id);

            openFile();
        }

        ~IConfiguration() {
            fclose(config);
            free(config);
        }
    private:
        ConfigurationType type;
        FILE* config;

        std::string id;

        FILE* openFile() {
            path = std::filesystem::current_path().string() + id + ".properties";
            config = fopen(path.c_str(), "rw");
            if (config == nullptr) {
                perror("ERROR!");
            }

            readValues();
        }

    protected:
        std::string path;

        bool isConfigEmpty() {
            fseek(config,0,SEEK_END);
            long pos=ftell(config);
            if(pos > 0) {
                // файл непустой.
                rewind(config);
                return false;
            }
            return true;
        }


        void readValues() {
            if (isConfigEmpty()) {
                declareValues();
            }
        }

        virtual void declareValues() = 0;

    };
}

#endif //DISCORD_BOT_ICONFIGURATION_H
