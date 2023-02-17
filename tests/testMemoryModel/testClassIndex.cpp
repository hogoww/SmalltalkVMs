#include "memorySpace.hpp"
#include "cTestCase.h"

#ifndef WORD_TYPE
#define WORD_TYPE uint64_t
#endif

int main(){
  Oop<WORD_TYPE> oop;
  oop.setHeader(0xFFFFFC0000000000);
  cAssertInts(__LINE__, oop.classIndexBits(), 0x3FFFFF);
  testPassed();
}
