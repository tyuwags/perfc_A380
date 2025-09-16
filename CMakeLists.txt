cmake_minimum_required(VERSION 3.10)

project(Performances_A380 VERSION 0.6.0.0)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED True)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

include(CheckCSourceCompiles)
include(CheckCSourceRuns)
include(CheckFunctionExists)
include(CheckIncludeFile)
include(CheckIncludeFiles)
include(CheckLibraryExists)
include(CheckSymbolExists)
include(CheckTypeSize)

macro(ck_check_include_file header var)
  check_include_files("${INCLUDES};${header}" ${var})
  if(${var})
    set(INCLUDES ${INCLUDES} ${header})
  endif(${var})
endmacro(ck_check_include_file)

ck_check_include_file("stdlib.h" HAVE_STDLIB_H)

check_type_size(intmax_t INTMAX_T)
check_type_size(uintmax_t UINTMAX_T)

check_type_size(pid_t PID_T)
if(NOT HAVE_PID_T)
  if(WIN32)
    set(pid_t "int")
  else(WIN32)
    MESSAGE(FATAL_ERROR "pid_t doesn't exist on this platform?")
  endif(WIN32)
endif(NOT HAVE_PID_T)

configure_file("${PROJECT_SOURCE_DIR}/include/config.h.in" config.h)

add_subdirectory(modules)

add_executable(main "${PROJECT_SOURCE_DIR}/src/main.c")
target_link_libraries(main convert atmos)
target_include_directories(main PUBLIC modules "${PROJECT_BINARY_DIR}" "${PROJECT_SOURCE_DIR}/include") 

enable_testing()
add_test(NAME Convert_Length COMMAND check_length)
add_test(NAME Convert_Force COMMAND check_force)
add_test(NAME Convert_Mass COMMAND check_mass)
add_test(NAME Convert_Velocity COMMAND check_velocity)
add_test(NAME Atmos_Temperature COMMAND check_temperature)
add_test(NAME Atmos_Pressure COMMAND check_pressure)
