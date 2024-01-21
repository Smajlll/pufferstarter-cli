//
// Created by smajl on 20.01.2024.
//

#ifndef PUFFERSTARTER_CLI_HTTP_REQUEST_H
#define PUFFERSTARTER_CLI_HTTP_REQUEST_H

#include <iostream>
#include <cstdio>
#include <string>
#include <sstream>
#include <memory>
#include <stdexcept>
#include <array>
#include "menu_and_authenticaton.h"

// don't ask me how I wrote this code, it compiles

std::string executeCommand(const char* cmd) {
    std::array<char, 128> buffer;
    std::string result;
    std::shared_ptr<FILE> pipe(popen(cmd, "r"), pclose);
    if (!pipe) {
        throw std::runtime_error("popen() is fucking stupid and i want to kill myself!");
    }
    while (!feof(pipe.get())) {
        if (fgets(buffer.data(), static_cast<int>(buffer.size()), pipe.get()) != nullptr) {
            result += buffer.data();
        }
    }
    return result;
}



#endif //PUFFERSTARTER_CLI_HTTP_REQUEST_H
