project(blendeqn)
cmake_minimum_required(VERSION 2.8)

SET(CMAKE_BUILD_TYPE DEBUG)
add_definitions("-g -Wall")

#find glut
find_package(GLUT REQUIRED)
include_directories(${GLUT_INCLUDE_DIRS})
link_directories(${GLUT_LIBRARY_DIRS})
add_definitions(${GLUT_DEFINITIONS})
if(NOT GLUT_FOUND)
   message(ERROR " GLUT not found!")
endif(NOT GLUT_FOUND)


SET(SRC_LIST list.cpp glextfuncget.cpp glextfuncget.h)
add_executable(${PROJECT_NAME} ${SRC_LIST})
link_directories(/usr/lib/x86_64-linux-gnu)
target_link_libraries(${PROJECT_NAME} ${GLUT_LIBRARIES} libGL.so libGLU.so)
