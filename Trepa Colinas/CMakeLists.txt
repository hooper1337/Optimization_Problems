cmake_minimum_required(VERSION 3.20)
project(TrepaColinas C)

set(CMAKE_C_STANDARD 99)

add_executable(TrepaColinas main.c funcao.c funcao.h utils.h utils.c algoritmo.h algoritmo.c)
