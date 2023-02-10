#include "memorySpace.h"
#include "cTestCase.h"

int main(){
  WORD_TYPE memorySize = 640;
  MemorySpace* ms = new MemorySpace(memorySize);
  std::cout<< "Actual: " << ms -> getEndAddress() << " expected:" << (ms-> getStartAddress() + memorySize) << " resub: "<<std::dec << ms -> getEndAddress() - (ms-> getStartAddress() + memorySize) << " in class: " << std::dec << ms-> bitSpaceSize() << std::endl;
  cAssert(__LINE__, ms->getEndAddress() == (ms-> getStartAddress() + memorySize));
  testPassed();
}
