#ifndef PUFFERSTARTER_CLI_MENU_AND_AUTH_H
#define PUFFERSTARTER_CLI_MENU_AND_AUTH_H


#include <iostream>
#include <string>
#include <memory>
#include "http_request.h"
#include "get_server_info.h"

// why the fuck did I code this to be in one header file, fuck me

std::string authToken;
std::string token;
void reset();
void getAuthKey();
std::string ip;
std::string serverIP;

void menu() {
    char opt;
    char choice;
    std::cout << "1) Change your credentials\n";
    std::cout << "2) Get the status and information of a server\n";
    std::cout << "3) Change the status of the server\n";
    std::cout << "4) Quit\n\n";
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
                    menu();
            }
        case '2':
            getServerInfo(serverIP, token);
            break;
        case '3':
            std::cout << "Working on it!";
            exit(0);
        case '4':
            exit(0);
        default:
            std::cout << "\n This isn\'t a valid action, try again. :)\n\n";
            menu();
    }
}

void reset() {
    getAuthKey();
    std::cout << "\nCredentials successfully changed!\n";
    menu();
}

void saveAuthKey(std::string jsonAuthString) {

    jsonAuthString.erase(0, 17);
    jsonAuthString.erase(447, 67);

    std::string authToken = jsonAuthString;
    token = authToken;
}

void getAuthKey() {
    std::string id;
    std::string secret;
    std::string ip;

    std::cout << "What is the IP of your PufferPanel server? (example: http://panel.abc.xyz:8080)\n";
    std::cin >> ip;
    serverIP = ip;
    std::cout << "\nWhat is the ClientID for your program? (You can get that at " << ip << "/account in the OAuth2 Clients section)\n";
    std::cin >> id;
    std::cout << "\nWhat is your Client Secret? (You can get that at " << ip << "/account in the OAuth2 Clients section. You can only see it once, after you create the client!)\n";
    std::cin >> secret;

    // Putting the command together

    std::string getAuthKeyCommand = "curl --request POST --url " + ip;
    getAuthKeyCommand = getAuthKeyCommand + "/oauth2/token";
    getAuthKeyCommand = getAuthKeyCommand + " --data grant_type=client_credentials --data client_id=";
    getAuthKeyCommand = getAuthKeyCommand + id;
    getAuthKeyCommand = getAuthKeyCommand + " --data client_secret=";
    getAuthKeyCommand = getAuthKeyCommand + secret;
    const char* command = getAuthKeyCommand.c_str();

    std::string output = executeCommand(command);
    saveAuthKey(output);

}


#endif //PUFFERSTARTER_CLI_MENU_AND_AUTH_H