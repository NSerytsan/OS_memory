cmake_minimum_required(VERSION 3.0.0)
project(memory VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(app1 app1.c)
add_executable(app2 app2.c)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
