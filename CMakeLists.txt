cmake_minimum_required(VERSION 3.25)
project(pufferstarter_cli)

set(CMAKE_CXX_STANDARD 17)
set(BOOST_INCLUDE_LIBRARIES thread filesystem program_options)
set(BOOST_ENABLE_CMAKE ON)

include(FetchContent)
FetchContent_Declare(
        Boost
        GIT_REPOSITORY https://github.com/boostorg/boost.git
        GIT_TAG boost-1.84.0
        GIT_SHALLOW TRUE
)
FetchContent_MakeAvailable(Boost)


add_executable(pufferstarter_cli src/main.cpp
        src/menu_and_authenticaton.h
        src/http_request.h
        src/get_server_info.h
        src/print_server_info.h
        src/change_status.h
        src/list_servers.h
        src/auth_menu.h
        src/load_config_file.h)

target_link_libraries(pufferstarter_cli PRIVATE Boost::filesystem
        Boost::program_options)



