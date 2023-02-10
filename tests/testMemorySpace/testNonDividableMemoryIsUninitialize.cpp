#include "memorySpace.h"
#include "cTestCase.h"

int main(){
  WORD_TYPE memorySize = 42;
  MemorySpace* ms = new MemorySpace(memorySize);
  cAssert(__LINE__, ms->isUninitialized());
  testPassed();
}
