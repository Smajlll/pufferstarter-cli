#ifndef PUFFERSTARTER_CLI_SEE_CONSOLE_H
#define PUFFERSTARTER_CLI_SEE_CONSOLE_H

#include <iostream>
#include "menu_and_authenticaton.h"

void printConsole(std::string ip, std::string token, int fromMenu, std::string serverID) {
    std::cout << "Console output running through 'more'. Use 'Q' to quit\n";

    std::string getStaticConsoleCommand = "curl -X GET -H \"Content-Type: application/json\" -H \"Authorization: Bearer ";
    std::string getServerConsoleCommand = getStaticConsoleCommand + token + "\" " + ip + "/daemon/server/" + serverID + "/console" + " -v | more";
    const char* command = getServerConsoleCommand.c_str();
    std::string output = executeCommand(command);
    std::cout << command;

    if (fromMenu == 0) {
        exit(0);
    }
    menuReturn();
}


void getConsoleInfo(std::string ip, std::string token, int fromMenu, std::string serverID) {

    if (fromMenu == 1) {
        std::cout << "Please, enter the ID of the server you want to get the information about.\n";
        std::cout << "(Server ID is the numbers and letters after " + ip + "/server/<this is the ID>\n";
        std::cin >> serverID;

        if (serverID.length() != 8) {
            std::cout << "This doesn't look like a valid ID, the ID should be 8 characters long.\nThe ID you entered is " << serverID << "\n";
            std::cout << "Returning to main menu\n";
            menuReturn();
        } else {
            printConsole(ip, token, fromMenu, serverID);
        }
    }

    printConsole(ip, token, fromMenu, serverID);

}


#endif //PUFFERSTARTER_CLI_SEE_CONSOLE_H
