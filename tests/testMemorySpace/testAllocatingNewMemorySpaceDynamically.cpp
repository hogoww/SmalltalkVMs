#include "memorySpace.hpp"
#include "cTestCase.h"

#ifndef WORD_TYPE
#define WORD_TYPE uint64_t
#endif


int main(){
  MemorySpace<WORD_TYPE>* ms = new MemorySpace<WORD_TYPE>(640);
  cAssert(__LINE__, ms->getStartAddress() != NULL);
  testPassed();
}
