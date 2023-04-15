#include "oopMock.hpp"
#include "cTestCase.h"

#ifndef WORD_TYPE
#define WORD_TYPE uint64_t
#endif

int main(){
  OopMock<WORD_TYPE> oop;
  oop.setHeader(0xF1FF);
  cAssert(__LINE__, oop.getHeader().markedBit());
  testPassed();
}
