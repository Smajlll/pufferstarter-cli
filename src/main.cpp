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

bool isValidStatus(const std::string& status) {
    std::set<std::string> validStatusValues = {"off", "start", "kill"};
    return validStatusValues.count(status) > 0;
}


int main(int argc, const char *argv[]) {
    try {
        std::string location;

        #ifdef _WIN32
            location = std::getenv("USERPROFILE");
            location += "\\.pufferstarter\\config.conf";
        #else
            location = std::getenv("HOME");
            location += "/.config/pufferstarter.conf";
        #endif


        po::options_description gen("Generic options");
        gen.add_options()
                ("help,?", "Print this message")
                ("interactive,i", "Start the interactive mode");
        po::options_description conf("Configuration options");
        conf.add_options()
                ("id", po::value<std::string>()->value_name("SERVER ID")->notifier([](const std::string& value){
                    if (value.length() != 8) {
                        throw std::invalid_argument("ID must be 8 characters long.");
                    }
                }), "Set the Server ID (length: 8)")
                ("config,c", po::value<std::string>()->required()->value_name("PATH"),"Set a custom path to your Config File, rather then use the default.")
                ("createConfig,r", "Creates the config at the default location");
        po::options_description desc("Allowed options");
        desc.add_options()
                ("setStatus,s", po::value<std::string>()->value_name("STATUS")->notifier([](const std::string& status) {
                    if (!isValidStatus(status)) {
                        throw std::invalid_argument("Invalid value for --status");
                    }
                }), "Set status must be one off these values: \noff \nstart \nkill")
                ("listAll,l", "Lists all servers and IDs")
                ("getInfo,g","Gets the info about a server (requires --id)");


        po::variables_map vm;
        po::store(po::parse_command_line(argc, argv, desc), vm);
        po::notify(vm);

        if (vm.count("interactive")) {
            interactive(location);
            return 0;
        }

        if (vm.count("help") || vm.count("?") || vm.empty()) {
            std::cout << "Usage: pufferstarter_cli [options]\n";
            std::cout << "You NEED a config file to use options, if you (for some reason) do not want to create it, you need to run PufferStarter interactively by using \"-i\"\n";
            std::cout << gen << std::endl << conf << std::endl << desc << std::endl;
        }

        if (vm.count("listAll") || vm.count("l")) {
            if (vm.count("config") || vm.count("c")) {
                location = vm["config"].as<std::string>();
            }
            exit(0);

        }
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
