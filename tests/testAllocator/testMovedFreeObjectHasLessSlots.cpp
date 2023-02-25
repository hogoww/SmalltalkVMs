#include "memorySpace.hpp"
#include "cTestCase.h"

#ifndef WORD_TYPE
#define WORD_TYPE uint64_t
#endif

int main(){
  MemorySpace<WORD_TYPE> ms(640);
  OopBuilder<WORD_TYPE>* oopBuilder = ms.getOopBuilder();
  oopBuilder -> setNumberOfSlots(1);
  oopBuilder -> build();
    
  cAssertInts(__LINE__, ms.firstOop().nextOop().numberOfSlotsBits(), ms.wordSpaceSize() - 2 - 1);// 2 == oop header + slot, 1 == freeOopheader
  testPassed();
}
