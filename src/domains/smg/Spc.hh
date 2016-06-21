/**
 * Symbolic program configuration for SMG abstract domain. Contains SMG graph and provides
 * methods to manipulate it.
 * Implements interface IAbstractProgramConfiguration.
 * @TODO Does not contain SMG yet and methods are not implemented.
 *  Viktor Malik, 21.6.2016 (c).
 */

#pragma once

#include <core/IAbstractProgramConfiguration.hh>

class Spc : public IAbstractProgramConfiguration {
 public:
  void AddGlobalVariable(VariableId id, const Type& type) override;
  void AddVariable(VariableId id, const Type& type) override;
  void RemoveVariable(VariableId id) override;
  void AssignVariable(VariableId target, VariableId source) override;
  ValuePtr Alloc(int size) override;
  void Free(ValuePtr val_with_address) override;
};


