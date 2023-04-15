#include "oopMock.hpp"
#include "cTestCase.h"

#ifndef WORD_TYPE
#define WORD_TYPE uint64_t
#endif

int main(){
  OopMock<WORD_TYPE> oop;
  oop.setHeader(0x10000000000);
  cAssert(__LINE__, oop.getHeader().rememberedBit());
  testPassed();
}
