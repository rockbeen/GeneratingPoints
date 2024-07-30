cmake_minimum_required(VERSION 3.16)

project(GeneratingPoints)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOMOC ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets)

add_executable(GeneratingPoints
        sourse/main.cpp
        sourse/MainWindow.cpp
        sourse/DisplayPoint.cpp
        sourse/Generator.cpp
)

target_link_libraries(GeneratingPoints Qt6::Widgets)
