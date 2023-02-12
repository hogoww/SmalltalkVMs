#include "memorySpace.hpp"
#include "cTestCase.h"

#ifndef WORD_TYPE
#define WORD_TYPE uint64_t
#endif

int main(){
  WORD_TYPE memorySize = -1;
  MemorySpace<WORD_TYPE>* ms = new MemorySpace<WORD_TYPE>(memorySize);
  cAssert(__LINE__, ms->isUninitialized());
  testPassed();
}
