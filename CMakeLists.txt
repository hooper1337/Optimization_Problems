cmake_minimum_required(VERSION 3.21)
project(teste C)

set(CMAKE_C_STANDARD 99)

add_executable(teste main.c sources/algoritmo.c headers/algoritmo.h sources/utils.c headers/utils.h sources/funcao.c headers/funcao.h)
