cmake_minimum_required(VERSION 3.11)

project(
  Tutorial-7
  VERSION     0.1
  DESCRIPTION "튜토리얼 #7"
  LANGUAGES   CXX)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)

add_subdirectory(lib)

add_executable(program main.cc)

# An important detail is to place target_link_libraries 
# AFTER the add_executable
include(FetchContent)

FetchContent_Declare(
  Fmt
  GIT_REPOSITORY "https://github.com/fmtlib/fmt"
  GIT_TAG "7.1.3")

FetchContent_MakeAvailable(Fmt)

target_link_libraries(program fmt)

target_link_libraries(program foo)
