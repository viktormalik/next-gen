/**
 *  Viktor Malik, 21.6.2016 (c).
 */

#include "BaseSpcOperation.hh"

/**
 * Method Do from IOperation is implemented by calling overloaded virtual method and
 * correctly casting arguments and return value.
 */
std::vector<std::unique_ptr<ISymState>> BaseSpcOperation::Do(ISymState* state,
                                                             std::vector<VariableId> args) {
  auto states = Do(dynamic_cast<SpcSymbolicState*>(state), args);
  std::vector<std::unique_ptr<ISymState>> result;
  for (auto& item : states) {
    auto t = std::unique_ptr<ISymState>(static_cast<ISymState*>(item.release()));
    result.push_back(std::move(t));
  }
  return result;
}



