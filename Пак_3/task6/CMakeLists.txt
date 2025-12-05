cmake_minimum_required(VERSION 3.10)

project(task_6)

add_library(task6_lib task6.c)

add_executable(task6_main main.c)

target_link_libraries(task6_main PRIVATE task6_lib)
