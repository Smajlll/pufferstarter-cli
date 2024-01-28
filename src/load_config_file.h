#ifndef PUFFERSTARTER_CLI_LOAD_CONFIG_FILE_H
#define PUFFERSTARTER_CLI_LOAD_CONFIG_FILE_H
#include <iostream>
#include <string>
#include <memory>
#include <fstream>
#include <string>
#include "menu_and_authenticaton.h"

// fucked up indentation in this file; too lazy to fix it

extern std::string id;
extern std::string ip;


void openConfig(std::string configFile) {

    // Open the file
    std::ifstream file(configFile);

    if (file.is_open()) {
        std::string rawIP, rawID, rawSecret;
        std::getline(file, rawIP);
        std::getline(file, rawID);
        std::getline(file, rawSecret);

        file.close();

        if (rawIP.length() <= 8 || rawID.length() <= 8 || rawSecret.length() <= 12) {
            std::cout << "Something isn't right with your configuration, or it did not exist in the first place (in that case, it was created with the defaults).\nTry reading the documentation at https://docs.smoliicek.xyz/#/Configuration/configuration-file for proper usage of the config file.\nFalling back to manually entering credentials.\n";
            getAuthKeyParams();
        } else {
            const char* findThis = "\"";

            std::string ip = rawIP.erase(0, 4);
            int ipLenght = ip.find(findThis);
            ip = ip.erase(ipLenght, 1);

            std::string id = rawID.erase(0, 4);
            int idLenght = id.find(findThis);
            id = id.erase(idLenght, 1);

            std::string secret = rawSecret.erase(0, 8);
            int secretLenght = secret.find(findThis);
            secret = secret.erase(secretLenght, 1);

            saveStringsFromConfig(id, secret, ip);
            getAuthKey(id, secret, ip);
        }

    } else {
        std::cerr << "Error opening file: " << configFile << "\nFalling back to manually entering credentials.";
        getAuthKeyParams();
    }

}


void getConfigFile(std::string location) {

    std::ifstream file(location);
    if (file.good()) {
        openConfig(location);
    } else {
        std::ofstream newFile(location);
        newFile << "ip=\"\"" << std::endl << "id=\"\"" << std::endl << "secret=\"\"" << std::endl;
        getAuthKeyParams();
    }

}


#endif //PUFFERSTARTER_CLI_LOAD_CONFIG_FILE_H
