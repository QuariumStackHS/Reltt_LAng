cmake_minimum_required(VERSION 3.17)
project(Reltt_LAng)
#find_package(Qt5Widgets REQUIRED)
set(CMAKE_CXX_STANDARD 17)

add_executable(Reltt Reltt/main.cpp Reltt/Reltt.cpp)
add_executable(Installer Installer/Installer.cpp)
#target_link_libraries(Reltt_LAng Qt5::Widgets)