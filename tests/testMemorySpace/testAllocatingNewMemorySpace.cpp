#include "memorySpace.hpp"
#include "cTestCase.h"

#ifndef WORD_TYPE
#define WORD_TYPE uint64_t
#endif


int main(){
  MemorySpace<uint64_t>* ms = new MemorySpace<uint64_t>(640);
  cAssert(__LINE__, ms->getStartAddress() != NULL);
  testPassed();
}
