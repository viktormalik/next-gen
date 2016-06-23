/**
 * Parser for LLVM CFG. Transforms LLVM IR into internal CFG (objects of InstructionNode with
 * appropriate operations).
 * @TODO Add parsing all functions, not only main.
 *  Viktor Malik, 21.6.2016 (c).
 */

#pragma once

#include <llvm/IR/Module.h>
#include <cfg/InstructionNode.hh>
#include <cfg/IOperationFactory.hh>

class LlvmSourceParser {
 private:
  llvm::Module* module_;           /**< LLVM module to be parsed */
  IOperationFactory* op_factory_;  /**< Factory to create operations */

 public:
  LlvmSourceParser(llvm::Module* module, IOperationFactory* op_factory);

  virtual ~LlvmSourceParser();

/**
   * Parse LLVM IR given by Module.
   * @return Pointer to the first InstructionNode in the main function of the module (entry point)
   */
  InstructionNode* parseCFG();
  /**
   * Create internal CFG node from given LLVM instruction.
   * Is called recursively and sets all links between nodes.
   * @param instruction LLVM IR instruction (CFG node)
   * @return Pointer to internal CFG node
   */
  InstructionNode* createNodeFromInstruction(llvm::Instruction* instruction);
};


