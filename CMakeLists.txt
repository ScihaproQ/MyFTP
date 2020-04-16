cmake_minimum_required(VERSION 3.15)
project(NWP_myftp_2019 C)

set(CMAKE_C_STANDARD 11)

include_directories(include)

add_executable(NWP_myftp_2019
        bootstrap.c
        bootstrap.h src/main.c include/ftp.h client.c)
