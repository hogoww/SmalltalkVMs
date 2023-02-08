#include "memorySpace.h"


MemorySpace::MemorySpace(WORD_TYPE spaceSize){
  std::cout<<spaceSize <<std::endl;
  if((spaceSize % sizeof(WORD_TYPE)) != 0){ };
  WORD_TYPE* startAddress = new WORD_TYPE[spaceSize % sizeof(WORD_TYPE)];
  if(startAddress == NULL) { }
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

WORD_TYPE MemorySpace::memorySpaceSize(){
  return this->endAddress - this->startAddress;
}
