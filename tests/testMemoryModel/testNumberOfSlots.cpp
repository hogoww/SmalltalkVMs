#include "memorySpace.hpp"
#include "cTestCase.h"

#ifndef WORD_TYPE
#define WORD_TYPE uint64_t
#endif

int main(){
  Oop<WORD_TYPE> oop;
  oop.setHeader(0xFF);
  cAssertInts(__LINE__, oop.numberOfSlotsBits(), 0xFF);
  testPassed();
}
