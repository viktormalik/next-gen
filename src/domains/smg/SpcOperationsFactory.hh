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
  IOperation* CreateReturn() override;
  IOperation* CreateBranch() override;
  IOperation* CreateAdd() override;
  IOperation* CreateSub() override;
  IOperation* CreateMul() override;
  IOperation* CreateUdiv() override;
  IOperation* CreateSdiv() override;
  IOperation* CreateUrem() override;
  IOperation* CreateSrem() override;
  IOperation* CreateShl() override;
  IOperation* CreateLshr() override;
  IOperation* CreateAshr() override;
  IOperation* CreateAnd() override;
  IOperation* CreateOr() override;
  IOperation* CreateXor() override;
  IOperation* CreateAlloca() override;
  IOperation* CreateLoad() override;
  IOperation* CreateStore() override;
  IOperation* CreateGetelementptr() override;
  IOperation* CreateIcmp(IcmpCode code) override;
};


