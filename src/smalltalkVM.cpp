#include <iostream>
#include "memorySpace.h"

int main(){
  uint64_t b = 640;
  MemorySpace* a = new MemorySpace(b);
  std::cout<< a->getStartAddress() << std::endl;
  return 1;
}
