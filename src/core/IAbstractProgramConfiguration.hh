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
  /**
   * Create new global variable.
   * @param id Variable ID
   * @param type Variable type
   */
  virtual void AddGlobalVariable(VariableId id, Type type) = 0;
  /**
   * Create new local variable.
   * @param id Varible ID.
   * @param type Variable type.
   */
  virtual void AddVariable(VariableId id, Type type) = 0;
  /**
   * Remove variable.
   * @param Variable ID.
   */
  virtual void RemoveVariable(VariableId id) = 0;
  /**
   * Assign content of one variable to another.
   * @param target ID of variable to assign to
   * @param source ID of variable to assign from
   */
  virtual void AssignVariable(VariableId target, VariableId source) = 0;

  // virtual void PushFrame(FunctionInfo info, IInstruction return_target) = 0;
  // virtual void PopFrame(VariableId return_variable) = 0;

  /**
   * Allocate space on the heap.
   * @param size Size of the allocated space
   * @return Pointer to the beginning of allocated space
   */
  virtual ValuePtr Alloc(int size) = 0;
  /**
   * Free space on the heap.
   * @param Pointer to the space to be freed.
   */
  virtual void Free(ValuePtr val_with_address) = 0;
};


