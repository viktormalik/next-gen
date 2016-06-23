/**
 * Abstract factory creating operations (internal implementations of LLVM instructions).
 * For now, contains only basic LLVM operations.
 *
 * Each abstract domain must implement its concrete factory (crteating its own operations).
 *
 *  Viktor Malik, 17.6.2016 (c).
 */

#pragma once

#include <cfg/IOperation.hh>
#include <llvm/IR/Instructions.h>

typedef enum { EQ, NE, UGT, UGE, ULT, ULE, SGT, SGE, SLT, SLE } IcmpCode;

class IOperationFactory {
 public:
  // Terminator operations
  virtual IOperation* CreateRet() = 0;
  virtual IOperation* CreateBr() = 0;

  // Binary operations (integers only)
  virtual IOperation* CreateAdd() = 0;
  virtual IOperation* CreateSub() = 0;
  virtual IOperation* CreateMul() = 0;
  virtual IOperation* CreateUDiv() = 0;
  virtual IOperation* CreateSDiv() = 0;
  virtual IOperation* CreateURem() = 0;
  virtual IOperation* CreateSRem() = 0;

  // Bitwise binary operations
  virtual IOperation* CreateShl() = 0;
  virtual IOperation* CreateLShr() = 0;
  virtual IOperation* CreateAShr() = 0;
  virtual IOperation* CreateAnd() = 0;
  virtual IOperation* CreateOr() = 0;
  virtual IOperation* CreateXor() = 0;

  // Memory access operations
  virtual IOperation* CreateAlloca() = 0;
  virtual IOperation* CreateLoad() = 0;
  virtual IOperation* CreateStore() = 0;
  virtual IOperation* CreateGetElementPtr() = 0;

  // Other operations
  virtual IOperation* CreateICmp(llvm::CmpInst::Predicate code) = 0;

  /**
   * Destructor.
   */
  virtual ~IOperationFactory() { }
};


