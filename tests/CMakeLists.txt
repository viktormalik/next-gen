cmake_minimum_required(VERSION 2.8)
project(tests)

find_package(LLVM REQUIRED CONFIG)
message(STATUS "Found LLVM ${LLVM_PACKAGE_VERSION}")
message(STATUS "Using LLVMConfig.cmake in: ${LLVM_DIR}")

include_directories(${LLVM_INCLUDE_DIRS})
include_directories(../src/)

add_definitions(${LLVM_DEFINITIONS})
add_definitions (-std=c++11)

message(STATUS "Cmake libpath ${CMAKE_LIBRARY_PATH}")

set(TESTS core/LlvmLoaderTest.cc core/LlvmSourceParserTest.cc)

add_executable(tests ${TESTS})

# Link against LLVM libraries, Google test and nextgen library
target_link_libraries(tests gtest gtest_main)
target_link_libraries(tests nextgen)
