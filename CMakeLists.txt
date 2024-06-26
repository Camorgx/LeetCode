cmake_minimum_required(VERSION 3.24)
project(LeetCode)
set(CMAKE_C_STANDARD 17)
set(CMAKE_CXX_STANDARD 17)
if ("${CMAKE_BUILD_TYPE}" STREQUAL "Debug")
    set(CMAKE_CXX_FLAGS "-fsanitize=address -fno-omit-frame-pointer")
endif ()

include_directories(include)
aux_source_directory(src/CommonStructure CommonStructure_SRCS)
aux_source_directory(src/Oct2022 Oct2022_SRCS)
aux_source_directory(src/Sept2022 Sept2022_SRCS)
aux_source_directory(src/Feb2024 Feb2024_SRCS)
add_library(CommonStructure ${CommonStructure_SRCS})
add_library(Oct2022 ${Oct2022_SRCS})
add_library(Sept2022 ${Sept2022_SRCS})
add_library(Feb2024 ${Feb2024_SRCS})
add_executable(LeetCode src/LeetCode.cpp)
target_link_libraries(LeetCode CommonStructure)
target_link_libraries(LeetCode Oct2022)
target_link_libraries(LeetCode Sept2022)
target_link_libraries(LeetCode Feb2024)
if (CMAKE_SYSTEM_NAME MATCHES "Linux")
    target_link_libraries(Oct2022 CommonStructure)
    target_link_libraries(Sept2022 CommonStructure)
    target_link_libraries(Feb2024 CommonStructure)
endif ()
