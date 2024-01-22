//
// Created by smajl on 22.01.2024.
//

#ifndef PUFFERSTARTER_CLI_LIST_SERVERS_H
#define PUFFERSTARTER_CLI_LIST_SERVERS_H

#include <iostream>
#include <string>
#include <memory>
#include "menu_and_authenticaton.h"

// I hate my life

void listAllServers() {
    std::cout << "implement this or idk";
}

void getAllServers() {
    std::string stopServerCommand = "curl -X GET -H \"Content-Type: application/json\" -H \"Authorization: Bearer " + token + "\" " + ip + "/api/servers -s";
    const char* command = stopServerCommand.c_str();
    std::string output = executeCommand(command);

    std::string searchString1 = "{";
    std::string searchString2 = "port";
    std::string searchString3 = ",";
    size_t found = output.find(searchString1);

    while (found != std::string::npos) {
        found = output.find(searchString1, found + 1);
    }
}

#endif //PUFFERSTARTER_CLI_LIST_SERVERS_H
