cmake_minimum_required(VERSION 3.10)

project(task_2)

add_library(task2_lib task2.c)

add_executable(task2_main main.c)

target_link_libraries(task2_main PRIVATE task2_lib)
