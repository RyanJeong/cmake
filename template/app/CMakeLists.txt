file(GLOB_RECURSE SRC_FILES CONFIGURE_DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/*.cc)

add_executable(program ${SRC_FILES})
target_link_libraries(program PUBLIC foo)

include(FetchContent)

FetchContent_Declare(
  Fmt
  GIT_REPOSITORY "https://github.com/fmtlib/fmt"
  GIT_TAG "7.1.3"
  )
FetchContent_MakeAvailable(Fmt)

target_link_libraries(program PRIVATE fmt)
