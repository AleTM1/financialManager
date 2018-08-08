cmake_minimum_required(VERSION 3.10)
project(financialManager)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOMOC ON)

find_package(Qt5Widgets)


set(SourceList main.cpp)
add_executable(financialManager ${SourceList})


target_link_libraries(financialManager Qt5::Widgets)
