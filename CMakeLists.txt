cmake_minimum_required(VERSION 3.5)

project(wireless-gui LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt5 COMPONENTS
    Charts
REQUIRED)

add_executable(wireless-gui
  main.cpp
        main_window.cpp
        main_window.h
        live_chart.h
        live_chart.cpp
        )

target_link_libraries(wireless-gui PRIVATE Qt5::Widgets Qt5::Charts)
