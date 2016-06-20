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
  /**
   * Next node in CFG. Used in case when node has only one successor.
   * @return Pointer to the next node.
   */
  virtual IInstruction* Next() const = 0;
  /**
   * Next node of True branch in conditional statement. Used in case the node has two successors
   * (node is an conditional statement).
   * @return Pointer to the first node of True branch.
   */
  virtual IInstruction* NextTrue() const = 0;
  /**
   * Next node of False branch in conditional statement. Used in case the node has two successors
   * (node is an conditional statement).
   * @return Pointer to the first node of False branch.
   */
  virtual IInstruction* NextFalse() const = 0;
  /**
   * Previous nodes in CFG (there can be potentially more previous states).
   * @return Vector of previous nodes.
   */
  virtual std::vector<IInstruction*> Prev() const = 0;

  /**
   * Set next node in CFG. Used in case when node has only one successor.
   * @param next Pointer to the next node.
   */
  virtual void SetNext(IInstruction* next) = 0;
  /**
   * Set next node of True branch in conditional statement. Used in case the node has two successors
   * (node is an conditional statement).
   * @param next_true Pointer to the first node of True branch.
   */
  virtual void SetNextTrue(IInstruction* next_true) = 0;
  /**
   * Set next node of False branch in conditional statement. Used in case the node has two
   * successors (node is an conditional statement).
   * @param next_false Pointer to the first node of False branch.
   */
  virtual void SetNextFalse(IInstruction* next_false) = 0;
  /**
   * Add node to set of previous nodes in CFG (there can be potentially more previous states).
   * @param prev Pointer to the node to be added to previous nodes.
   */
  virtual void AddPrev(IInstruction* prev) = 0;

  /**
   * Set of symbolic states of program in this CFG node.
   * @TODO implement as StatesContainer
   * @return Vector of symbolic states in node.
   */
  virtual std::vector<ISymState*> States() const = 0;

  /**
   * Destructor.
   */
  virtual ~IInstruction() { }
};


