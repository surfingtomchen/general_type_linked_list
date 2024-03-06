cmake_minimum_required(VERSION 3.27)
project(general_linked_list C)

set(CMAKE_C_STANDARD 11)

add_executable(general_linked_list main.c
        general_linked_list.c
        general_linked_list.h
        struct_a.c
        struct_a.h)
