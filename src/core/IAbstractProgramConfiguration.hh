/**
 * Interface for abstract domain SPC (symbolic program configuration).
 * It is the only communication point with the abstract domains.
 *
 *  Viktor Malik, 16.6.2016 (c).
 */

#pragma once

#include <cfg/IInstruction.hh>
#include <types/Type.hh>

typedef int VariableId;

typedef int ValuePtr;

class IAbstractProgramConfiguration {
 public:
  virtual void AddGlobalVariable(VariableId, Type type) = 0;
  virtual void AddVariable(VariableId id, Type type) = 0;
  virtual void RemoveVariable(VariableId id) = 0;
  virtual void AssignVariable(VariableId target, VariableId source) = 0;

  // virtual void PushFrame(FunctionInfo info, IInstruction return_target) = 0;
  // virtual void PopFrame(VariableId return_variable) = 0;

  virtual ValuePtr Alloc(int size) = 0;
  virtual void Free(ValuePtr val_with_address) = 0;
};


