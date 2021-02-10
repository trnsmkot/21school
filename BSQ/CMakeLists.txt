cmake_minimum_required(VERSION 3.17)
project(BSQ C)

set(CMAKE_C_STANDARD 99)

add_executable(BSQ src/main.c include/bsq.h src/str_lib.c src/num_lib.c src/io_lib.c src/settings_lib.c src/map_lib.c src/matrix_lib.c)