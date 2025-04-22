cmake_minimum_required(VERSION 3.27)
project(HW_4 C)

set(CMAKE_C_STANDARD 11)

add_executable(HW_4 fork.c
        outredir.c
        pip2redir.c
        piperedir.c
        allredir.c
        argredir.c)
