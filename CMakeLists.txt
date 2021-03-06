cmake_minimum_required(VERSION 3.17)
project(Reltt_LAng)

set(CMAKE_CXX_STANDARD 17)

add_executable(Reltt_LAng Reltt/main.cpp Reltt/Reltt.cpp)
add_executable(Reltt_Installer Installer/Installer.cpp Reltt/Modules/ASM.c Reltt/Modules/ASM.h)
