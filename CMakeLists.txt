cmake_minimum_required(VERSION 4.0)
project(ReportsNew)

set(CMAKE_CXX_STANDARD 20)

add_executable(ReportsNew src/main.cpp
        src/Report.cpp
        include/Report.h
        src/Employee.cpp
        include/Employee.h
        src/Technician.cpp
        include/Technician.h
        src/Sample.cpp
        include/Sample.h
        src/AsbestosReport.cpp
        include/AsbestosReport.h)
