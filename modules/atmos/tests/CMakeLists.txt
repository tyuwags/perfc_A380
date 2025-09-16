find_package(Check REQUIRED)

include_directories(${CHECK_INCLUDE_DIRS})
link_directories(${CHECK_LIBRARY_DIRS})

add_executable(check_temperature "${PROJECT_SOURCE_DIR}/modules/atmos/tests/temperature_tests.c")
add_executable(check_pressure "${PROJECT_SOURCE_DIR}/modules/atmos/tests/pressure_tests.c")
add_executable(check_density "${PROJECT_SOURCE_DIR}/modules/atmos/tests/density_tests.c")
target_link_libraries(check_temperature atmos ${CHECK_LIBRARIES})
target_link_libraries(check_pressure atmos ${CHECK_LIBRARIES})
target_link_libraries(check_density atmos ${CHECK_LIBRARIES})
