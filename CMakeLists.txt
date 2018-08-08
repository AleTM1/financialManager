cmake_minimum_required(VERSION 3.10)
project(financialManager)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOMOC ON)

find_package(Qt5Widgets)

##########à

add_subdirectory(test)

set(SOURCE_FILES Account.cpp Account.h)
add_executable(financialManager main.cpp)
add_library(core ${SOURCE_FILES})

target_link_libraries(financialManager core Qt5::Widgets)

