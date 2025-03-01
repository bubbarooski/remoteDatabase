cmake_minimum_required(VERSION 3.30)
project(remoteDatabase C)

include_directories(client)
include_directories(database)
include_directories(startup)

set(CMAKE_C_STANDARD 17)
set(CMAKE_C_COMPILER gcc)

add_executable(remoteDatabase
        main.C
        database/database.h
        startup/dataCreation.h
)

# find_package(Python3 3.12 COMPONENTS Interpreter Development)
