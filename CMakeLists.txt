cmake_minimum_required(VERSION 3.10)
project(roaring_demo
  LANGUAGES CXX C
)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_C_STANDARD 11)

add_executable(hello hello.cpp)
# You can add CPM.cmake like so:
# mkdir -p cmake
# wget -O cmake/CPM.cmake https://github.com/cpm-cmake/CPM.cmake/releases/latest/download/get_cpm.cmake
include(cmake/CPM.cmake)
CPMAddPackage(
  NAME roaring
  GITHUB_REPOSITORY "RoaringBitmap/CRoaring"
  GIT_TAG v2.0.4
  OPTIONS "BUILD_TESTING OFF"
)

target_link_libraries(hello roaring::roaring)