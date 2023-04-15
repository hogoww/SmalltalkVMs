#include "oopMock.hpp"
#include "cTestCase.h"

#ifndef WORD_TYPE
#define WORD_TYPE uint64_t
#endif

int main(){
  OopMock<WORD_TYPE> oop;
  oop.setHeader(0xFFFFFC00);
  cAssertInts(__LINE__, oop.getHeader().hashBits(), 0x3FFFFF);
  testPassed();
}
