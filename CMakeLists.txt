cmake_minimum_required(VERSION 3.7)

project(euler CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -W -Wall -Wextra -Wpedantic -Werror")

# dependencies
set(range-v3_INCLUDE_DIR /home/pierrec/Documents/code/ericniebler/range-v3/include)
add_library(range-v3 INTERFACE IMPORTED)
set_property(TARGET range-v3
  PROPERTY
    INTERFACE_INCLUDE_DIRECTORIES ${range-v3_INCLUDE_DIR}
)

find_package(Boost)

add_subdirectory(1)
add_subdirectory(2)
add_subdirectory(3)
add_subdirectory(4)
add_subdirectory(5)
add_subdirectory(6)
add_subdirectory(7)
add_subdirectory(8)
add_subdirectory(9)

