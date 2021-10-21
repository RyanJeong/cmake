cmake_minimum_required(VERSION 3.11)

project(
  Tutorial-5
  VERSION     0.1
  DESCRIPTION "튜토리얼 #5"
  LANGUAGES   CXX)

#set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)

add_subdirectory(lib)

add_executable(program main.cc)

target_link_libraries(program shape)