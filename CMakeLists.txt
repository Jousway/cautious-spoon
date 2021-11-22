cmake_minimum_required(VERSION 3.0)

project(SPOON)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

set(SPN_LIB "${CMAKE_CURRENT_LIST_DIR}/Lib")
set(SPN_SRC "${CMAKE_CURRENT_LIST_DIR}/Src")
set(SPN_TOPDIR "${CMAKE_CURRENT_LIST_DIR}")

add_subdirectory(Lib)
add_subdirectory(Src)

set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT ${PROJECT_NAME})
