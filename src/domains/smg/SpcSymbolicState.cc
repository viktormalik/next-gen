/**
 *  Viktor Malik, 21.6.2016 (c).
 */

#include "SpcSymbolicState.hh"

IInstructionWithOperation* SpcSymbolicState::Location() {
  return location_;
}

IAbstractProgramConfiguration& SpcSymbolicState::Context() {
  return context_;
}



