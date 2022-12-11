//
// Created by leanfe on 10.12.22.
//

#include "../headers/Settings.h"


#if defined(WINDOWS)
#define popen _popen;
#define pclose _pclose;
#endif

namespace Options {
    Options::OptionMemory::OptionMemory() {
        struct utsname retval{};
        if(uname(&retval) < 0) {     // <----
            perror("Can't get information about system");
        }

        systemName = retval.sysname;
        nodeName = retval.nodename;
        domain = retval.domainname;
        release = retval.release;
        version = retval.version;
        machine = retval.machine;

    }

    std::string Options::OptionMemory::getDistro() const {
        char buffer[128];
        std::string result;
        FILE* pipe = popen(cmd.c_str(), "r");
        if (!pipe) throw std::runtime_error("popen() failed!");
        try {
            while (fgets(buffer, sizeof buffer, pipe) != nullptr) {
                result += buffer;
            }
        } catch (...) {
            pclose(pipe);
            throw;
        }
        pclose(pipe);
        return result;
    }

    std::string Options::OptionMemory::getDistroIcon() const {
        if (distributive.find("arch") != std::string::npos) {
            return "https://raw.githubusercontent.com/Leanfe/CppDiscord/main/img/arch.png";
        }
        if (distributive.find("fedora") != std::string::npos ) {
            return "https://raw.githubusercontent.com/Leanfe/CppDiscord/main/img/fedora.png";
        }
        if (distributive.find("manjaro") != std::string::npos) {
            return "https://raw.githubusercontent.com/Leanfe/CppDiscord/main/img/manjaro.png";
        }
        if (distributive.find("gentoo") != std::string::npos) {
            return "https://raw.githubusercontent.com/Leanfe/CppDiscord/main/img/gentoo.png";
        }
        if (distributive.find("redhat") != std::string::npos) {
            return "https://raw.githubusercontent.com/Leanfe/CppDiscord/main/img/redhat.png";
        }
        if (distributive.find("ubuntu") != std::string::npos) {
            return "https://raw.githubusercontent.com/Leanfe/CppDiscord/main/img/ubuntu.png";
        }
        if (distributive.find("debian") != std::string::npos) {
            return "https://raw.githubusercontent.com/Leanfe/CppDiscord/main/img/debian.png";
        }
        return "https://raw.githubusercontent.com/Leanfe/CppDiscord/main/img/linux.png";
    }

}