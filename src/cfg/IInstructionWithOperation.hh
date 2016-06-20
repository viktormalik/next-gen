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
  /**
   * Destructor.
   */
  virtual ~IInstructionWithOperation() { }
};
