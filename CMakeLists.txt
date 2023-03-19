cmake_minimum_required(VERSION 3.16)

project(SchoolTimetable VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)

find_package(Qt6 REQUIRED COMPONENTS Core Widgets)

add_executable(SchoolTimetable
    main.cpp
    mainwindow.cpp
    mainwindow.h
)

set_target_properties(SchoolTimetable PROPERTIES
    WIN32_EXECUTABLE ON
    MACOSX_BUNDLE ON
)

target_link_libraries(SchoolTimetable PRIVATE Qt6::Core Qt6::Widgets)

