/**
 *  Viktor Malik, 23.6.2016 (c).
 */

#include <gtest/gtest.h>
#include <llvm/IR/Module.h>
#include <core/LlvmLoader.hh>

TEST(LlvmBuilder, Build) {
  LlvmLoader loader;
  auto module = loader.loadSource("/home/viktor/Documents/fit/VeriFIT/next-gen/next-gen/examples"
                                       "/tests/loader/lowermem.ll");

  // Main should contain 6 instructions:
  // alloca, alloca, store, bitcast, call, ret
  ASSERT_EQ(module->getFunction("main")->getEntryBlock().size(), 6);
}