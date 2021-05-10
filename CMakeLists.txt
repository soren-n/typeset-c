cmake_minimum_required(VERSION 3.20.2)
project(Typeset)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

set(TYPESET_SOURCES
  src/typeset.c
)
if(${CONAN_SETTINGS_OS_BUILD} STREQUAL "Macos")
  set(TYPESET_SOURCES ${TYPESET_SOURCES}
    src/arena_unix.c
  )
elseif(${CONAN_SETTINGS_OS_BUILD} STREQUAL "Linux")
  set(TYPESET_SOURCES ${TYPESET_SOURCES}
    src/arena_unix.c
  )
elseif(${CONAN_SETTINGS_OS_BUILD} STREQUAL "Windows")
  set(TYPESET_SOURCES ${TYPESET_SOURCES}
    src/arena_windows.c
  )
endif()

add_library(typeset ${TYPESET_SOURCES})

target_link_libraries(typeset ${CONAN_LIBS})
