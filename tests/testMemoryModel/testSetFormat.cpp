#include "oopMock.hpp"
#include "cTestCase.h"

#ifndef WORD_TYPE
#define WORD_TYPE uint64_t
#endif

int main(){
  OopMock<WORD_TYPE> oop;
  WORD_TYPE format = 4;
  oop.setHeader(0);
  oop.getHeader().setFormatBits(format);
  cAssertInts(__LINE__, oop.getHeader().formatBits(), format);
  testPassed();
}
