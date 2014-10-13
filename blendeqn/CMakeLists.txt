project(blendeqn)
cmake_minimum_required(VERSION 2.8)

SET(CMAKE_BUILD_TYPE DEBUG)

#find glut
find_package(GLUT REQUIRED)
include_directories(${GLUT_INCLUDE_DIRS})
link_directories(${GLUT_LIBRARY_DIRS})
add_definitions(${GLUT_DEFINITIONS})
if(NOT GLUT_FOUND)
   message(ERROR "GLUT not found!")
endif(NOT GLUT_FOUND)

FILE(GLOB SRC_FILES *.c *.cpp)

#aux_source_directory(. SRC_LIST)
#add_executable(${PROJECT_NAME} ${SRC_LIST})
#add_executable(${PROJECT_NAME} ${SRC_FILES})
add_executable(${PROJECT_NAME} fog.c glextfuncget.cpp)

target_link_libraries(${PROJECT_NAME} ${OPENGL_LIBRARIES} ${GLUT_LIBRARIES})
