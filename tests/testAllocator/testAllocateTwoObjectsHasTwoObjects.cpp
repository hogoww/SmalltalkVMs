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
  
  oopBuilder -> reset();
  oopBuilder -> setNumberOfSlots(2);
  oopBuilder -> build();
    
  cAssert(__LINE__, ms.firstOop().nextOop().nextOop().isFreeOop());
  testPassed();
}
