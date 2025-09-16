add_library(atmos 
    "${PROJECT_SOURCE_DIR}/modules/atmos/src/temperature.c"
    "${PROJECT_SOURCE_DIR}/modules/atmos/src/pressure.c"
    "${PROJECT_SOURCE_DIR}/modules/atmos/src/density.c")

add_subdirectory(tests)
