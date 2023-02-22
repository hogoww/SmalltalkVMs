#ifndef __ALLOCATOR__HPP__
#define __ALLOCATOR__HPP__

#include <cstdlib>
#include <iostream>
#include <stdint.h>

template <typename WORD_TYPE>
class Allocator;

#include "oop.hpp"
#include "oopBuilder.hpp"

template <typename WORD_TYPE>
class Allocator {
 private:
  OopBuilder<WORD_TYPE>* oopBuilder;
 public:
  //constructors
  Allocator(OopBuilder<WORD_TYPE>* anOopBuilder);
  Allocator(Allocator const& anotherMemorySpace) = delete;
  void operator=(Allocator const& anotherMemorySpace) = delete;
  
  //accessors
  void setOopBuilder(const OopBuilder<WORD_TYPE>* anOopBuilder);
  
  //API
  WORD_TYPE* whereToAllocateWords(WORD_TYPE numberOfWords);
};

template <typename WORD_TYPE>
Allocator<WORD_TYPE>::Allocator(OopBuilder<WORD_TYPE>* anOopBuilder){
  this -> oopBuilder = anOopBuilder;
}

template <typename WORD_TYPE>
void Allocator<WORD_TYPE>::setOopBuilder(const OopBuilder<WORD_TYPE>* anOopBuilder){
  this -> oopBuilder = anOopBuilder;
}

template <typename WORD_TYPE>
WORD_TYPE* Allocator<WORD_TYPE>::whereToAllocateWords(WORD_TYPE numberOfWords){
  return oopBuilder -> getMemorySpace() -> getStartAddress();
}

#endif
