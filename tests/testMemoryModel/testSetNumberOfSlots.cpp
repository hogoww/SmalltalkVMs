#include "oopMock.hpp"
#include "cTestCase.h"

#ifndef WORD_TYPE
#define WORD_TYPE uint64_t
#endif

int main(){
  OopMock<WORD_TYPE> oop;
  WORD_TYPE numberOfSlots = 5;
  oop.setHeader(0);
  oop.setNumberOfSlotsBits(numberOfSlots);
  cAssertInts(__LINE__, oop.numberOfSlotsBits(), numberOfSlots);
  testPassed();
}
