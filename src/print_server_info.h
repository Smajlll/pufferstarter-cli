#ifndef PUFFERSTARTER_CLI_PRINT_SERVER_INFO_H
#define PUFFERSTARTER_CLI_PRINT_SERVER_INFO_H

#include <iostream>
#include "menu_and_authenticaton.h"

void menu();

void printServerInfo(std::string serverID, std::string serverName, std::string serverPort, std::string serverStatus = "Not defined") {
    std::cout << "SERVER INFORMATION\n";
    std::cout << "Server Name: " << serverName << "\n";
    std::cout << "Server Port: " << serverPort << "\n";
    std::cout << "Server ID: " << serverID << "\n";
    std::cout << "Online: " << serverStatus << "\n\n";
    std::cout << "Nothing else to see here, returning to main menu!";
    menu();
}


#endif //PUFFERSTARTER_CLI_PRINT_SERVER_INFO_H
