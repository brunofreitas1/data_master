cmake_minimum_required(VERSION 3.30)
project(projeto_nava C)

set(CMAKE_C_STANDARD 11)

add_executable(projeto_nava main.c
        func.c
        func.h)
