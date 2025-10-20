cmake_minimum_required(VERSION 4.0)
project(ReportsNew)

set(CMAKE_CXX_STANDARD 20)

add_executable(ReportsNew main.cpp
        Report.cpp
        Report.h
        Employee.cpp
        Employee.h
        Technician.cpp
        Technician.h
        Sample.cpp
        Sample.h
        AsbestosReport.cpp
        AsbestosReport.h)
