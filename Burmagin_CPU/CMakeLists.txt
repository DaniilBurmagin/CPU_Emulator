cmake_minimum_required(VERSION 3.14)
project(Main)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(project)

add_executable(Main main.cpp)
target_link_libraries(Main Source)
include_directories(Main project/include)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
FetchContent_MakeAvailable(googletest)
enable_testing()

file(GLOB SOURCE_TEST project/test/*.cpp)
add_executable(Test ${SOURCE_TEST})
target_link_libraries(Test GTest::gtest_main Source)
include(GoogleTest)
gtest_discover_tests(Test)