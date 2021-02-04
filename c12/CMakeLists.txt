cmake_minimum_required(VERSION 3.17)
project(c12 C)

set(CMAKE_C_STANDARD 99)
#set(GCC_COVERAGE_COMPILE_FLAGS "-Wall -Wextra -Werror")
#set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}")

add_executable(c12 main.c
        ex00/ft_create_elem.c
#        ex01/ft_list_push_front.c
        ex09/ft_list_foreach.c
#        ex04/ft_list_push_back.c
        ex10/ft_list_foreach_if.c
        ex11/ft_list_find.c
        ex12/ft_list_remove_if.c)