cmake_minimum_required(VERSION 3.11)

project(
  Tutorial-6
  VERSION     0.1
  DESCRIPTION "튜토리얼 #6"
  LANGUAGES   CXX)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)
add_subdirectory(lib)

add_executable(program main.cc)
target_link_libraries(program foo)
