#include <iostream>
#include <fstream>
#include <boost/program_options.hpp>
#include "auth_menu.h"
namespace po = boost::program_options;

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

void interactive() {

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

int main(int argc, const char *argv[]) {
    try {
        po::options_description gen("Generic options");
        gen.add_options()
                ("help,?", po::value<std::string>(), "Print this message")
                ("interactive", "Activate interactive mode");
        po::options_description desc("Allowed options");
        desc.add_options()
                ("status", po::value<std::string>(), "Set status")
                ("id", po::value<int>(), "Set ID")
                ("secret", po::value<std::string>(), "Set secret")
                ("oauthid", po::value<std::string>(), "Set OAuth ID")
                ("ip", po::value<std::string>(), "Set IP");

        po::variables_map vm;
        po::store(po::parse_command_line(argc, argv, desc), vm);
        po::notify(vm);

        if (vm.count("interactive")) {
            interactive();
        }

        if (vm.count("help") || vm.count("?")) {
            std::cout << "Status: " << vm["status"].as<std::string>() << std::endl;
        }

        if (vm.count("status")) {
            std::cout << "Status: " << vm["status"].as<std::string>() << std::endl;
        }
        if (vm.count("id")) {
            std::cout << "ID: " << vm["id"].as<int>() << std::endl;
        }
        if (vm.count("secret")) {
            std::cout << "Secret: " << vm["secret"].as<std::string>() << std::endl;
        }
        if (vm.count("oauthid")) {
            std::cout << "OAuth ID: " << vm["oauthid"].as<std::string>() << std::endl;
        }
        if (vm.count("ip")) {
            std::cout << "IP: " << vm["ip"].as<std::string>() << std::endl;
        }
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
}
