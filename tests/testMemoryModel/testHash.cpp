#include "memorySpace.hpp"
#include "cTestCase.h"

#ifndef WORD_TYPE
#define WORD_TYPE uint64_t
#endif

int main(){
  Oop<WORD_TYPE> oop;
  oop.setHeader(0x3FFFFF00);
  cAssertInts(__LINE__, oop.hashBits(), 0xFFFFF3);
  testPassed();
}
