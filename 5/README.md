```txt
% tree
.
├── CMakeLists.txt
├── README.md
├── build
├── includes
│   ├── hello.h
│   └── shape.h
├── lib
│   ├── CMakeLists.txt
│   ├── hello.cc
│   ├── (libhello.a)
│   ├── (libshape.a)
│   └── shape.cc
└── main.cc
```

```cmake
# ./lib/CMakeLists.txt

project(
  shape-hello
  LANGUAGES CXX)

# SHAPE
add_library(shape STATIC shape.cc)
target_include_directories(shape PUBLIC ${CMAKE_SOURCE_DIR}/includes)
target_compile_options(shape PRIVATE -Wall -Werror)

# HELLO
add_library(hello STATIC hello.cc)
target_include_directories(hello PUBLIC ${CMAKE_SOURCE_DIR}/includes)
target_compile_options(hello PRIVATE -Wall -Werror)

# shape 라이브러리는 hello 라이브러리를 필요로 함 
target_link_libraries(shape PRIVATE hello)
```

```cmake
# ./CMakeLists.txt

# CMake 프로그램의 최소 버전
cmake_minimum_required(VERSION 3.11)

# 프로젝트 정보
project(
  Tutorial-5
  VERSION     0.1
  DESCRIPTION "튜토리얼 #5"
  LANGUAGES   CXX)

# 정적 라이브러리 ${CMAKE_SOURCE_DIR}/lib 폴더에 생성
#set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)

# 확인할 디렉토리 추가
add_subdirectory(lib)

# 실행 파일 생성
add_executable(program main.cc)

# 실행 파일 생성 시 링크할 라이브러리 지정
target_link_libraries(program shape)
```