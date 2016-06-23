/**
 * @TODO Only operations needed for the first case are implemented so far.
 *  Viktor Malik, 21.6.2016 (c).
 */

#include "SpcOperationsFactory.hh"
#include <domains/smg/operations/SpcOperationRet.hh>
#include <domains/smg/operations/SpcOperationAdd.hh>
#include <domains/smg/operations/SpcOperationAlloca.hh>
#include <domains/smg/operations/SpcOperationLoad.hh>
#include <domains/smg/operations/SpcOperationStore.hh>

IOperation* SpcOperationsFactory::CreateRet() {
  return new SpcOperationRet;
}

IOperation* SpcOperationsFactory::CreateBr() {
  return nullptr;
}

IOperation* SpcOperationsFactory::CreateAdd() {
  return new SpcOperationAdd;
}

IOperation* SpcOperationsFactory::CreateSub() {
  return nullptr;
}

IOperation* SpcOperationsFactory::CreateMul() {
  return nullptr;
}

IOperation* SpcOperationsFactory::CreateUDiv() {
  return nullptr;
}

IOperation* SpcOperationsFactory::CreateSDiv() {
  return nullptr;
}

IOperation* SpcOperationsFactory::CreateURem() {
  return nullptr;
}

IOperation* SpcOperationsFactory::CreateSRem() {
  return nullptr;
}

IOperation* SpcOperationsFactory::CreateShl() {
  return nullptr;
}

IOperation* SpcOperationsFactory::CreateLShr() {
  return nullptr;
}

IOperation* SpcOperationsFactory::CreateAShr() {
  return nullptr;
}

IOperation* SpcOperationsFactory::CreateAnd() {
  return nullptr;
}

IOperation* SpcOperationsFactory::CreateOr() {
  return nullptr;
}

IOperation* SpcOperationsFactory::CreateXor() {
  return nullptr;
}

IOperation* SpcOperationsFactory::CreateAlloca() {
  return new SpcOperationAlloca;
}

IOperation* SpcOperationsFactory::CreateLoad() {
  return new SpcOperationLoad;
}

IOperation* SpcOperationsFactory::CreateStore() {
  return new SpcOperationStore;
}

IOperation* SpcOperationsFactory::CreateGetElementPtr() {
  return nullptr;
}

IOperation* SpcOperationsFactory::CreateICmp(llvm::CmpInst::Predicate code) {
  return nullptr;
}


