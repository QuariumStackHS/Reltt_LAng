cmake_minimum_required(VERSION 3.17)
project(Reltt_LAng)
set(CMAKE_CXX_STANDARD 17)

add_executable(Reltt Reltt/main.cpp Reltt/Reltt.cpp)
add_executable(Installer Installer/Installer.cpp)