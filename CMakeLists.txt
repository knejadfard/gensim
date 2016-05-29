cmake_minimum_required(VERSION 3.0)

project(gensim)

add_definitions(-Wall -s -Os)

include_directories("${gensim_SOURCE_DIR}/include" "${gensim_BINARY_DIR}")

set(SOURCES "${gensim_SOURCE_DIR}/src/main.cpp")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

add_executable(gensim "${SOURCES}")
