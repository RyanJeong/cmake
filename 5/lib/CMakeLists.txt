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

target_link_libraries(shape PRIVATE hello)