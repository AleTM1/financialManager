cmake_minimum_required(VERSION 3.10)
project(financialManager)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOMOC ON)

find_package(Qt5Widgets)


set(SourceList main.cpp Account.cpp Account.h View.h View.cpp Controller.cpp Controller.h Model.cpp Model.h Subject.h Observer.h ViewWindow.h)
add_executable(financialManager ${SourceList})


target_link_libraries(financialManager Qt5::Widgets)
