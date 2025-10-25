cmake_minimum_required(VERSION 3.10)

project(task_4)

add_library(task4_lib task_4.c)
add_executable(task4 main.c)

target_link_libraries(task4 PRIVATE task4_lib m)
