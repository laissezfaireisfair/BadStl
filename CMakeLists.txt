cmake_minimum_required(VERSION 3.23)
project(BadSTL C)

set(CMAKE_C_STANDARD 23)

add_executable(BadSTL_tests test/tests.c src/vector.c include/vector.h src/list.c include/list.h)
