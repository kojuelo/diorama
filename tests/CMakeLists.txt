enable_testing()

# Find source files.
file(GLOB DIORAMA_TEST_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/*.c)

# Prepare executable.
add_executable(diorama_tests ${DIORAMA_TEST_SOURCES})

# Output executable to "/bin" directory.
set_target_properties(diorama_tests PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

# Link Diorama library.
target_link_libraries(diorama_tests PRIVATE diorama)

# Include Unity test framework.
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/../third_party/unity ${CMAKE_SOURCE_DIR}/build/third_party/unity)

set_target_properties(unity PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin
    LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

target_link_libraries(diorama_tests PRIVATE unity)

add_test(NAME API COMMAND diorama_tests)