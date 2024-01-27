//
// Created by smajl on 23.01.2024.
//

#ifndef PUFFERSTARTER_CLI_AUTH_MENU_H
#define PUFFERSTARTER_CLI_AUTH_MENU_H
#include <iostream>
#include <string>
#include <memory>
#include <cstdio>
#include <fstream>
#include "menu_and_authenticaton.h"
#include "load_config_file.h"

void authMenu(std::string location) {
        char authChoice;
        std::cout << "\n1) Load my credentials from the config file\n";
        std::cout << "2) Enter my credentials manually\n";
        std::cout << "Choose an option: ";
        std::cin >> authChoice;

        switch (authChoice) {
            case '1':
                getConfigFile(location);
            case '2':
                getAuthKeyParams();
            default:
                std::cout << "This doesn't look like an option, try again :)";
                authMenu(location);
        }
}

#endif //PUFFERSTARTER_CLI_AUTH_MENU_H
