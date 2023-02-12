#include "memorySpace.hpp"
#include "cTestCase.h"

#ifndef WORD_TYPE
#define WORD_TYPE uint64_t
#endif

int main(){
  WORD_TYPE memorySize = 640;
  MemorySpace<WORD_TYPE>* ms = new MemorySpace<WORD_TYPE>(memorySize);
  std::cout<< "Actual: " << ms -> getEndAddress() << " expected:" << (ms-> getStartAddress() + memorySize) << " resub: "<<std::dec << ms -> getEndAddress() - (ms-> getStartAddress() + memorySize) << " in class: " << std::dec << ms-> bitSpaceSize() << std::endl;
  cAssert(__LINE__, ms->getEndAddress() == (ms-> getStartAddress() + memorySize));
  testPassed();
}
