cmake_minimum_required(VERSION 3.25..3.27)
project(pufferstarter_cli)

set(CMAKE_CXX_STANDARD 17)

add_executable(pufferstarter_cli src/main.cpp
        src/menu_and_authenticaton.h
        src/http_request.h
        src/get_server_info.h
        src/print_server_info.h
        src/change_status.h
        src/list_servers.h)
