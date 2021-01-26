cmake_minimum_required(VERSION 3.17)
project(c04 C)

set(CMAKE_C_STANDARD 99)
set(GCC_COVERAGE_COMPILE_FLAGS "-Wall -Wextra -Werror")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}")

add_executable(c04 main.c
        ex02/ft_putnbr.c
        ex05/ft_atoi_base.c ex05/ft_atoi_base.h)