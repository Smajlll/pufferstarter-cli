#include <iostream>
#include <fstream>
#include "auth_menu.h"
#include "../libs/cxxopts.hpp"

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

void interactive(std::string location) {

    std::cout << "Hello";

    std::ifstream file(location);
    if (!file.good()) {
        std::ofstream newFile(location);
        newFile << "ip=\"\"" << std::endl << "id=\"\"" << std::endl << "secret=\"\"" << std::endl;
    }


    ascii();
    authMenu(location);
}

int main(int argc, char* argv[]) {
    std::string location;

    #ifdef _WIN32
        location = std::getenv("USERPROFILE");
        location += "\\.pufferstarter\\config.conf";
    #else
        location = std::getenv("HOME");
            location += "/.config/pufferstarter.conf";
    #endif


    cxxopts::Options options("PufferStarter", " - command line options");
    options.add_options("Generic options")
            ("h,help", "Print this message")
            ("i,interactive", "Start the interactive mode");

    options.add_options("Configuration options")
            ("id", "Set the Server ID (length: 8)",cxxopts::value<std::string>(), "<Server ID>")
            ("c,config", "Set a custom path to your Config File, rather then use the default.", cxxopts::value<std::string>(), "<filename>")
            ("r,createConfig", "Creates the config at the default location");

    options.add_options("Functions")
            ("s,setStatus","Set the status of the server\nRequires --id", cxxopts::value<std::string>(), "<start, stop, kill>")
            ("l,listAll", "Lists all servers and IDs")
            ("g,getInfo","Gets the info about a server\nRequires --id");

    auto result = options.parse(argc, argv);


    if (argc <= 2 || result.count("help")) {
        std::cout << "Section 1:\n" << options.help() << "\n\n";
        // std::cout << "Section 2:\n" << options.help("Configuration options") << "\n\n";
        // std::cout << "Section 1:\n" << options.help('Functions') << std::endl;
        return 0;
    }

    if (result.count("interactive")) {
        interactive(location);
    }

    return 0;
}
