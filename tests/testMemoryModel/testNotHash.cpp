#include "memorySpace.hpp"
#include "cTestCase.h"

#ifndef WORD_TYPE
#define WORD_TYPE uint64_t
#endif

int main(){
  Oop<WORD_TYPE> oop;
  oop.setHeader(0xFFFFFFFF000003FF);
  cAssert(__LINE__, ! oop.hashBits());
  testPassed();
}
