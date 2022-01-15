cmake_minimum_required(VERSION 3.5)

## Project
project(cqp)

## Flags and includes for building
# Note that we make sure not to overwrite previous flags
if(NOT WIN32)
  set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -O3")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
  set(CMAKE_C_COMPILE gcc)
  set(CMAKE_CXX_COMPILER g++)
endif()

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/build/)

## Add any additional library paths here
# ${CMAKE_CURRENT_BINARY_DIR} lets you use any library currently being built
link_directories(
  ${CMAKE_CURRENT_BINARY_DIR}
)

## Include headers
# Add all the files needed to compile here
include_directories(
  src/cqapi/include/
  src/codec/uniconn/include/
)

## Including cqapi
file(GLOB CQAPI_SRC
  src/cqapi/*.c
)

## Including codec
file(GLOB CODEC_SRC
  src/codec/json/*.c
  src/codec/uniconn/*.c
)

## Build and link
# Add all the files needed to compile here
add_executable(${PROJECT_NAME}
  ${CQAPI_SRC}
  ${CODEC_SRC}
  src/main.c
)

set_target_properties(${PROJECT_NAME} PROPERTIES SUFFIX ".dll")
