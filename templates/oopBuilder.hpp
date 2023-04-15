#ifndef __OOP__BUILDER__HPP__
#define __OOP__BUILDER__HPP__

#include <cstdlib> // for NULL

#include "specialClassIndexes.h"

template <typename WORD_TYPE>
class OopBuilder;

#include "oop.hpp"
#include "allocator.hpp"
#include "memorySpace.hpp"

template <typename WORD_TYPE>
class OopBuilder {
 protected:
  MemorySpace<WORD_TYPE>* memorySpace;
  Allocator<WORD_TYPE>* allocator;

  WORD_TYPE numberOfSlots;
  WORD_TYPE format;
  WORD_TYPE classIndex;
  
public:
  //constructors
  OopBuilder(MemorySpace<WORD_TYPE>* aMemorySpace);
  OopBuilder(OopBuilder const& anotherMemorySpace) = delete;
  void operator=(OopBuilder const& anotherMemorySpace) = delete;
  
  void initialize();
  void reset();
  
  void setNumberOfSlots(WORD_TYPE numberOfSlots);
  void setFormat(WORD_TYPE format);
  void setClassIndex(WORD_TYPE classIndex);

  //accessors
  MemorySpace<WORD_TYPE>* getMemorySpace();
  //void setMemorySpace(const MemorySpace<WORD_TYPE>* aMemorySpace);
  //void setAllocator(const Allocator<WORD_TYPE>* allocator);

  //API
  WORD_TYPE* build();
};
 

template <typename WORD_TYPE>
OopBuilder<WORD_TYPE>::OopBuilder(MemorySpace<WORD_TYPE>* aMemorySpace){
  this -> memorySpace = aMemorySpace;
  //const_cast<OopBuilder<WORD_TYPE>*>(
  this -> allocator = new Allocator<WORD_TYPE>(this);
  this -> initialize();
}

template <typename WORD_TYPE>
WORD_TYPE* OopBuilder<WORD_TYPE>::build(){
  WORD_TYPE numberOfWords = this -> numberOfSlots + 1; // + header
  WORD_TYPE* address = allocator -> whereToAllocateWords(numberOfWords);
  Oop<WORD_TYPE> newOop(address);
  Oop<WORD_TYPE> newFreeOop(address + numberOfWords * sizeof(WORD_TYPE) * 8 );
  newFreeOop.getHeader().setHeader(newOop.getHeader().headerValue());
  newFreeOop.getHeader().setNumberOfSlotsBits(newFreeOop.getHeader().numberOfSlotsBits() - numberOfWords);

  newOop.setHeader(0x0000000000000000);
  newOop.getHeader().setNumberOfSlotsBits(this -> numberOfSlots);
  newOop.getHeader().setFormatBits(this -> format);
  newOop.getHeader().setClassIndexBits(this -> classIndex);
  return address;
}


// API, for code readability
template <typename WORD_TYPE>
void OopBuilder<WORD_TYPE>::reset(){
  this -> initialize();
}

template <typename WORD_TYPE>
void OopBuilder<WORD_TYPE>::initialize(){
  this -> numberOfSlots = 0;
  this -> format = 0;
  this -> classIndex = 1; //should probably be different than existing classes (i.e., freeObject)
}

template <typename WORD_TYPE>
void OopBuilder<WORD_TYPE>::setNumberOfSlots(WORD_TYPE numberOfSlots){
  this -> numberOfSlots = numberOfSlots;
}

template <typename WORD_TYPE>
void OopBuilder<WORD_TYPE>::setFormat(WORD_TYPE format){
  this -> format = format;
}

template <typename WORD_TYPE>
void OopBuilder<WORD_TYPE>::setClassIndex(WORD_TYPE classIndex){
  this -> classIndex = classIndex;
}

template <typename WORD_TYPE>
MemorySpace<WORD_TYPE>* OopBuilder<WORD_TYPE>::getMemorySpace(){
  return this -> memorySpace;
}

// template <typename WORD_TYPE>
// void OopBuilder<WORD_TYPE>::setMemorySpace(const MemorySpace<WORD_TYPE>* aMemorySpace){
//   this -> memorySpace = aMemorySpace;
// }

// template <typename WORD_TYPE>
// void OopBuilder<WORD_TYPE>::setAllocator(const Allocator<WORD_TYPE>* allocator){
//   this -> allocator = allocator;
// }

#endif
