cmake_minimum_required(VERSION 2.8)

project(gensim)

add_definitions(-Wall -s -Os)

include_directories("${PROJECT_SOURCE_DIR}")

add_executable(gensim main.cpp)
