```txt
% tree
.
├── CMakeLists.txt
├── README.md
├── build
├── foo.cc
├── includes
│   └── foo.h
└── main.cc
```

```cmake
# CMake 프로그램의 최소 버전
cmake_minimum_required(VERSION 3.11)

# 프로젝트 정보
project(
  Tutorial-2
  VERSION     0.1
  DESCRIPTION "튜토리얼 #2"
  LANGUAGES   CXX)

# 실행 파일 생성 
add_executable(program main.cc foo.cc)

# 타켓 컴파일 옵션
target_compile_options(program PUBLIC -Wall -Werror)

# 실행 파일 생성 시 필요한 헤더파일 경로
target_include_directories(program PUBLIC ${CMAKE_SOURCE_DIR}/includes)
```