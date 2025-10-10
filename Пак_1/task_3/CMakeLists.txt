cmake_minimum_required(VERSION 3.10)

project(task_3)

add_library(task3_lib task_3.c)
add_executable(task3 main.c)

target_link_libraries(task3 PRIVATE task3_lib)
