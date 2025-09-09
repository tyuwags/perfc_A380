find_package(Check REQUIRED)

include_directories(${CHECK_INCLUDE_DIRS})
link_directories(${CHECK_LIBRARY_DIRS})

add_executable(check_temperature "${PROJECT_SOURCE_DIR}/modules/atmos/tests/temperature_tests.c")
target_link_libraries(check_temperature atmos ${CHECK_LIBRARIES})
