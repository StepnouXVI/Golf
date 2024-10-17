cmake_minimum_required(VERSION 3.12)

project(
  "Golf"
  VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
add_subdirectory(third_party)
add_subdirectory(Domain)
add_subdirectory(Ui)

add_subdirectory(Golf)
