/**
 *  Viktor Malik, 20.6.2016 (c).
 */

#include "InstructionNode.hh"

InstructionNode::InstructionNode(llvm::Instruction* inner_instr, IOperation* operation_impl)
    : inner_instr_(inner_instr), operation_impl_(operation_impl) { }

IInstruction* InstructionNode::Next() const {
  return next_;
}

IInstruction* InstructionNode::NextTrue() const {
  return next_true_;
}

IInstruction* InstructionNode::NextFalse() const {
  return next_false_;
}

std::vector<IInstruction*> InstructionNode::Prev() const {
  return prev_;
}

std::vector<ISymState*> InstructionNode::States() const {
  return states_;
}

std::vector<std::unique_ptr<ISymState>> InstructionNode::Do(ISymState* state,
                                                            std::vector<VariableId> args) {
  return operation_impl_->Do(state, args);
}

llvm::Instruction* InstructionNode::Inner_instr() const {
  return inner_instr_;
}

void InstructionNode::SetNext(IInstruction* next) {
  next_ = next;
  next_->AddPrev(this);
}

void InstructionNode::SetNextTrue(IInstruction* next_true) {
  next_true_ = next_true;
  next_true_->AddPrev(this);
}

void InstructionNode::SetNextFalse(IInstruction* next_false) {
  next_false_ = next_false;
  next_false_->AddPrev(this);
}

void InstructionNode::AddPrev(IInstruction* prev) {
  prev_.push_back(prev);
}
