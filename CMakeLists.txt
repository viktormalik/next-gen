cmake_minimum_required(VERSION 3.3)
project(next_gen)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

include_directories(src/)

set(SOURCE_FILES src/main.cpp
        src/cfg/IInstruction.hh
        src/cfg/IInstructionWithOperation.hh
        src/cfg/IOperation.hh
        src/core/IAbstractProgramConfiguration.hh
        src/types/Type.hh
        src/core/ISymState.hh
        src/cfg/IOperationFactory.hh)
add_executable(next_gen ${SOURCE_FILES})