/**
 *  Viktor Malik, 21.6.2016 (c).
 */

#include "SpcOperationAdd.hh"

std::vector<std::unique_ptr<SpcSymbolicState>> SpcOperationAdd::Do(SpcSymbolicState* state,
                                                                   std::vector<VariableId> args) {
  std::vector<std::unique_ptr<SpcSymbolicState>> result;
  result.emplace_back(std::unique_ptr<SpcSymbolicState>(state));
  return result;
}

