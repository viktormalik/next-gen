/**
 * Interface for symbolic state used in symbolic execution of the program.
 * Contains location (CFG node) and context (symbolic program configuration).
 *
 *  Viktor Malik, 17.6.2016 (c).
 */

#pragma once

#include <cfg/IInstructionWithOperation.hh>
#include <core/IAbstractProgramConfiguration.hh>

class ISymState {
 public:
  virtual IInstructionWithOperation* Location() const = 0;
  virtual IAbstractProgramConfiguration& Context() const = 0;
};


