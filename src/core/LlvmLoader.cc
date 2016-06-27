/**
 *  Viktor Malik, 23.6.2016 (c).
 */

#include "LlvmLoader.hh"
#include <llvm/IRReader/IRReader.h>
#include <llvm/Support/SourceMgr.h>

std::unique_ptr<llvm::Module> LlvmLoader::loadSource(std::string source_file) {
  llvm::SMDiagnostic err;
  llvm::LLVMContext &context = llvm::getGlobalContext();

  auto module = llvm::parseIRFile(source_file, err, context);

  return module;
}

