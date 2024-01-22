//
// Created by smajl on 21.01.2024.
//

#ifndef PUFFERSTARTER_CLI_CHANGE_STATUS_H
#define PUFFERSTARTER_CLI_CHANGE_STATUS_H
#include <iostream>
#include <string>
#include <memory>
#include "menu_and_authenticaton.h"

std::string ip;
std::string token;
std::string id;
std::string sid;


void stopServer(std::string sid, std::string ip, std::string token) {
    std::cout << "Server is stopping";
    std::string stopServerCommand = "curl -X POST -H \"Content-Type: application/json\" -H \"Authorization: Bearer " + token + "\" " + ip + "/daemon/server/" + sid + "/stop -s";
    const char* command = stopServerCommand.c_str();
    std::string output2 = executeCommand(command);

    if (output2 != "") {
        std::cout << "This didn't work. The server did NOT stop. Returning to the main menu! ";
        menuReturn();
    } else {
        std::cout << "Server stopped successfully, returning to the main menu!";
        menuReturn();
    }
}

void startServer(std::string sid, std::string ip, std::string token) {
    std::cout << "Server is starting";
    std::string stopServerCommand = "curl -X POST -H \"Content-Type: application/json\" -H \"Authorization: Bearer " + token + "\" " + ip + "/daemon/server/" + sid + "/start -s";
    const char* command = stopServerCommand.c_str();
    std::string output2 = executeCommand(command);

    if (output2 != "") {
        std::cout << "This didn't work. The server did NOT start. Returning to the main menu! ";
        menuReturn();
    } else {
        std::cout << "Server started successfully, returning to the main menu!";
        menuReturn();
    }
}


void killServer(std::string sid, std::string ip, std::string token) {

    std::string killChoice;

    std::cout <<"\nAre you sure?\nThis will kill your server without any saving, it will just kill its java process.\nDo this only if you are sure you need this, using the \"Stop the Server\" function is recommended\n\nType \"YES\" (without the quotation marks) to kill the server.\n";
    std::cin >> killChoice;

    if (killChoice == "YES") {

        std::cout << "Killing your server\n";
        std::string stopServerCommand = "curl -X POST -H \"Content-Type: application/json\" -H \"Authorization: Bearer " + token + "\" " + ip + "/daemon/server/" + sid + "/kill -s";
        const char* command = stopServerCommand.c_str();
        std::string output2 = executeCommand(command);

        if (output2 != "") {
            std::cout << "This didn't work. The server was NOT killed. Returning to the main menu! ";
            menuReturn();
        } else {
            std::cout << "Server killed successfully, returning to the main menu!";
            menuReturn();
        }

    } else {
        std::cout << "Recieved something else then \"YES\", returning to menu";
        menuReturn();
    }

}

std::string getCurrentStatus() {

    std::string getStaticServerStatusCommand = "curl -X GET -H \"Content-Type: application/json\" -H \"Authorization: Bearer ";
    std::string getServerStatusCommand = getStaticServerStatusCommand + token + "\" " + ip + "/daemon/server/" + sid + "/status -s";
    const char* command2 = getServerStatusCommand.c_str();
    std::string output2 = executeCommand(command2);

    if (output2 == "{\"running\":true}" || output2 == "{\"running\":false}") {
        std::string serverStatus = output2.erase(0, 11);
        int cutFrom = serverStatus.length() - 1;
        serverStatus = serverStatus.erase(cutFrom, 1);
        return serverStatus;
    } else {
        std::string serverStatus = "unkown";
        return serverStatus;
    }

}

int statusChangeChoice() {
    int statusChoice;
    std::string currentStatus = getCurrentStatus();
    if (currentStatus == "true") {
        currentStatus = "Server is ONLINE";
    } else if (currentStatus == "false") {
        currentStatus = "Server is OFFLINE";
    } else {
        currentStatus = "Unknown :(";
    }

    std::cout << "\nCurrent status: " << currentStatus;
    std::cout << "\nWhat do you want to do?";
    std::cout << "\n1) Stop the Server";
    std::cout << "\n2) Kill the Server";
    std::cout << "\n3) Start the server";
    std::cout << "\n4) Rreturn to menu\n";
    std::cin >> statusChoice;
    if (statusChoice == 4) {
        std::cout << "\nReturning to menu!";
        menuReturn();
    } else if (statusChoice == 1 || statusChoice == 2 || statusChoice == 3) {
        return statusChoice;
    } else {
        std::cout << "\nThis doesn't look like a valid choice. Returning to menu\n";
        // INFO: works here
        menuReturn();
    }
}

void constructCommand(std::string sid, std::string ip, std::string token, int choice) {
    switch (choice) {
        case 1:
            stopServer(sid, ip, token);
            break;
        case 2:
            killServer(sid, ip, token);
            break;
        case 3:
            startServer(sid, ip, token);
            break;
        default:
            std::cout << "How the fuck did you get here. Try to reproduce this and report this @ https://github.com/Smajlll/pufferstarter-cli/issues\n";
            std::cout << "Quitting! :(";
            exit(1);
    }
}

void getStatusInfo(std::string serverIP, std::string authToken) {

    ip = serverIP;
    token = authToken;
    std::string serverID;

    std::cout << "Please, enter the ID of the server you want to get the information about.\n";
    std::cout << "(Server ID is the numbers and letters after " + ip + "/server/<this is the ID>\n";
    std::cin >> serverID;

    if (serverID.length() != 8) {
        std::cout << "This doesn't look like a valid ID, the ID should be 8 characters long.\nThe ID you entered is " << serverID << "\n";
        std::cout << "Returning to main menu\n";
        menuReturn();
    } else {
        sid = serverID;
        int statusChoice = statusChangeChoice();
        constructCommand(serverID, ip, token, statusChoice);
    }
}



#endif //PUFFERSTARTER_CLI_CHANGE_STATUS_H
