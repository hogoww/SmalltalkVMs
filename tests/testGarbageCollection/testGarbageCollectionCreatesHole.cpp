#include "memorySpace.hpp"
#include "cTestCase.h"
#include <vector>

#ifndef WORD_TYPE
#define WORD_TYPE uint64_t
#endif

int main(){
  MemorySpace<WORD_TYPE> ms(640);
  OopBuilder<WORD_TYPE>* oopBuilder = ms.getOopBuilder();
  std::vector<WORD_TYPE*> roots;
  oopBuilder -> build();
  roots.push_back(oopBuilder -> build());
  
  ms.getGarbageCollector() -> collectFromRoots(roots);
  
  cAssert(__LINE__, ms.firstOop().isFreeOop());
  testPassed();
}
