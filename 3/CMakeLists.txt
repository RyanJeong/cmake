cmake_minimum_required(VERSION 3.11)

project(
  Tutorial-3
  VERSION     0.1
  DESCRIPTION "튜토리얼 #3"
  LANGUAGES   CXX)

add_subdirectory(lib)

add_executable(program main.cc)

target_link_libraries(program shape)