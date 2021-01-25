cmake_minimum_required(VERSION 3.17)
project(c01 C)

set(CMAKE_C_STANDARD 99)
set(GCC_COVERAGE_COMPILE_FLAGS "-Wall -Wextra -Werror")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}")

add_executable(
        c01 main.c
        ex00/ft_ft.c
        ex01/ft_ultimate_ft.c
        ex02/ft_swap.c
        ex03/ft_div_mod.c
        ex04/ft_ultimate_div_mod.c
        ex05/ft_putstr.c
        ex06/ft_strlen.c
        ex07/ft_rev_int_tab.c
        ex08/ft_sort_int_tab.c)
