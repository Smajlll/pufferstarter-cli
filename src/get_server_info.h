#ifndef PUFFERSTARTER_CLI_GET_SERVER_INFO_H
#define PUFFERSTARTER_CLI_GET_SERVER_INFO_H

// TODO: Fixnout CURL commandy, pak už by všechno mělo snad fungovat
// sadge


#include <iostream>
#include <string>
#include <memory>
#include "menu_and_authenticaton.h"
#include "print_server_info.h"

void saveServerInfo(std::string jsonServerInfo, std::string id, std::string jsonServerStatus) {
    // just get the id, name and port
    char findThis = '"';

    // get the id, that was provided
    std::string serverID = id;

    // somehow get the name
    std::string serverName = jsonServerInfo.erase(0, 35);
    int nameLenght = serverName.find(findThis);
    int fullLenght = serverName.length();
    int cutFrom = nameLenght;
    int cutTo = fullLenght - nameLenght;
    // this is the final server name, use this pls
    serverName = serverName.erase(cutFrom, cutTo);

    // and also get the port
    int findPort = jsonServerInfo.find("\"port\"");
    findPort = findPort + 7;
    std::string serverPort = jsonServerInfo.erase(0, findPort);
    findThis = ',';
    cutFrom = serverPort.find(findThis);
    cutTo = serverPort.length();
    serverPort = serverPort.erase(cutFrom, cutTo);

    // strip the status
    std::string serverStatus = jsonServerStatus.erase(0, 12);
    cutFrom = serverStatus.length() - 1;
    serverStatus = serverStatus.erase(cutFrom, 1);

    // pass this to the print function
    printServerInfo(serverID, serverName ,serverPort, serverStatus);

}


void makeCommandStructures(std::string serverID, std::string ip, std::string token) {

    std::string getServerInfoCommand = "curl --request GET --url " + ip;
    getServerInfoCommand = getServerInfoCommand + "/api/servers/";
    getServerInfoCommand = getServerInfoCommand + serverID;
    getServerInfoCommand = getServerInfoCommand + " --header 'Authorization: Bearer ";
    getServerInfoCommand = getServerInfoCommand + token + "'";

    const char* command1 = getServerInfoCommand.c_str();

    std::cout << command1;

    std::string output1 = executeCommand(command1);

    std::string getServerStatusCommand = "curl --request GET --url " + ip;
    getServerStatusCommand = getServerStatusCommand + "/proxy/daemon/servers/";
    getServerStatusCommand = getServerStatusCommand + serverID;
    getServerStatusCommand = getServerStatusCommand + "/status";
    getServerStatusCommand = getServerStatusCommand + " --header 'Authorization: Bearer ";
    getServerStatusCommand = getServerStatusCommand + token + "'";
    getServerStatusCommand = getServerStatusCommand + " --header 'Content-Type: application/json'";

    std::cout << getServerStatusCommand;

    const char* command2 = getServerStatusCommand.c_str();

    std::cout << command2;

    std::string output2 = executeCommand(command2);

    saveServerInfo(output1, serverID, output2);
}


void getServerInfo(std::string ip, std::string token) {

    std::string serverID;

    std::cout << ip;

    std::cout << "Please, enter the ID of the server you want to get the information about.\n";
    std::cout << "(Server ID is the numbers and letters after " + ip + "/server/<this is the ID>\n";
    std::cin >> serverID;

    if (serverID.length() != 8) {
        std::cout << "This doesn't look like a valid ID, the ID should be 8 characters long.\nThe ID you entered is " << serverID << "\n";
    } else {
        makeCommandStructures(serverID, ip, token);
    }

}

#endif //PUFFERSTARTER_CLI_GET_SERVER_INFO_H
