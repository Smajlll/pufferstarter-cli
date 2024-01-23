#ifndef PUFFERSTARTER_CLI_PRINT_SERVER_INFO_H
#define PUFFERSTARTER_CLI_PRINT_SERVER_INFO_H

#include <iostream>
#include "menu_and_authenticaton.h"
#ifdef _WIN32
#include <io.h>
#else
#include <unistd.h>
#endif
#ifdef _WIN32
#include <windows.h>
#define sleep(x) Sleep((x) * 1000)
#endif

void menu();
void menuReturn();

void printServerInfo(std::string serverID, std::string serverName, std::string serverPort, std::string serverStatus = "Not defined") {
    std::cout << "\n\nSERVER INFORMATION\n";
    std::cout << "Server Name: " << serverName << "\n";
    std::cout << "Server Port: " << serverPort << "\n";
    std::cout << "Server ID: " << serverID << "\n";
    std::cout << "Online: " << serverStatus << "\n\n";
    sleep(3);

    std::cout << "Nothing else to see here, returning to main menu!\n";
    menuReturn();
}


#endif //PUFFERSTARTER_CLI_PRINT_SERVER_INFO_H
