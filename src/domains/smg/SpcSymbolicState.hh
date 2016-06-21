/**
 * Symbolic state of the program. Contains context - Symbolic Program Configiuration.
 * Implements interface ISymState.
 *  Viktor Malik, 21.6.2016 (c).
 */

#pragma once

#include <core/ISymState.hh>
#include <domains/smg/Spc.hh>

class SpcSymbolicState : public ISymState {
 private:
  IInstructionWithOperation* location_;  /**< Location of the state - CFG node */
  Spc context_;                          /**< SPC associated with the state */
 public:
  // Methods from interface ISymState
  IInstructionWithOperation* Location() override;
  IAbstractProgramConfiguration& Context() override;
};


