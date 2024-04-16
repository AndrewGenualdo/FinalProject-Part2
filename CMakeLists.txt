cmake_minimum_required(VERSION 3.27)
project(FinalProject_Part2)

set(CMAKE_CXX_STANDARD 17)

add_executable(FinalProject_Part2 final_part4.cpp
        doctor.cpp
        doctor.h
        person.cpp
        patient.cpp
        doctorOperations.cpp
        doctorOperations.h
        patientOperations.cpp
        patientOperations.h
        commonOperations.cpp
        commonOperations.h
        commonOperations.cpp)
