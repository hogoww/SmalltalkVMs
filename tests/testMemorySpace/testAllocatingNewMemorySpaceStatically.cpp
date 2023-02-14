#include "memorySpace.hpp"
#include "cTestCase.h"

#ifndef WORD_TYPE
#define WORD_TYPE uint64_t
#endif

int main(){
  WORD_TYPE memorySize = 640;
  MemorySpace<WORD_TYPE> ms;
  ms. initializeForBitSize(640);

  cAssert(__LINE__, ! ms.isUninitialized());
  testPassed();
}
