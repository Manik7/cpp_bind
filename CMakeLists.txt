cmake_minimum_required(VERSION 3.12)

project(cpp_bind)

set(CMAKE_CXX_STANDARD 17)
 
# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Link unit_tests with what we want to test and the GTest and pthread library
add_executable(unit_tests ${SOURCES}
                          test/main.cpp
                          test/test_bind.cpp
)
target_link_libraries(unit_tests ${GTEST_LIBRARIES} pthread)
