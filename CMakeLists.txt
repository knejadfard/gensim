cmake_minimum_required(VERSION 2.8)

project(gensim)

add_definitions(-Wall -s -Os)

include_directories("${gensim_SOURCE_DIR}/include" "${gensim_BINARY_DIR}")
link_directories("${gensim_SOURCE_DIR}/lib")

set(SOURCES "${gensim_SOURCE_DIR}/src/main.cpp")

set(CXX_STANDARD 11)
set(CXX_STANDARD_REQUIRED ON)

add_executable(gensim "${SOURCES}")
target_link_libraries(gensim ranum)
