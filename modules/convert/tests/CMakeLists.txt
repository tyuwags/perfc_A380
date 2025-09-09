find_package(Check REQUIRED)

include_directories(${CHECK_INCLUDE_DIRS})
link_directories(${CHECK_LIBRARY_DIRS})

add_executable(check_length "${PROJECT_SOURCE_DIR}/modules/convert/tests/length_tests.c")
add_executable(check_force "${PROJECT_SOURCE_DIR}/modules/convert/tests/force_tests.c")
add_executable(check_mass "${PROJECT_SOURCE_DIR}/modules/convert/tests/mass_tests.c")
add_executable(check_velocity "${PROJECT_SOURCE_DIR}/modules/convert/tests/velocity_tests.c")
target_link_libraries(check_length convert ${CHECK_LIBRARIES})
target_link_libraries(check_force convert ${CHECK_LIBRARIES})
target_link_libraries(check_mass convert ${CHECK_LIBRARIES})
target_link_libraries(check_velocity convert ${CHECK_LIBRARIES})


