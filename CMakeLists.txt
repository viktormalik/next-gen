cmake_minimum_required(VERSION 3.3)
project(next_gen)

add_subdirectory(tests)

find_package(LLVM REQUIRED CONFIG)
message(STATUS "Found LLVM ${LLVM_PACKAGE_VERSION}")
message(STATUS "Using LLVMConfig.cmake in: ${LLVM_DIR}")

include_directories(${LLVM_INCLUDE_DIRS})
include_directories(src/)

add_definitions(${LLVM_DEFINITIONS})
add_definitions (-std=c++11)

message(STATUS "Cmake libpath ${CMAKE_LIBRARY_PATH}")

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
        src/core/LlvmSourceParser.cc
        src/core/LlvmSourceParser.hh
        src/core/LlvmLoader.cc
        src/core/LlvmLoader.hh)

add_library(nextgen SHARED ${SOURCE_FILES})

llvm_map_components_to_libnames(LLVM_LIBS core support irreader)

target_link_libraries(nextgen ${LLVM_LIBS})
