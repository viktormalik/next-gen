/**
 * Interface for a CFG node with associated operation.
 * Simply joins interfaces IInstruction and IOperation.
 *
 *  Viktor Malik, 16.6.2016 (c).
 */

#pragma once

#include <cfg/IInstruction.hh>
#include <cfg/IOperation.hh>
#include <vector>

class IInstructionWithOperation: public IInstruction, IOperation {
 public:
  // Methods from interface IInstruction.
  virtual IInstruction* Next() const = 0;
  virtual IInstruction* NextTrue() const = 0;
  virtual IInstruction* NextFalse() const = 0;
  virtual std::vector<IInstruction*> Prev() const = 0;
  virtual std::vector<ISymState*> States() const = 0;
  // Methods from interface IOperation.
  virtual std::vector<std::unique_ptr<ISymState>>
      Do(ISymState* state, std::vector<VariableId> args) = 0;
};
