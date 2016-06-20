/**
 * Interface for symbolic state used in symbolic execution of the program.
 *
 *  Viktor Malik, 17.6.2016 (c).
 */

#pragma once

#include <cfg/IInstructionWithOperation.hh>
#include <core/IAbstractProgramConfiguration.hh>

class ISymState {
 public:
  /**
   * Location of the state (CFG node).
   * @return Pointer to the CFG node which holds this state.
   */
  virtual IInstructionWithOperation* Location() const = 0;
  /**
   * Symbolic program configuration associated with the state (SPC).
   * @return Pointer to the program configuration.
   */
  virtual IAbstractProgramConfiguration& Context() const = 0;

  /**
   * Destructor.
   */
  virtual ~ISymState() { }
};


