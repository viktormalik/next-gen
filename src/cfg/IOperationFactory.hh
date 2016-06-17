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

typedef enum { EQ, NE, UGT, UGE, ULT, ULE, SGT, SGE, SLT, SLE } IcmpCode;

class IOperationFactory {
 public:
  // Terminator operations
  virtual IOperation* CreateReturn() = 0;
  virtual IOperation* CreateBranch() = 0;

  // Binary operations (integers only)
  virtual IOperation* CreateAdd() = 0;
  virtual IOperation* CreateSub() = 0;
  virtual IOperation* CreateMul() = 0;
  virtual IOperation* CreateUdiv() = 0;
  virtual IOperation* CreateSdiv() = 0;
  virtual IOperation* CreateUrem() = 0;
  virtual IOperation* CreateSrem() = 0;

  // Bitwise binary operations
  virtual IOperation* CreateShl() = 0;
  virtual IOperation* CreateLshr() = 0;
  virtual IOperation* CreateAshr() = 0;
  virtual IOperation* CreateAnd() = 0;
  virtual IOperation* CreateOr() = 0;
  virtual IOperation* CreateXor() = 0;

  // Memory access operations
  virtual IOperation* CreateAlloca() = 0;
  virtual IOperation* CreateLoad() = 0;
  virtual IOperation* CreateStore() = 0;
  virtual IOperation* CreateGetelementptr() = 0;

  // Other operations
  virtual IOperation* CreateIcmp(IcmpCode code) = 0;
};


