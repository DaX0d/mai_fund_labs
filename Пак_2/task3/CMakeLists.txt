cmake_minimum_required(VERSION 3.10)

project(task_3)

add_library(task3_lib task3.c)

add_executable(task3_main main.c)

target_link_libraries(task3_main PRIVATE task3_lib m)
