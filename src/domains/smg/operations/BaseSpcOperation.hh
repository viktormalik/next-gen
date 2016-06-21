/**
 * Base class for all operations over SMG abstract domain.
 * Overloads method Do to work on symbolic states from SMG domain.
 * Implements interface IOperation.
 *  Viktor Malik, 21.6.2016 (c).
 */

#pragma once

#include <cfg/IOperation.hh>
#include <domains/smg/SpcSymbolicState.hh>
#include <vector>

class BaseSpcOperation: public IOperation {
 public:
  // Method from IOperation
  std::vector<std::unique_ptr<ISymState>> Do(ISymState* state,
                                              std::vector<VariableId> args) override;

  /**
   * Overloaded method Do from IOperation working on symbolic states from SMG domain.
   * @param state Symbolic state from SMG domain to execute operation on.
   * @param args Arguments of the operation.
   * @return Set of symbolic states from SMG domain obtained as the result of symbolic execution of
   * the operation.
   */
  virtual std::vector<std::unique_ptr<SpcSymbolicState>> Do(SpcSymbolicState* state,
                                                             std::vector<VariableId> args) = 0;
};


