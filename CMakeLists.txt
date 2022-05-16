cmake_minimum_required(VERSION 3.22)
project(OOP4)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(OOP_Task4
        Point.cpp
        allShapes.h
        Square.h
        Circle.h
        allShapes.cpp
        Point.h
        Square.cpp
        Shape.h
        Shape.cpp
        Quad.h
        Circle.cpp
        Quad.cpp
        MainTrain.cpp)
