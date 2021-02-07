cmake_minimum_required(VERSION 3.17)
project(rush02 C)

set(CMAKE_C_STANDARD 99)
#set(GCC_COVERAGE_COMPILE_FLAGS "-Wall -Wextra -Werror")
#set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}")

add_executable(rush02
        src/main.c
        src/parse_dictionary.c
        src/parse_number.c
        src/ft_strlen.c
        src/ft_putstr.c
        src/convert_number.c)