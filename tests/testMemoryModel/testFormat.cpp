#include "memorySpace.hpp"
#include "cTestCase.h"

#ifndef WORD_TYPE
#define WORD_TYPE uint64_t
#endif

int main(){
  Oop<WORD_TYPE> oop;
  oop.setHeader(0x000000008F);
  cAssertInts(__LINE__, oop.formatBits(), 0xF1);
  testPassed();
}
