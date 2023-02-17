#include "memorySpace.hpp"
#include "cTestCase.h"

#ifndef WORD_TYPE
#define WORD_TYPE uint64_t
#endif

int main(){
  Oop<WORD_TYPE> oop;
  oop.setHeader(0xFFFFFF07FFFFFFFF);
  cAssert(__LINE__, ! oop.formatBits());
  testPassed();
}
