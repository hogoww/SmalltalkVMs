#include "oop.hpp"
#include "cTestCase.h"

#ifndef WORD_TYPE
#define WORD_TYPE uint64_t
#endif

int main(){
  Oop<WORD_TYPE> oop(new WORD_TYPE[1]);
  oop.setHeader(0xFFFFFF07FFFFFFFF);
  cAssert(__LINE__, ! oop.getHeader().formatBits());
  testPassed();
}
