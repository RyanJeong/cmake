cmake_minimum_required(VERSION 3.11)

project(
  Tutorial-1
  VERSION     0.1
  DESCRIPTION "튜토리얼 #1"
  LANGUAGES   CXX)

add_executable (program main.cc foo.cc)