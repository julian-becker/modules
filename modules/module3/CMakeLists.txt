cmake_minimum_required(VERSION 3.3)
project (module3)
 
set (PROJECT_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include)
set (PROJECT_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
 
set(MODULE_SRCS 
	${PROJECT_SOURCE_DIR}/module.cpp
	${PROJECT_SOURCE_DIR}/Digraph.cpp
	${PROJECT_SOURCE_DIR}/test_mpl.cpp
	${PROJECT_SOURCE_DIR}/Task.cpp
)
 
include_directories("${PROJECT_BINARY_DIR}")
include_directories("${PROJECT_INCLUDE_DIR}")
 
add_library(${PROJECT_NAME} SHARED ${MODULE_SRCS})
