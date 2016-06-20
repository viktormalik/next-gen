/**
 * Interface for an operation simulating an instruction from source program.
 * Contains one method, which does the symbolic execution of the operation.
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
  /**
   * Symbolic execution of the operation.
   * Takes one symbolic state and set of arguments (variables in the state) and performs symbolic
   * execution of the operation over them.
   * Number of arguments is given by the type of operation.
   * @param state Symbolic state to execute operation on
   * @param args Arguments of the operation (represented by variables in the program configuration
   * @return Set of states obtained as the result of symbolic execution of the operation.
   */
  virtual std::vector<std::unique_ptr<ISymState>>
      Do(ISymState* state, std::vector<VariableId> args) = 0;
};


