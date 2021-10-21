cmake_minimum_required(VERSION 3.11)

project(
  Tutorial-7
  VERSION     0.1
  DESCRIPTION "튜토리얼 #7"
  LANGUAGES   CXX)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

add_subdirectory(lib)
add_subdirectory(app)