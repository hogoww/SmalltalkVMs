#include "oopMock.hpp"
#include "cTestCase.h"

#ifndef WORD_TYPE
#define WORD_TYPE uint64_t
#endif

int main(){
  OopMock<WORD_TYPE> oop;
  oop.setHeader(0);
  oop.setRememberedBit();
  cAssert(__LINE__, oop.rememberedBit());
  testPassed();
}
