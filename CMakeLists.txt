cmake_minimum_required(VERSION 3.10)
project(Sorting)

set(EXECUTABLE ${CMAKE_PROJECT_NAME}_RUN)
set(CMAKE_CXX_STANDARD 17)

include_directories(${PROJECT_SOURCE_DIR}/include)

add_subdirectory(source)
add_subdirectory(test)
add_subdirectory(library/googletest)

file(GLOB_RECURSE SOURCES LIST_DIRECTORIES true include/*.hpp source/*.cpp)
add_executable(${EXECUTABLE} ${SOURCES})
add_library(${CMAKE_PROJECT_NAME}_lib STATIC ${SOURCES})
