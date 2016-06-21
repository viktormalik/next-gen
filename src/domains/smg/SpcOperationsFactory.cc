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

IOperation* SpcOperationsFactory::CreateReturn() {
  return new SpcOperationRet;
}

IOperation* SpcOperationsFactory::CreateBranch() {
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

IOperation* SpcOperationsFactory::CreateUdiv() {
  return nullptr;
}

IOperation* SpcOperationsFactory::CreateSdiv() {
  return nullptr;
}

IOperation* SpcOperationsFactory::CreateUrem() {
  return nullptr;
}

IOperation* SpcOperationsFactory::CreateSrem() {
  return nullptr;
}

IOperation* SpcOperationsFactory::CreateShl() {
  return nullptr;
}

IOperation* SpcOperationsFactory::CreateLshr() {
  return nullptr;
}

IOperation* SpcOperationsFactory::CreateAshr() {
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

IOperation* SpcOperationsFactory::CreateGetelementptr() {
  return nullptr;
}

IOperation* SpcOperationsFactory::CreateIcmp(IcmpCode code) {
  return nullptr;
}


