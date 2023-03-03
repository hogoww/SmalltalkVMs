#include "memorySpace.hpp"
#include "cTestCase.h"

#ifndef WORD_TYPE
#define WORD_TYPE uint64_t
#endif

int main(){
  MemorySpace<WORD_TYPE> ms(640);
  OopBuilder<WORD_TYPE>* oopBuilder = ms.getOopBuilder();
  oopBuilder -> build();
  oopBuilder -> build();
  ms.firstOop().becomeFreeOop();
  WORD_TYPE* newObject = oopBuilder -> build();

  cAssert(__LINE__, newObject == ms.getStartAddress());
  testPassed();
}
