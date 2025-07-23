cmake_minimum_required(VERSION 3.10)

project(Performances_A380 VERSION 0.1.0.0)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED True)

configure_file("${PROJECT_SOURCE_DIR}/include/config.h.in" config.h)

add_subdirectory(aircraft modules)

add_executable(main "${PROJECT_SOURCE_DIR}/src/main.c")

target_include_directories(main PUBLIC "${PROJECT_BINARY_DIR}" "${PROJECT_SOURCE_DIR}/include") 
