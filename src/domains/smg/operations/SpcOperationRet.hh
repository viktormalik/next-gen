/**
 * Implementation of LLVM operation "ret" over SPC.
 * @TODO Not implemented, only returns the input state as the result.
 *  Viktor Malik, 21.6.2016 (c).
 */

#pragma once

#include <domains/smg/operations/BaseSpcOperation.hh>
#include <vector>

class SpcOperationRet: public BaseSpcOperation {
 public:
  std::vector<std::unique_ptr<SpcSymbolicState>> Do(SpcSymbolicState* state,
                                                    std::vector<VariableId> args) override;
};


