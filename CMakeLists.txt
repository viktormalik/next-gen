cmake_minimum_required(VERSION 3.3)
project(next_gen)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

include_directories(src/)
include_directories(/home/viktor/local/include)

set(SOURCE_FILES
        src/cfg/IInstruction.hh
        src/cfg/IInstructionWithOperation.hh
        src/cfg/IOperation.hh
        src/core/IAbstractProgramConfiguration.hh
        src/types/Type.hh
        src/core/ISymState.hh
        src/cfg/IOperationFactory.hh
        src/cfg/InstructionNode.cc
        src/cfg/InstructionNode.hh
        src/domains/smg/operations/BaseSpcOperation.cc
        src/domains/smg/operations/BaseSpcOperation.hh
        src/domains/smg/Spc.cc
        src/domains/smg/Spc.hh
        src/domains/smg/SpcSymbolicState.cc
        src/domains/smg/SpcSymbolicState.hh
        src/domains/smg/SpcOperationsFactory.cc
        src/domains/smg/SpcOperationsFactory.hh
        src/domains/smg/operations/SpcOperationAlloca.cc
        src/domains/smg/operations/SpcOperationAlloca.hh
        src/domains/smg/operations/SpcOperationStore.cc
        src/domains/smg/operations/SpcOperationStore.hh
        src/domains/smg/operations/SpcOperationLoad.cc
        src/domains/smg/operations/SpcOperationLoad.hh
        src/domains/smg/operations/SpcOperationAdd.cc
        src/domains/smg/operations/SpcOperationAdd.hh
        src/domains/smg/operations/SpcOperationRet.cc
        src/domains/smg/operations/SpcOperationRet.hh
        )

add_library(nextgen SHARED ${SOURCE_FILES})