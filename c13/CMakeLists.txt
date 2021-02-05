cmake_minimum_required(VERSION 3.17)
project(c13 C)

set(CMAKE_C_STANDARD 99)

add_executable(c13 main.c ex00/btree_create_node.c ex01/btree_apply_prefix.c ex02/btree_apply_infix.c ex03/btree_apply_suffix.c ex04/btree_insert_data.c)