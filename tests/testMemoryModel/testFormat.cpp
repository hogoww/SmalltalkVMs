#include "oopMock.hpp"
#include "cTestCase.h"

#ifndef WORD_TYPE
#define WORD_TYPE uint64_t
#endif

int main(){
  OopMock<WORD_TYPE> oop;
  oop.setHeader(0xF800000000);
  cAssertInts(__LINE__, oop.getHeader().formatBits(), 0x1F);
  testPassed();
}
