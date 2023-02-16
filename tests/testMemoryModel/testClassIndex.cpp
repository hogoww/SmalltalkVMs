#include "memorySpace.hpp"
#include "cTestCase.h"

#ifndef WORD_TYPE
#define WORD_TYPE uint64_t
#endif

int main(){
  Oop<WORD_TYPE> oop;
  oop.setHeader(0x0000000000CFFFFF);
  cAssertInts(__LINE__, oop.classIndexBits(), 0xCFFFFF);
  testPassed();
}
