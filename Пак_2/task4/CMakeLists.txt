cmake_minimum_required(VERSION 3.10)

project(task_4)

add_library(task4_lib task4.c)

add_executable(task4_main main.c)

target_link_libraries(task4_main PRIVATE task4_lib m)
