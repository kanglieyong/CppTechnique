cmake_minimum_required(VERSION 2.8.12.2)

PROJECT(chapterFirstExample CXX)

MESSAGE(STATUS "project source dir: " ${PROJECT_SOURCE_DIR})
MESSAGE(STATUS "project binary dir: " ${PROJECT_BINARY_DIR})

ADD_DEFINITIONS(-std=c++11)
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")

SET(source main.cpp
           SoundexTest.cpp)

ADD_EXECUTABLE(test ${source})
TARGET_LINK_LIBRARIES(test pthread)
TARGET_LINK_LIBRARIES(test gmock)

SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)

MESSAGE(STATUS "executable output path " ${EXECUTABLE_OUTPUT_PATH})
