cmake_minimum_required(VERSION 3.13)


project(smalltalkVM)

add_executable(smalltalkVM)
add_subdirectory(src)


target_include_directories(smalltalkVM PRIVATE includes)


