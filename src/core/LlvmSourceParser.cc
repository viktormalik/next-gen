/**
 *  Viktor Malik, 21.6.2016 (c).
 */

#include "LlvmSourceParser.hh"

LlvmSourceParser::LlvmSourceParser(std::unique_ptr<llvm::Module> module,
                                   std::unique_ptr<IOperationFactory> op_factory)
    : module_(std::move(module)), op_factory_(std::move(op_factory)) { }

InstructionNode* LlvmSourceParser::parseCFG() {
  // Get first instruction of function main
  auto& entry_point = module_->getFunction("main")->getEntryBlock().front();

  return createNodeFromInstruction(&entry_point);
}
/**
 * First creates appropriate operation based on LLVM instruction type using operation factory.
 * After that, creates InstructionNode containing pointer to this operation and original LLVM
 * instruction.
 * Finally recursively calls itself on following instruction (or instructions in case of
 * conditional branch) and sets correct links between created CFG nodes. Recursion ends on ret
 * instruction.
 */
InstructionNode* LlvmSourceParser::createNodeFromInstruction(llvm::Instruction* instruction) {
  // Create correct operation
  IOperation* op;
  switch (instruction->getOpcode()) {
    // Terminator instructions
    case llvm::Instruction::Ret:
      op = op_factory_->CreateRet();
      break;
    case llvm::Instruction::Br:
      op = op_factory_->CreateBr();
      break;

      // Binary instructions
    case llvm::Instruction::Add:
      op = op_factory_->CreateAdd();
      break;
    case llvm::Instruction::Sub:
      op = op_factory_->CreateSub();
      break;
    case llvm::Instruction::Mul:
      op = op_factory_->CreateMul();
      break;
    case llvm::Instruction::UDiv:
      op = op_factory_->CreateUDiv();
      break;
    case llvm::Instruction::SDiv:
      op = op_factory_->CreateSDiv();
      break;
    case llvm::Instruction::URem:
      op = op_factory_->CreateURem();
      break;
    case llvm::Instruction::SRem:
      op = op_factory_->CreateSRem();
      break;

      // Bitwise binary instructions
    case llvm::Instruction::Shl:
      op = op_factory_->CreateShl();
      break;
    case llvm::Instruction::LShr:
      op = op_factory_->CreateLShr();
      break;
    case llvm::Instruction::AShr:
      op = op_factory_->CreateAShr();
      break;
    case llvm::Instruction::And:
      op = op_factory_->CreateAnd();
      break;
    case llvm::Instruction::Or:
      op = op_factory_->CreateOr();
      break;
    case llvm::Instruction::Xor:
      op = op_factory_->CreateXor();
      break;

      // Memory access operations
    case llvm::Instruction::Alloca:
      op = op_factory_->CreateAlloca();
      break;
    case llvm::Instruction::Load:
      op = op_factory_->CreateLoad();
      break;
    case llvm::Instruction::Store:
      op = op_factory_->CreateStore();
      break;
    case llvm::Instruction::GetElementPtr:
      op = op_factory_->CreateGetElementPtr();
      break;

      // Other operations
    case llvm::Instruction::ICmp: {
      auto pred = static_cast<llvm::CmpInst*>(instruction)->getPredicate();
      op = op_factory_->CreateICmp(pred);
    }
      break;

    default:
      op = nullptr;
  }

  // Create CFG node
  InstructionNode* inode = new InstructionNode(instruction, op);

  // Create links to next nodes
  if (!instruction->isTerminator()) {
    inode->SetNext(createNodeFromInstruction(instruction->getNextNode()));
  } else {
    // If the instruction is terminator, links go to the next block
    // @TODO Supports only ret and br (conditional and unconditional)
    if (instruction->getOpcode() == llvm::Instruction::Br) {
      auto branch_instr = static_cast<llvm::BranchInst*>(instruction);
      if (branch_instr->isUnconditional()) {
        // Unconditional branch - next is first instruction of target basic block
        inode->SetNext(createNodeFromInstruction(&(branch_instr->getSuccessor(0)->front())));
      } else {
        // Conditional branch - has two successors for true and false branches
        inode->SetNextTrue(createNodeFromInstruction(&(branch_instr->getSuccessor(0)->front())));
        inode->SetNextFalse(createNodeFromInstruction(&(branch_instr->getSuccessor(1)->front())));
      }
    }
  }
}







