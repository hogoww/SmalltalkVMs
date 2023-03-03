#include "memorySpace.hpp"
#include "cTestCase.h"
#include <vector>

#ifndef WORD_TYPE
#define WORD_TYPE uint64_t
#endif

int main(){
  MemorySpace<WORD_TYPE> ms(640);
  OopBuilder<WORD_TYPE>* oopBuilder = ms.getOopBuilder();
  std::vector<WORD_TYPE*> roots;
  oopBuilder -> build();
  
  ms.getGarbageCollector() -> collectFromRoots(roots);
  
  cAssertInts(__LINE__, ms.firstOop().bitSize(), ms.bitSpaceSize());
  testPassed();
}

