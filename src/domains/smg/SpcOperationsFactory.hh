/**
 * Factory for creating operations (internal implmentations of LLVM instructions) over SPC from
 * SMG abstract domain.
 * Implements abstract factory IOperationFactory.
 *  Viktor Malik, 21.6.2016 (c).
 */

#pragma once

#include <cfg/IOperationFactory.hh>

class SpcOperationsFactory : public IOperationFactory {
 public:
  IOperation* CreateRet() override;
  IOperation* CreateBr() override;
  IOperation* CreateAdd() override;
  IOperation* CreateSub() override;
  IOperation* CreateMul() override;
  IOperation* CreateUDiv() override;
  IOperation* CreateSDiv() override;
  IOperation* CreateURem() override;
  IOperation* CreateSRem() override;
  IOperation* CreateShl() override;
  IOperation* CreateLShr() override;
  IOperation* CreateAShr() override;
  IOperation* CreateAnd() override;
  IOperation* CreateOr() override;
  IOperation* CreateXor() override;
  IOperation* CreateAlloca() override;
  IOperation* CreateLoad() override;
  IOperation* CreateStore() override;
  IOperation* CreateGetElementPtr() override;
  IOperation* CreateICmp(llvm::CmpInst::Predicate code) override;
};


