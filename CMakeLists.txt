cmake_minimum_required(VERSION 3.0)
project(TicTacToeSFML)

set(CMAKE_CXX_STANDARD 17)

find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)

add_executable(TicTacToeSFML main.cpp)
target_link_libraries(TicTacToeSFML sfml-graphics sfml-window sfml-system)
