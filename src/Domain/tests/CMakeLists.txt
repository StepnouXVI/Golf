set(namespace "Golf")
project(
  "TestsForGolf"
  VERSION 0.1.1)

set(TEST_SOURCE src/main.cpp)

# find_package(GTest CONFIG REQUIRED)
include_directories(include ../include/private ../include/public)

add_executable(${PROJECT_NAME} ${TEST_SOURCE})
target_link_libraries(${PROJECT_NAME} Domain GTest::gtest
                      GTest::gtest_main GTest::gmock GTest::gmock_main)

add_test(NAME tests_for_golf COMMAND ${PROJECT_NAME})
