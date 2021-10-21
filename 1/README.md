```txt
% tree
.
├── CMakeLists.txt
├── README.md
├── build
├── foo.cc
├── foo.h
└── main.cc
```

```cmake
# CMake 프로그램의 최소 버전
cmake_minimum_required(VERSION 3.11)

# 프로젝트 정보
project(
  Tutorial-1
  VERSION     0.1
  DESCRIPTION "튜토리얼 #1"
  LANGUAGES   CXX)

add_executable (program main.cc foo.cc)
```