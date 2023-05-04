#include "memorySpace.hpp"
#include "cTestCase.h"
#include <vector>

#ifndef WORD_TYPE
#define WORD_TYPE uint64_t
#endif

int main(){
  MemorySpace<WORD_TYPE> ms(640);
  OopBuilder<WORD_TYPE>* oopBuilder = ms.getOopBuilder();
  std::vector<WORD_TYPE*> roots(0);
  oopBuilder -> setNumberOfSlots(1);
  roots.push_back(oopBuilder -> build());
  
  oopBuilder -> reset();
  ms.firstOop().slotAtPut(1, oopBuilder -> build());
  
  ms.getGarbageCollector() -> collectFromRoots(roots);
  
  cAssert(__LINE__, not ms.firstOop().getHeader().markedBit());
  testPassed();
}

