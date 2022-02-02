# CMakeLists 
# Created by ContCh (cc).

cmake_minimum_required(VERSION 3.20.1)
project(Optimized_GEMM)

include_directories(${PROJECT_SOURCE_DIR}/include)

set(CPPFILE "${PROJECT_SOURCE_DIR}/tests/TEST_clock.cpp")
add_executable(run_test ${CPPFILE})
