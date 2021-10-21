```txt
% tree
.
├── CMakeLists.txt
├── README.md
├── build
├── includes
│   ├── color.h
│   └── shape.h
├── lib
│   ├── CMakeLists.txt
│   ├── color.cc
│   ├── (libfmt.a)
│   ├── (libfoo.a)
│   └── shape.cc
└── main.cc
```

```cmake
# ./lib/CMakeLists.txt

project(
  lib
  LANGUAGES CXX)

#add_library(lib STATIC shape.cc color.cc)
# GLOB 사용 시 편리하게 여러 파일 사용할 수 있음:
# GLOB_RECURSE : 하위 디렉토리까지 재귀탐색
#  - ${CMAKE_CURRENT_SOURCE_DIR}: 현재 CMakeLists.txt(실행 중인 대상)가 위치한 디렉토리
#  - GLOB을 통해 선택된 파일들을 모아 SRC_FILES 변수로 구성
#  - CONFIGURE_DEPENDS는 GLOB를 통해 불러온 파일 목록이 이전에 얻은 파일 목록과
#    다를 경우 CMake를 다시 실행해서 빌드 파일을 재생성하게 됨

# Note: We do not recommend using GLOB to collect a list of 
# source files from your source tree. If no CMakeLists.txt file 
# changes when a source is added or removed then the generated 
# build system cannot know when to ask CMake to regenerate. 
# The CONFIGURE_DEPENDS flag may not work reliably on all 
# generators, or if a new generator is added in the future that 
# cannot support it, projects using it will be stuck. Even if 
# CONFIGURE_DEPENDS works reliably, there is still a cost to 
# perform the check on every rebuild (링크).
# https://cmake.org/cmake/help/v3.15/command/file.html?highlight=glob#glob-recurse
file(GLOB_RECURSE SRC_FILES CONFIGURE_DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/*.cc)

# foo 라이브러리
add_library(foo STATIC ${SRC_FILES})
target_include_directories(foo PUBLIC ${CMAKE_SOURCE_DIR}/includes)
target_compile_options(foo PRIVATE -Wall -Werror)
```

```cmake
# ./CMakeLists.txt

# CMake 프로그램의 최소 버전
cmake_minimum_required(VERSION 3.11)

# 프로젝트 정보
project(
  Tutorial-7
  VERSION     0.1
  DESCRIPTION "튜토리얼 #7"
  LANGUAGES   CXX)

# 정적/동적 라이브러리 ${CMAKE_SOURCE_DIR}/lib 폴더에 생성
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)

# 확인할 디렉토리 추가
add_subdirectory(lib)

# 실행 파일 생성
add_executable(program main.cc)

# An important detail is to place target_link_libraries 
# AFTER the add_executable

# FetchContent 모듈 불러옴
include(FetchContent)

# Fmt 라이브러리를 GIT 저장소로부터 특정 태그 버전으로 가져옴
FetchContent_Declare(
  Fmt
  GIT_REPOSITORY "https://github.com/fmtlib/fmt"
  GIT_TAG "7.1.3")

# Fmt 라이브러리를 위에서 명세한 내용대로 가져와 설치 
FetchContent_MakeAvailable(Fmt)

# 실행 파일 생성 시 링크할 라이브러리 지정
target_link_libraries(program fmt)
target_link_libraries(program shape)
```