cmake_minimum_required(VERSION 3.10)

project(task_1)

add_library(task1_lib task1.c)

add_executable(task1_main main.c)

target_link_libraries(task1_main PRIVATE task1_lib)
