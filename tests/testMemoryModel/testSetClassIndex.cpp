#include "oopMock.hpp"
#include "cTestCase.h"

#ifndef WORD_TYPE
#define WORD_TYPE uint64_t
#endif

int main(){
  OopMock<WORD_TYPE> oop;
  WORD_TYPE classIndex = 4;
  oop.setHeader(0);
  oop.getHeader().setClassIndexBits(classIndex);
  cAssertInts(__LINE__, oop.getHeader().classIndexBits(), classIndex);
  testPassed();
}
