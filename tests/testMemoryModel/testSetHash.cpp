#include "oopMock.hpp"
#include "cTestCase.h"

#ifndef WORD_TYPE
#define WORD_TYPE uint64_t
#endif

int main(){
  OopMock<WORD_TYPE> oop;
  WORD_TYPE hash = 549;
  oop.setHeader(0);
  oop.setHashBits(hash);
  cAssertInts(__LINE__, oop.hashBits(), hash);
  testPassed();
}
