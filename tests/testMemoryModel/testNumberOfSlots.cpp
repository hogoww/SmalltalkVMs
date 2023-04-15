#include "oopMock.hpp"
#include "cTestCase.h"

#ifndef WORD_TYPE
#define WORD_TYPE uint64_t
#endif

int main(){
  OopMock<WORD_TYPE> oop;
  oop.setHeader(0xFF);
  cAssertInts(__LINE__, oop.getHeader().numberOfSlotsBits(), 0xFF);
  testPassed();
}
