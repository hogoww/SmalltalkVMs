#include "oopMock.hpp"
#include "cTestCase.h"

#ifndef WORD_TYPE
#define WORD_TYPE uint64_t
#endif

int main(){
  OopMock<WORD_TYPE> oop;
  oop.setHeader(0xDFFFFFFFF);
  cAssert(__LINE__, ! oop.pinnedBit());
  testPassed();
}
