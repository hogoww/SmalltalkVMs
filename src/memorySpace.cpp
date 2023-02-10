#include "memorySpace.h"

void halt(){ return;}

MemorySpace::MemorySpace(WORD_TYPE spaceSize){

  if((spaceSize % sizeof(WORD_TYPE)) != 0) {
    this -> uninitialize();
    return;
  }
  WORD_TYPE numberOfWords = spaceSize / (sizeof(WORD_TYPE) * 8);
  std::cout << spaceSize << " " << sizeof(WORD_TYPE)*8 << " " << numberOfWords << std::endl;
  
  
  WORD_TYPE* startAddress = new WORD_TYPE[numberOfWords];
  if(startAddress == NULL) {
    this -> uninitialize();
    return;
  }

  endAddress = startAddress + spaceSize;
  halt();
  std::cout << "start: " << std::hex << startAddress << " + " << std::hex <<spaceSize << " end: "<< endAddress << " size:" << (startAddress + spaceSize)<< std::endl;
}


MemorySpace::~MemorySpace(){
  if( this -> isUninitialized()){ return; }

  delete[] startAddress;
}

void MemorySpace::uninitialize(){
   startAddress = NULL;
   endAddress = NULL;
}

bool MemorySpace::isUninitialized(){
  return startAddress == NULL;
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

WORD_TYPE MemorySpace::bitSpaceSize(){
  return this->endAddress - this->startAddress;
}

WORD_TYPE MemorySpace::byteSpaceSize(){
  return this->bitSpaceSize() / 8;
}

WORD_TYPE MemorySpace::wordSpaceSize(){
  return this->byteSpaceSize() / sizeof(WORD_TYPE);
}
