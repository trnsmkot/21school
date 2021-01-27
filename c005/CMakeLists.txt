cmake_minimum_required(VERSION 3.17)
project(c005 C)

set(CMAKE_C_STANDARD 99)
set(GCC_COVERAGE_COMPILE_FLAGS "-Wall -Wextra -Werror")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}")

add_executable(c005 main.c
        ex00/ft_iterative_factorial.c
        ex01/ft_recursive_factorial.c ex02/ft_iterative_power.c ex03/ft_recursive_power.c ex04/ft_fibonacci.c ex05/ft_sqrt.c ex06/ft_is_prime.c ex07/ft_find_next_prime.c ex08/ft_ten_queens_puzzle.c)