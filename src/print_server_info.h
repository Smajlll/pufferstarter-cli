#ifndef PUFFERSTARTER_CLI_PRINT_SERVER_INFO_H
#define PUFFERSTARTER_CLI_PRINT_SERVER_INFO_H

#include <iostream>
#include "menu_and_authenticaton.h"
#include <unistd.h>

void menu();
void menuReturn();

void printServerInfo(std::string serverID, std::string serverName, std::string serverPort, std::string serverStatus = "Not defined") {
    std::cout << "\n\nSERVER INFORMATION\n";
    std::cout << "Server Name: " << serverName << "\n";
    std::cout << "Server Port: " << serverPort << "\n";
    std::cout << "Server ID: " << serverID << "\n";
    std::cout << "Online: " << serverStatus << "\n\n";
    sleep(5);

    std::cout << "Nothing else to see here, returning to main menu!\n";
    menuReturn();
}


#endif //PUFFERSTARTER_CLI_PRINT_SERVER_INFO_H
