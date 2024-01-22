//
// Created by smajl on 22.01.2024.
//

#ifndef PUFFERSTARTER_CLI_LIST_SERVERS_H
#define PUFFERSTARTER_CLI_LIST_SERVERS_H

#include <iostream>
#include <string>
#include <memory>
#include "menu_and_authenticaton.h"
#include "../libs/json.hpp"
using json = nlohmann::json; // sue me
std::string gotServerID;

// I hate my life
// this code is shitty af, i know

void getAllServers() {
    int serverNum = 0;

    std::string stopServerCommand = "curl -X GET -H \"Content-Type: application/json\" -H \"Authorization: Bearer " + token + "\" " + ip + "/api/servers -s";
    const char* command = stopServerCommand.c_str();
    std::string output = executeCommand(command);

    std::string jsonData = output;

    try {
        json data = json::parse(jsonData);

        // Extract server ids and names
        if (data.contains("servers") && data["servers"].is_array()) {
            for (const auto& server : data["servers"]) {
                std::string gotServerID = server["id"];
                std::string gotServerName = server["name"];

                // Print server id and name
                serverNum++;
                std::cout << serverNum << ") Server Name = " << gotServerName << ", Server ID = " << gotServerID << "\n";
            }
        } else {
            std::cerr << "Invalid JSON format. Something went wrong while sending the request, or you just don't have any servers :). Returning to menu.\n";
            menuReturn();
        }
    } catch (const std::exception& e) {
        std::cerr << "Error parsing JSON: " << e.what() << std::endl;
        std::cout << "Report this @ https://github.com/smajlll/pufferstarter-cli/issues, returning to menu\n";
        menuReturn();
    }
    sleep(5);
    std::cout << "\nReturning to menu!";
    menuReturn();

}

#endif //PUFFERSTARTER_CLI_LIST_SERVERS_H
