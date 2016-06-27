/**
 * Builder for the source code. Compiles source program into LLVM IR and runs selected passes on it.
 * @TODO Selection and scaling of the passes
 *  Viktor Malik, 23.6.2016 (c).
 */

#pragma once

#include <llvm/IR/Module.h>
#include <string>

class LlvmLoader {
 public:
  /**
   * Build source into LLVM IR.
   * @param source_file Path to the source program
   */
  std::unique_ptr<llvm::Module> loadSource(std::string source_file);
};


