cmake_minimum_required(VERSION 3.20.2)
project(Typeset)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

add_library(typeset
  src/typeset.c
  include/typeset.h
)

target_link_libraries(typeset ${CONAN_LIBS})
