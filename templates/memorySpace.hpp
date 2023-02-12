#ifndef __MEMORY_SPACE__
#define __MEMORY_SPACE__

#include <cstdlib>
#include <iostream>

#include <stdint.h>
//#include "oop.h"

template <typename WORD_TYPE>
class MemorySpace {
 private:
  WORD_TYPE* startAddress;
  WORD_TYPE* endAddress;
 public:
  MemorySpace (WORD_TYPE spaceSize);
  ~MemorySpace();
  WORD_TYPE* getStartAddress();
  WORD_TYPE* getEndAddress();
  void uninitialize();
  bool isUninitialized();
  
  
  WORD_TYPE bitSpaceSize();
  WORD_TYPE byteSpaceSize();
  WORD_TYPE wordSpaceSize();
  //oop firstOop();
};


template <typename WORD_TYPE>
MemorySpace<WORD_TYPE>::MemorySpace(WORD_TYPE spaceSize){

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
  std::cout << "start: " << std::hex << startAddress << " + " << std::hex <<spaceSize << " end: "<< endAddress << " size:" << (startAddress + spaceSize)<< std::endl;
}

template <typename WORD_TYPE>
MemorySpace<WORD_TYPE>::~MemorySpace(){
  if( this -> isUninitialized()){ return; }

  delete[] startAddress;
}

template <typename WORD_TYPE>
void MemorySpace<WORD_TYPE>::uninitialize(){
   startAddress = NULL;
   endAddress = NULL;
}

template <typename WORD_TYPE>
bool MemorySpace<WORD_TYPE>::isUninitialized(){
  return startAddress == NULL;
}

// oop MemorySpace::firstOop(){
//   return static_cast<oop>(startAddress);
// }

template <typename WORD_TYPE>
WORD_TYPE* MemorySpace<WORD_TYPE>::getStartAddress(){
  return this->startAddress;
}

template <typename WORD_TYPE>
WORD_TYPE* MemorySpace<WORD_TYPE>::getEndAddress(){
  return this->endAddress;
}

template <typename WORD_TYPE>
WORD_TYPE MemorySpace<WORD_TYPE>::bitSpaceSize(){
  return this->endAddress - this->startAddress;
}

template <typename WORD_TYPE>
WORD_TYPE MemorySpace<WORD_TYPE>::byteSpaceSize(){
  return this->bitSpaceSize() / 8;
}

template <typename WORD_TYPE>
WORD_TYPE MemorySpace<WORD_TYPE>::wordSpaceSize(){
  return this->byteSpaceSize() / sizeof(WORD_TYPE);
}

#endif
