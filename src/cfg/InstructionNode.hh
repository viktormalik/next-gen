/**
 * Node in CFG wrapping node from LLVM IR.
 * Wraps original LLVM instruction, pointers to next and previous nodes and implementation of the
 * operation simulating this LLVM instruction.
 * Implements interface IInstructionWithOperation.
 *
 *  Viktor Malik, 20.6.2016 (c).
 */

#pragma once

#include <cfg/IInstruction.hh>
#include <cfg/IInstructionWithOperation.hh>
#include <core/ISymState.hh>

#include <llvm/IR/Instruction.h>
#include <vector>

class InstructionNode: public IInstructionWithOperation {
 private:
  IInstruction* next_;              /**< Next CFG node */
  IInstruction* next_true_;         /**< Next CFG node in True branch */
  IInstruction* next_false_;        /**< Next CFG node in False branch */
  std::vector<IInstruction*> prev_; /**< Previous CFG nodes */
  std::vector<ISymState*> states_;  /**< Symbolic states of the program in this CFG node */

  llvm::Instruction* inner_instr_;  /**< LLVM instruction wrapped by this CFG node */

  /**
   * Operation performed by this node (depends on inner instruction)
   */
  IOperation* operation_impl_;

 public:
  /**
   * Constructor with LLVM instruction and wrapper operation assignment.
   * @param inner_instr Pointer to the LLVM instruction in this CFG node
   * @param operation_impl Pointer to the operation performed by this node
   */
  InstructionNode(llvm::Instruction* inner_instr, IOperation* operation_impl);

  // Methods from the interface IInstructionWithOperation (see IInstructionWithOperation.hh for
  // documentation
  IInstruction* Next() const;
  IInstruction* NextTrue() const;
  IInstruction* NextFalse() const;
  std::vector<IInstruction*> Prev() const;
  void SetNext(IInstruction* next);
  void SetNextTrue(IInstruction* next_true);
  void SetNextFalse(IInstruction* next_false);
  void AddPrev(IInstruction* prev);
  std::vector<ISymState*> States() const;
  std::vector<std::unique_ptr<ISymState>>
      Do(ISymState* state, std::vector<VariableId> args);

  /**
   * Inner LLVM instruction (node in LLVM IR CFG).
   * @return Pointer to the original LLVM instruction which is wrapped by this node.
   */
  llvm::Instruction* Inner_instr() const;
};


