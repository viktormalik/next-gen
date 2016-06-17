/**
 * Interface for an operation simulating an instruction from source program.
 * Contains one method, which takes a symbolic state with arguments and produces a vector of
 * states obtained after symbolic execution of the operation.
 *
 * Each abstract domain must implement its own set of operations.
 *
 *  Viktor Malik, 16.6.2016 (c).
 */

#pragma once

#include <core/IAbstractProgramConfiguration.hh>
#include <memory>
#include <vector>

class ISymState;

class IOperation {
 public:
  virtual std::vector<std::unique_ptr<ISymState>>
      Do(ISymState* state, std::vector<VariableId> args) = 0;
};


