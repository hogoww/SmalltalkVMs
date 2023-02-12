#include <iostream>
#include "memorySpace.hpp"

#ifndef WORD_TYPE
#define WORD_TYPE uint64_t
#endif

int main(){
  uint64_t b = 640;
  MemorySpace<uint64_t>* a = new MemorySpace<uint64_t>(b);
  std::cout<< a->getStartAddress() << std::endl;
  return 1;
}
