cmake_minimum_required(VERSION 3.17)
project(libft C)

set(CMAKE_C_STANDARD 99)
#set(GCC_COVERAGE_COMPILE_FLAGS "-Wall -Wextra -Werror")
#set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}")

add_executable(libft main.c libft.h ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c)