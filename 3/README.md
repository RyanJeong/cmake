```txt
% tree
.
├── CMakeLists.txt
├── README.md
├── build
├── includes
│   └── shape.h
├── lib
│   ├── CMakeLists.txt
│   └── shape.cc
└── main.cc
```

```cmake
# ./lib/CMakeLists.txt

project(
  shape
  LANGUAGES CXX)

# 정적 라이브러리 shape 생성
# 동적 라이브러리는 SHARED
add_library(shape STATIC shape.cc)

# 해당 라이브러리 컴파일 시 사용할 헤더 파일 경로
# . shape 컴파일 시 헤더 파일 검색 경로에 ${CMAKE_SOURCE_DIR}/includes 추가
# . shape 라이브러리를 참조하는 타겟의 해더 파일 검색 경로에 ${CMAKE_SOURCE_DIR}/includes 추가
target_include_directories(shape PUBLIC ${CMAKE_SOURCE_DIR}/includes)

# 해당 라이브러리 컴파일 시 사용할 옵션들
target_compile_options(shape PRIVATE -Wall -Werror)
```

```cmake
# ./CMakeLists.txt

# CMake 프로그램의 최소 버전
cmake_minimum_required(VERSION 3.11)

# 프로젝트 정보
project(
  Tutorial-3
  VERSION     0.1
  DESCRIPTION "튜토리얼 #3"
  LANGUAGES   CXX)

# 확인할 디렉토리 추가
#    해당 경로에 CMakeLists.txt 있을 때 해당 파일 실행
add_subdirectory(lib)

# 실행 파일 생성
add_executable(program main.cc)

# 실행 파일 생성 시 링크할 라이브러리 지정
target_link_libraries(program shape)
```