cmake_minimum_required(VERSION 3.11)

project(
  Tutorial-2
  VERSION     0.1
  DESCRIPTION "튜토리얼 #2"
  LANGUAGES   CXX)

add_executable(program main.cc foo.cc)

target_compile_options(program PUBLIC -Wall -Werror)

target_include_directories(program PUBLIC ${CMAKE_SOURCE_DIR}/includes)