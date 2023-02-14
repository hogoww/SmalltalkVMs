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
  //constructors
  MemorySpace ();
  MemorySpace (WORD_TYPE spaceSize);
  ~MemorySpace();

  //accessors
  WORD_TYPE* getStartAddress();
  WORD_TYPE* getEndAddress();

  //initialization
  void initializeForBitSize(WORD_TYPE spaceSize);
  void uninitialize();
  bool isUninitialized();
  

  //size computation
  WORD_TYPE bitSpaceSize();
  WORD_TYPE byteSpaceSize();
  WORD_TYPE wordSpaceSize();
  //oop firstOop();
};


void halt(){}

//Constructors
template <typename WORD_TYPE>
MemorySpace<WORD_TYPE>::MemorySpace(WORD_TYPE spaceSize){
  initializeForBitSize(spaceSize);
}

template <typename WORD_TYPE>
MemorySpace<WORD_TYPE>::MemorySpace(){
  this -> uninitialize();
}


template <typename WORD_TYPE>
MemorySpace<WORD_TYPE>::~MemorySpace(){
  if( this -> isUninitialized()){ return; }

  delete[] startAddress;
}


// Initialization
template <typename WORD_TYPE>
void MemorySpace<WORD_TYPE>::uninitialize(){
   startAddress = NULL;
   endAddress = NULL;
}

template <typename WORD_TYPE>
bool MemorySpace<WORD_TYPE>::isUninitialized(){
  return startAddress == NULL;
}

template <typename WORD_TYPE>
void MemorySpace<WORD_TYPE>::initializeForBitSize(WORD_TYPE spaceSize){
  
  if((spaceSize % sizeof(WORD_TYPE)) != 0) {
    this -> uninitialize();
    return;
  }

  WORD_TYPE numberOfWords = spaceSize / (sizeof(WORD_TYPE) * 8);

  
  this -> startAddress = new WORD_TYPE[numberOfWords];
  this -> endAddress = this -> startAddress + spaceSize;
}

// oop MemorySpace::firstOop(){
//   return static_cast<oop>(startAddress);
// }

//Accessors
template <typename WORD_TYPE>
WORD_TYPE* MemorySpace<WORD_TYPE>::getStartAddress(){
  return this->startAddress;
}

template <typename WORD_TYPE>
WORD_TYPE* MemorySpace<WORD_TYPE>::getEndAddress(){
  return this->endAddress;
}

//Accessing space
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
