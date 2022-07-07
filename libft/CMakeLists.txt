cmake_minimum_required(VERSION 3.21)

project(ft)

#this is for google test
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_C_STANDARD 99)

add_subdirectory(libft)
add_subdirectory(tests)
add_subdirectory(app)