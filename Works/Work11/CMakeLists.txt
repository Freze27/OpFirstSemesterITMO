cmake_minimum_required(VERSION 3.26)
project(lab11op C)

set(CMAKE_C_STANDARD 11)

add_executable(lab11op main.c
        geom.h
        geom.c)
