#ifndef PUFFERSTARTER_CLI_MENU_AND_AUTH_H
#define PUFFERSTARTER_CLI_MENU_AND_AUTH_H


#include <iostream>
#include <string>
#include <memory>
#include "http_request.h"
#include "get_server_info.h"
#include "change_status.h"
#include "list_servers.h"
// why the fuck did I code this to be in one header file, fuck me

std::string authToken;

void reset();
void getAuthKey(std::string id, std::string secret);
void menuReturn();
std::string serverIP;
void getAuthKeyParams();
extern std::string token;
extern std::string id;
std::string secret;
extern std::string ip;

void menu() {
    char opt;
    char choice;
    std::cout << "\n1) Change your credentials\n";
    std::cout << "2) Get new authentication token using your credentials\n";
    std::cout << "3) Get all server names and IDs\n";
    std::cout << "4) Get the status and information of a server\n";
    std::cout << "5) Change the status of the server\n";
    std::cout << "6) Quit\n\n";
    std::cout << "Choose an option: ";
    std::cin >> opt;

    switch (opt) {
        case '1':
            std::cout <<"\nThis will reset the program, and you will have to start again by typing your clientID and your clientSecret. Are you sure you want to continue? [Y/y]\n";
            std::cin >> choice;
            switch (choice) {
                case 'y':
                    reset();
                    break;
                case 'Y':
                    reset();
                    break;
                default:
                    std::cout << "This doesn't look like \'Y\' or \'y\', sending you back to main menu.\n";
                    menuReturn();
            }
        case '2':
            menuReturn();
            break;
        case '3':
            getAllServers();
            break;
        case '4':
            getServerInfo(serverIP, token);
            break;
        case '5':
            getStatusInfo(ip, token);
        case '6':
            exit(0);
        default:
            std::cout << "\n This isn\'t a valid action, try again. :)\n\n";
            menuReturn();
    }
}

void reset() {
    void getAuthKeyParams();

    getAuthKeyParams();
    std::cout << "\nCredentials successfully changed!\n";
    menu();
}

void saveAuthKey(std::string jsonAuthString) {

    /*jsonAuthString.erase(0, 17);
    jsonAuthString.erase(447, 67);*/
    const char* findThis = ",";
    std::string authToken = jsonAuthString.erase(0, 17);
    int tokenLenght = authToken.find(findThis);
    int fullLenght = authToken.length();
    int cutFrom = tokenLenght - 1;
    int cutTo = fullLenght - cutFrom;

    authToken = jsonAuthString.erase(cutFrom, cutTo);
    token = authToken;
}

void getAuthKeyParams() {
    void getAuthKey(std::string id, std::string secret, std::string ip);

    std::cout << "What is the IP of your PufferPanel host server? (example: panel.abc.xyz:8080)\n";
    std::cin >> ip;
    serverIP = ip;
    std::cout << "\nWhat is your ClientID? (You can get that at " << ip << "/account in the OAuth2 Clients section)\n";
    std::cin >> id;
    std::cout << "\nWhat is your Client Secret? (You can get that at " << ip << "/account in the OAuth2 Clients section. You can only see it once, after you create the client!)\n";
    std::cin >> secret;

    // Putting the command together
    getAuthKey(id, secret, ip);
}

void getAuthKey(std::string id, std::string secret, std::string ip) {

    std::string getAuthKeyCommand = "curl --request POST --url " + ip;
    getAuthKeyCommand = getAuthKeyCommand + "/oauth2/token";
    getAuthKeyCommand = getAuthKeyCommand + " --data grant_type=client_credentials --data client_id=";
    getAuthKeyCommand = getAuthKeyCommand + id;
    getAuthKeyCommand = getAuthKeyCommand + " --data client_secret=";
    getAuthKeyCommand = getAuthKeyCommand + secret + " -s";

    const char* command = getAuthKeyCommand.c_str();

    std::string output = executeCommand(command);
    saveAuthKey(output);

}

void menuReturn() {
    void getAuthKey(std::string id, std::string secret, std::string ip);

    std::cout << "\nGetting you a fresh new token!\n";
    getAuthKey(id, secret, ip);
    menu();
}

void statusMenuReturn() {
    menuReturn();
}

#endif //PUFFERSTARTER_CLI_MENU_AND_AUTH_H