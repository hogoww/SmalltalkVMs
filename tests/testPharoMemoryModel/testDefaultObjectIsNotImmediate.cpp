#include "memorySpace.hpp"
#include "immediateOop.hpp"
#include "cTestCase.h"

#ifndef WORD_TYPE
#define WORD_TYPE uint64_t
#endif

int main(){
  MemorySpace<WORD_TYPE> ms(640);
  OopBuilder<WORD_TYPE>* oopBuilder = ms.getOopBuilder();
  oopBuilder -> build();
    
  cAssert(__LINE__, not ImmediateOop<WORD_TYPE>::isImmediateOop(ms.firstOop().getAddress()));
  testPassed();
}
