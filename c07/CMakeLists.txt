cmake_minimum_required(VERSION 3.17)
project(c07 C)

set(CMAKE_C_STANDARD 99)
set(GCC_COVERAGE_COMPILE_FLAGS "-Wall -Wextra -Werror")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}")

add_executable(c07 main.c ex00/ft_strdup.c ex01/ft_range.c ex02/ft_ultimate_range.c ex03/ft_strjoin.c)