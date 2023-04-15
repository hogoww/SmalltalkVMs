#include "memorySpace.hpp"
#include "cTestCase.h"

#ifndef WORD_TYPE
#define WORD_TYPE uint64_t
#endif


//This test case is subject to change.
//Should the class handle such error? don't know
int main(){
  WORD_TYPE memorySize = -64;
  MemorySpace<WORD_TYPE>* ms;
  try{
    new MemorySpace<WORD_TYPE>(memorySize);
    cAssert(__LINE__, false);
  }
  catch(const std::bad_alloc& e)
    {
      testPassed();
    }
  cAssert(__LINE__, ms->isUninitialized());
  testPassed();
}
