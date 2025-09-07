add_library(convert 
    "${PROJECT_SOURCE_DIR}/modules/convert/src/utils.c"
    "${PROJECT_SOURCE_DIR}/modules/convert/src/length.c"
    "${PROJECT_SOURCE_DIR}/modules/convert/src/force.c"
    "${PROJECT_SOURCE_DIR}/modules/convert/src/velocity.c"
    "${PROJECT_SOURCE_DIR}/modules/convert/src/mass.c")

add_subdirectory(tests)

