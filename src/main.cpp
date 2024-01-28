#include <iostream>
#include <fstream>
#include "auth_menu.h"
#include "load_config_file.h"
#include "../libs/cxxopts.hpp"
#include "see-console.h"


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

    std::ifstream file(location);
    if (!file.good()) {
        std::ofstream newFile(location);
        newFile << "ip=\"\"" << std::endl << "id=\"\"" << std::endl << "secret=\"\"" << std::endl;
    }


    ascii();
    authMenu(location);
    menu();
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


    cxxopts::Options options("pufferstarter-cli");
    options.add_options("Generic options")
            ("h,help", "Print this message")
            ("i,interactive", "Start the interactive mode");

    options.add_options("Configuration options")
            ("id", "Set the Server ID (length: 8)",cxxopts::value<std::string>(), "<Server ID>")
            ("r,createConfig", "Creates the config at the default location");

    options.add_options("Functions")
            ("s,setStatus","Set the status of the server\nRequires --id", cxxopts::value<std::string>(), "<start, stop, kill>")
            ("console,c", "See the log of the server\nRequires --id")
            ("l,listAll", "Lists all servers and IDs")
            ("g,getInfo","Gets the info about a server\nRequires --id");

    auto result = options.parse(argc, argv);

    if (result.count("interactive")) {
        interactive(location);
    }


    if (result.count("createConfig")) {
        std::ifstream file(location);
        if (!file.good()) {
            std::ofstream newFile(location);
            newFile << "ip=\"\"" << std::endl << "id=\"\"" << std::endl << "secret=\"\"" << std::endl;
        }

        std::cout << "\nConfig created!\nQuitting.";
        exit(0);
    }

    if (result.count("listAll")) {
        openConfig(location);
        getAllServers(0);
    }

    if (result.count("console")) {
        if (!result.count("id")) {
            std::cout << "You need to specify --id to run this function.";
            exit(1);
        }

        sid = result["id"].as<std::string>();
        openConfig(location);
        getConsoleInfo(ip, token, 0, sid);
    }

    if (result.count("getInfo")) {
        if (!result.count("id")) {
            std::cout << "You need to specify --id to run this function.";
            exit(1);
        }

        sid = result["id"].as<std::string>();
        openConfig(location);
        getServerInfo(ip, token, 0, sid);
    }
    
    if (result.count("setStatus")) {


        if (!result.count("id")) {
            std::cout << "You need to specify --id and -s to run this function.";
            exit(1);
        }

        std::string status = result["setStatus"].as<std::string>();
        std::string sid = result["id"].as<std::string>();


        if (status == "off") {
            openConfig(location);
            stopServer(sid, ip, token, 0);
        } else if (status == "on") {
            openConfig(location);
            startServer(sid, ip, token, 0);
        } else if (status == "kill") {
            openConfig(location);
            killServer(sid, ip, token, 0);
        } else {
            std::cout << "This isn't a valid status, please use off, on or kill.";
        }

    }

    if (argc == 1 || result.count("help")) {
        std::cout << options.help() << std::endl;
        return 0;
    }

    if (result.count("id")) {
        std::cout << "You can't run --id by itself.\n\n";
        std::cout << options.help() << std::endl;
        return 1;
    }

    return 0;
}
