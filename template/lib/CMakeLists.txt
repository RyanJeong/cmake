add_library(foo STATIC shape.cc color.cc)
target_include_directories(foo PUBLIC ${CMAKE_SOURCE_DIR}/includes)
target_compile_options(foo PRIVATE -Wall -Werror)

add_library(hello STATIC hello.cc)
target_include_directories(hello PUBLIC ${CMAKE_SOURCE_DIR}/includes)
target_compile_options(hello PRIVATE -Wall -Werror)

target_link_libraries(foo PRIVATE hello)