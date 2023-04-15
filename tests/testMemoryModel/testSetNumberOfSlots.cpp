#include "oop.hpp"
#include "cTestCase.h"

#ifndef WORD_TYPE
#define WORD_TYPE uint64_t
#endif

int main(){
  Oop<WORD_TYPE> oop(new WORD_TYPE[1]);
  WORD_TYPE numberOfSlots = 5;
  oop.setHeader(0);
  oop.getHeader().setNumberOfSlotsBits(numberOfSlots);
  cAssertInts(__LINE__, oop.getHeader().numberOfSlotsBits(), numberOfSlots);
  testPassed();
}
