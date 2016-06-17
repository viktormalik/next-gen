/**
 * Interface for CFG (control-flow graph) node. It is in fact a location in the program.
 * Contains information about previous and next locations and a set of states obtained after
 * symbolic execution of the instruction associated with the node.
 *
 *  Viktor Malik, 16.6.2016 (c).
 */

#pragma once

#include <vector>

class ISymState;

class IInstruction {
 public:
  virtual IInstruction* Next() const = 0;
  virtual IInstruction* NextTrue() const = 0;
  virtual IInstruction* NextFalse() const = 0;
  virtual std::vector<IInstruction*> Prev() const = 0;

  virtual std::vector<ISymState*> States() const = 0;
};


