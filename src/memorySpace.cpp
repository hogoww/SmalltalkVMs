#include "memorySpace.h"
#include <cstdlib>

MemorySpace::MemorySpace(WORD_TYPE spaceSize){
  WORD_TYPE* startAddress = new WORD_TYPE[spaceSize];
  if(startAddress == NULL) { std::abort(); }
  endAddress = startAddress + spaceSize;
}

MemorySpace::~MemorySpace(){
  delete[] startAddress;
}

// oop MemorySpace::firstOop(){
//   return static_cast<oop>(startAddress);
// }


WORD_TYPE* MemorySpace::getStartAddress(){
  return this->startAddress;
}

WORD_TYPE* MemorySpace::getEndAddress(){
  return this->endAddress;
}
