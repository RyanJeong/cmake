# cmake
CMake tutorials

* [`add_executable`](https://cmake.org/cmake/help/latest/command/add_executable.html)
    * 실행 파일 생성 
    ```cmake
    add_executable(<실행 파일 이름> <소스1> <소스2> ... <소스들>)
    ```

* [`target_compile_options`](https://cmake.org/cmake/help/latest/command/target_compile_options.html)
    * 컴파일 옵션 지정
    ```cmake
    target_compile_options(<실행 파일 이름> PUBLIC <컴파일 옵션1> <컴파일 옵션2> ...)
    ```

    * `target_compile_options(program PUBLIC -Wall -Werror)`
        * 컴파일 옵션으로 `-Wall`, `-Werror` 사용
    
* [`target_include_directories`](https://cmake.org/cmake/help/latest/command/target_include_directories.html)
    * 컴파일 시 `include` 경로 지정
    ```cmake
    target_include_directories(<실행 파일 이름> PUBLIC <경로 1> <경로 2> ...)
    ```

    * `target_include_directories(program PUBLIC ${CMAKE_SOURCE_DIR}/includes)`
        * `${CMAKE_SOURCE_DIR}`은 실행되는 `CMakeLists.txt`의 경로

* [`add_library`](https://cmake.org/cmake/help/latest/command/add_library.html)
    * 라이브러리 생성
    ```cmake
    add_library(<라이브러리 이름> [STATIC | SHARED | MODULE ] <소스 1> <소스 2> ...)
    ```
    * `add_library(shape STATIC shape.cc)`
        * 정적 라이브러리 생성

* [`add_subdirectory`](https://cmake.org/cmake/help/latest/command/add_subdirectory.html)
    * CMake가 추가로 확인해야 할 디렉토리 경로 지정
    * CMake는 해당 경로에 위치한 CMake 실행
    ```cmake
    add_subdirectory(<경로>)
    ```

* [`target_link_libraries`](https://cmake.org/cmake/help/latest/command/target_link_libraries.html)
    * 실행 파일을 빌드할 때, 라이브러리 링크
    ```cmake
    target_link_libraries(<실행 파일 이름> [PUBLIC | PRIVATE | INTERFACE] <라이브러리 이름>)
    ```

    * 어떤 라이브러리를 사용하고자 할 떄:
        * 라이브러리의 내용을 헤더 파일과 소스 파일에서 모두 사용: `PUBLIC`
        * 라이브러리의 내용을 소스 파일에서만 사용: `PRIVATE`
        * 라이브러리의 내용을 헤더 파일에서만 사용: `INTERFACE`

* [`file`](https://cmake.org/cmake/help/latest/command/file.html)
    * 디렉토리에 있는 파일 추가
    ```cmake
    file(GLOB_RECURSE SRC_FILES CONFIGURE_DEPENDS
        ${CMAKE_CURRENT_SOURCE_DIR}/*.cc
    )
    ```

    * 현재 디렉토리부터 하위 디렉토리까지 존재하는 파일을 모두 모아서 `SRC_FILES`라는 변수를 구성
    * 만약 현재 디렉토리에 있는 파일만 모아서 처리하고자 할 때(하위 디렉토리를 포함하고 싶지 않다면), `GLOB` 사용
    * `CONFIGURE_DEPENDS` 옵션은 `GLOB`으로 파일을 불러올 때 파일 목록이 이전에 갖고 있던 정보와 다를 경우 CMake를 다시 실행해 빌드 파일을 재생성하라는 의미

* [`FetchContent`](https://cmake.org/cmake/help/latest/module/FetchContent.html)
    * `cmake_minimum_required(VERSION 3.11)`
    * 외부 라이브러리를 불러오고 설치할 수 있는 기능
    ```cmake
    include(FetchContent)
    FetchContent_Declare(
      Fmt
      GIT_REPOSITORY "https://github.com/fmtlib/fmt"
      GIT_TAG "7.1.3"
    )
    FetchContent_MakeAvailable(Fmt)
    ```

    * `include`를 사용해 `FetchContent` 모듈 불러옴
    * `FetchContent_Declare`는 어느 외부 라이브러리를 가져올지 명세: 
        * `Fmt`: 외부 라이브러리
        * `GIT_REPOSITORY`: 외부 라이브러리 코드 저장 위치
        * `GIT_TAG`: 설치할 외부 라이브러리의 tag
    * `FetchContent_MakeAvailable`는 외부 라이브러리를 사용할 수 있게 함
    * `FetchContent`를 통해 가져온 외부 라이브러리는 프로젝트 전체에서 사용 가능
* Locations:
> CMAKE_BINARY_DIR : if you are building in-source, this is the same
as CMAKE_SOURCE_DIR, otherwise this is the top level directory of
your build tree

> CMAKE_COMMAND : this is the complete path of the cmake which runs
currently (e.g. /usr/local/bin/cmake). Note that if you have
custom commands that invoke cmake -E, it is very important to
use CMAKE_COMMAND as the CMake executable, because CMake might not
be on the system PATH.

> CMAKE_CURRENT_BINARY_DIR : if you are building in-source, this is
the same as CMAKE_CURRENT_SOURCE_DIR, otherwise this is the
directory where the compiled or generated files from the current
CMakeLists.txt will go to.

> CMAKE_CURRENT_SOURCE_DIR : this is the directory where the
currently processed CMakeLists.txt is located in

> CMAKE_CURRENT_LIST_FILE : this is the full path to the listfile
currently being processed.

> CMAKE_CURRENT_LIST_DIR : (since 2.8.3) this is the directory
of the listfile currently being processed.

> CMAKE_CURRENT_LIST_LINE : this is linenumber where the variable
is used.

> CMAKE_FILES_DIRECTORY : the directory within the current binary
directory that contains all the CMake generated files. Typically
evaluates to "/CMakeFiles". Note the leading slash for the
directory. Typically used with the current binary directory, i.e.
${CMAKE_CURRENT_BINARY_DIR}${CMAKE_FILES_DIRECTORY}

> CMAKE_MODULE_PATH : tell CMake to search first in directories
listed in CMAKE_MODULE_PATH when you use FIND_PACKAGE() or
INCLUDE()
SET(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/MyCMakeScripts)
FIND_PACKAGE(HelloWorld)

> CMAKE_ROOT : this is the CMake installation directory

> CMAKE_SOURCE_DIR : this is the directory which contains the
top-level CMakeLists.txt, i.e. the top level source directory

> PROJECT_NAME : the name of the project set by PROJECT() command.

> CMAKE_PROJECT_NAME : the name of the first project set by the
PROJECT() command, i.e. the top level project.

> PROJECT_BINARY_DIR : contains the full path to the top level
directory of your build tree

> PROJECT_SOURCE_DIR : contains the full path to the root of your
project source directory, i.e. to the nearest directory where
CMakeLists.txt contains the PROJECT() command

## Index
* [실행파일 만들기](./1)
* [`include` 경로를 지정하여 실행파일 만들기](./2)
* [라이브러리 생성 및 연결](./3)
* [특정 경로에 라이브러리 생성 및 연결](./4)
* [다른 라이브러리를 필요로 하는 라이브러리](./5)
* [한 번에 여러 파일 추가하기](./6)
* [`FetchContent` 예제](./7)
* [CMake 템플릿](./template)

## [Documentation](https://cmake.org/documentation/)
* [v3.22](https://cmake.org/cmake/help/v3.22/)

## References:
* [C++ 프로젝트를 위한 CMake 사용법](https://modoocode.com/332)
* [CGold: The Hitchhiker’s Guide to the CMake](https://cgold.readthedocs.io/en/latest/)
* [CMake 할때 쪼오오금 도움이 되는 문서](https://gist.github.com/luncliff/6e2d4eb7ca29a0afd5b592f72b80cb5c)
