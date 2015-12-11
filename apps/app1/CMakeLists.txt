cmake_minimum_required(VERSION 3.3)
project (app1)
 
set (PROJECT_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include)
set (PROJECT_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
 
set(APP_SRCS
	${PROJECT_SOURCE_DIR}/main.cpp 
	${PROJECT_SOURCE_DIR}/Module.cpp 
	${PROJECT_SOURCE_DIR}/ModuleLoader.cpp 
)
 
include_directories("${PROJECT_BINARY_DIR}")
add_executable(app1 ${APP_SRCS})
include_directories("${PROJECT_INCLUDE_DIR}")
