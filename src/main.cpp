#include <iostream>
#include <fstream>
#include "menu_and_authenticaton.h"
#include "auth_menu.h"

void ascii() {
    std::cout << R"(
     ________  ___  ___  ________ ________ _______   ________  ________  _________  ________  ________  _________  _______   ________
    |\   __  \|\  \|\  \|\  _____\\  _____\\  ___ \ |\   __  \|\   ____\|\___   ___\\   __  \|\   __  \|\___   ___\\  ___ \ |\   __  \
    \ \  \|\  \ \  \\\  \ \  \__/\ \  \__/\ \   __/|\ \  \|\  \ \  \___|\|___ \  \_\ \  \|\  \ \  \|\  \|___ \  \_\ \   __/|\ \  \|\  \
     \ \   ____\ \  \\\  \ \   __\\ \   __\\ \  \_|/_\ \   _  _\ \_____  \   \ \  \ \ \   __  \ \   _  _\   \ \  \ \ \  \_|/_\ \   _  _\
      \ \  \___|\ \  \\\  \ \  \_| \ \  \_| \ \  \_|\ \ \  \\  \\|____|\  \   \ \  \ \ \  \ \  \ \  \\  \|   \ \  \ \ \  \_|\ \ \  \\  \|
       \ \__\    \ \_______\ \__\   \ \__\   \ \_______\ \__\\ _\ ____\_\  \   \ \__\ \ \__\ \__\ \__\\ _\    \ \__\ \ \_______\ \__\\ _\
        \|__|     \|_______|\|__|    \|__|    \|_______|\|__|\|__|\_________\   \|__|  \|__|\|__|\|__|\|__|    \|__|  \|_______|\|__|\|__|
                                                                 \|_________|

    )" << "\n";

    std::cout << "\nWelcome to PufferStarter!\n";
}

int main() {

    std::string location;

    #ifdef _WIN32
        location = std::getenv("USERPROFILE");
        location += "\\.pufferstarter\\config.conf";
    #else
        location = std::getenv("HOME");
        location += "/.config/pufferstarter.conf";
    #endif

    std::ifstream file(location);
    if (!file.good()) {
        std::ofstream newFile(location);
        newFile << "ip=\"\"" << std::endl << "id=\"\"" << std::endl << "secret=\"\"" << std::endl;
    }


    ascii();
    authMenu();
}

