cmake_minimum_required(VERSION 3.16)

project(SchoolTimetable VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Core Widgets)

qt_standard_project_setup()

qt_add_executable(SchoolTimetable
    WIN32 MACOSX_BUNDLE
    main.cpp
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui
    SchoolTimetable.cpp
    SchoolTimetable.h
)

qt_add_resources(SchoolTimetable imageresources
    PREFIX "/images"
    FILES heart.png
)

target_link_libraries(SchoolTimetable PRIVATE Qt::Core Qt::Widgets)
