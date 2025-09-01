find_package(Check REQUIRED)

include_directories(${CHECK_INCLUDE_DIRS})
link_directories(${CHECK_LIBRARY_DIRS})

add_executable(check_convert "${PROJECT_SOURCE_DIR}/modules/convert/tests/convert_tests.c")
target_link_libraries(check_convert convert ${CHECK_LIBRARIES})

