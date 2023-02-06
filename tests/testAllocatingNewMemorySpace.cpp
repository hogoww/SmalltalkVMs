#include "memorySpace.h"
#include "cTestCase.h"

int main(){
  MemorySpace* ms = new MemorySpace(10);
  cAssert(__LINE__, ms->getStartAddress() != NULL);
  testPassed();
}
