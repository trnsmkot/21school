cmake_minimum_required(VERSION 3.17)
project(c11 C)

set(CMAKE_C_STANDARD 99)
#set(GCC_COVERAGE_COMPILE_FLAGS "-Wall -Wextra -Werror")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}")

#add_executable(c11 main.c ex00/ft_foreach.c ex01/ft_map.c ex02/ft_any.c ex04/ft_is_sort.c)
add_executable(c11 main.c ex04/ft_is_sort.c)