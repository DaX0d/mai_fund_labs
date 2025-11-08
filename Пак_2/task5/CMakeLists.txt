cmake_minimum_required(VERSION 3.10)

project(task_5)

add_library(task5_lib task5.c)

add_executable(task5_main main.c)

target_link_libraries(task5_main PRIVATE task5_lib m)
