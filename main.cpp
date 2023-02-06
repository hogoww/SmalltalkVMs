#include <iostream>
#include "memorySpace.h"

int main(){
  uint64_t b = 10;
  MemorySpace* a = new MemorySpace(b);
  std::cout<< "2";
  std::cout.flush();
  return 1;
}
