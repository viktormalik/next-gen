/**
 *  Viktor Malik, 27.6.2016 (c).
 */

#include <gtest/gtest.h>
#include <core/LlvmSourceParser.hh>
#include <core/LlvmLoader.hh>
#include <domains/smg/SpcOperationsFactory.hh>

TEST(LlvmSourceParser, parseCFG) {
  // Load source into IR
  LlvmLoader loader;
  auto module = loader.loadSource("/home/viktor/Documents/fit/VeriFIT/next-gen/next-gen/examples"
                                      "/tests/loader/lowermem.ll");
  // Create factory
  std::unique_ptr<IOperationFactory> factory(new SpcOperationsFactory);

  // Parse IR into CFG
  LlvmSourceParser parser(std::move(module), std::move(factory));
  auto instruction = parser.parseCFG();

  ASSERT_EQ(instruction->Inner_instr()->getOpcode(), llvm::Instruction::Alloca);
  instruction = static_cast<InstructionNode*>(instruction->Next());
  ASSERT_EQ(instruction->Inner_instr()->getOpcode(), llvm::Instruction::Alloca);
  instruction = static_cast<InstructionNode*>(instruction->Next());
  ASSERT_EQ(instruction->Inner_instr()->getOpcode(), llvm::Instruction::Store);
  instruction = static_cast<InstructionNode*>(instruction->Next());
  ASSERT_EQ(instruction->Inner_instr()->getOpcode(), llvm::Instruction::BitCast);
  instruction = static_cast<InstructionNode*>(instruction->Next());
  ASSERT_EQ(instruction->Inner_instr()->getOpcode(), llvm::Instruction::Call);
  instruction = static_cast<InstructionNode*>(instruction->Next());
  ASSERT_EQ(instruction->Inner_instr()->getOpcode(), llvm::Instruction::Ret);
}
