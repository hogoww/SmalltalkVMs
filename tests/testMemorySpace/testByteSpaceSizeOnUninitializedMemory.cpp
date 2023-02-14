#include "memorySpace.hpp"
#include "cTestCase.h"

#ifndef WORD_TYPE
#define WORD_TYPE uint64_t
#endif

int main(){
  WORD_TYPE memorySize = 640;
  MemorySpace<WORD_TYPE> ms;
  
  cAssert(__LINE__, ms.byteSpaceSize() == 0);
  testPassed();
}
