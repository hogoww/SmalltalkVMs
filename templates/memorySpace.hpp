#ifndef __MEMORY_SPACE__HPP__
#define __MEMORY_SPACE__HPP__

#include <cstdlib>
#include <iostream>
#include <stdint.h>



template <typename WORD_TYPE>
class MemorySpace;

#include "oop.hpp"
#include "allocator.hpp"

template <typename WORD_TYPE>
class MemorySpace {
 private:
  WORD_TYPE* startAddress;
  WORD_TYPE* endAddress;
  OopBuilder<WORD_TYPE>* oopBuilder;
 public:
  //constructors
  MemorySpace();
  MemorySpace(WORD_TYPE spaceSize);
  MemorySpace(MemorySpace const& anotherMemorySpace) = delete;
  void operator=(MemorySpace const& anotherMemorySpace) = delete;
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

  //oop accessors
  Oop<WORD_TYPE> firstOop();

  //accessors
  OopBuilder<WORD_TYPE>* getOopBuilder();
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

// template <typename WORD_TYPE>
// MemorySpace<WORD_TYPE>::MemorySpace(MemorySpace<WORD_TYPE>& anotherMemorySpace){
//   this -> startAddress = anotherMemorySpace -> startAddress;
//   this -> endAddress = anotherMemorySpace -> endAddress;
//   this -> allocator = anotherMemorySpace -> allocator;
// }

template <typename WORD_TYPE>
MemorySpace<WORD_TYPE>::~MemorySpace(){
  if( this -> isUninitialized()){ return; }
  
  std::cout<<"destroying the memory space" << std::endl;
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

  Oop<WORD_TYPE> firstOop = this -> firstOop();
  firstOop.setClassIndexBits(specialClassIndexes::freeObject);
  //should also set up the format to avoid accidental indexable formats
  firstOop.setNumberOfSlotsBits(this -> wordSpaceSize());

  //const_cast<MemorySpace<WORD_TYPE>*>;
  this -> oopBuilder = new OopBuilder<WORD_TYPE>(this);
}

template <typename WORD_TYPE>
Oop<WORD_TYPE> MemorySpace<WORD_TYPE>::firstOop(){
  Oop<WORD_TYPE> m(this -> startAddress);
  return m;
}

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

template <typename WORD_TYPE>
OopBuilder<WORD_TYPE>* MemorySpace<WORD_TYPE>::getOopBuilder(){
  return this -> oopBuilder;
}


#endif
