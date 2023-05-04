#include "memorySpace.hpp"
#include "cTestCase.h"
#include <vector>

#ifndef WORD_TYPE
#define WORD_TYPE uint64_t
#endif

int main(){
  MemorySpace<WORD_TYPE> ms(640);
  OopBuilder<WORD_TYPE>* oopBuilder = ms.getOopBuilder();
  oopBuilder -> setNumberOfSlots(1);
  oopBuilder -> build();
  ms.firstOop().getHeader().resetHeader();
  
  cAssertInts(__LINE__, ms.firstOop().getHeader().headerValue() , 0);
  testPassed();
}
