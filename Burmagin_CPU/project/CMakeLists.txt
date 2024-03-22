cmake_minimum_required(VERSION 3.14)

file(GLOB SOURCE_FILES src/*.cpp)
add_library(Source ${SOURCE_FILES})

include_directories(Source include)
