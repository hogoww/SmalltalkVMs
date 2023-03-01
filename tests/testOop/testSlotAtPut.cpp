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
  oopBuilder -> build();
  
  Oop<WORD_TYPE> container = ms.firstOop();
  container.slotAtPut( 1 , container.nextOop().getAddress());
  
  cAssert(__LINE__, container.slotAt(1).getAddress() == ms.firstOop().nextOop().getAddress());
  testPassed();
}
