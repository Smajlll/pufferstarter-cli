cmake_minimum_required(VERSION 3.25)
project(pufferstarter-cli)

set(CMAKE_CXX_STANDARD 17)


add_executable(pufferstarter-cli src/main.cpp
        src/menu_and_authenticaton.h
        src/http_request.h
        src/get_server_info.h
        src/print_server_info.h
        src/change_status.h
        src/list_servers.h
        src/auth_menu.h
        src/load_config_file.h
        src/see-console.h)




