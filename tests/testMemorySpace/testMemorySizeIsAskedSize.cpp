#include "memorySpace.hpp"
#include "cTestCase.h"

#ifndef WORD_TYPE
#define WORD_TYPE uint64_t
#endif

int main(){
  WORD_TYPE memorySize = 640;
  MemorySpace<WORD_TYPE>* ms = new MemorySpace<WORD_TYPE>(memorySize);
  int size = ms -> wordSpaceSize();
  std::cout<< "Actual: " << std::dec << size << std::endl;
  cAssert(__LINE__, size == 10);
  testPassed();
}
