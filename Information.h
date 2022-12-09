//
// Created by leanfe on 09.12.22.
//


#ifndef DISCORD_BOT_INFORMATION_H
#define DISCORD_BOT_INFORMATION_H

#include <iostream>
#include <stdexcept>
#include <cstdio>
#include <string>
#include <sys/utsname.h>

#if defined(WINDOWS)
#define popen _popen;
#define pclose _pclose;
#endif

std::string cmd = R"(for f in $(find /etc -type f -maxdepth 1 \( ! -wholename /etc/os-release ! -wholename /etc/lsb-release -wholename /etc/\*release -o -wholename /etc/\*version \) 2> /dev/null); do echo ${f:5:${#f}-13}; done;)";

std::string systemName;
std::string nodeName;
std::string domain;

std::string release;
std::string version;
std::string machine;

std::string getDistro() {
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

bool initUTS() {
    struct utsname retval;
    if(uname(&retval) < 0) {     // <----
        return false;
    }

    systemName = retval.sysname;
    nodeName = retval.nodename;
    domain = retval.domainname;

    release = retval.release;
    version = retval.version;
    machine = retval.machine;

    return true;
}

#endif //DISCORD_BOT_INFORMATION_H
