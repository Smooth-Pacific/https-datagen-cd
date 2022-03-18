cmake_minimum_required(VERSION 3.0.0)
project(csv_xml VERSION 0.1.0)
set(TARGET "csv_xml")

include(CTest)
enable_testing()

# specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

## add directories
add_subdirectory(src)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
