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
  Allocator(Allocator const& anotherAllocator) = delete;
  void operator=(Allocator const& anotherMemorySpace) = delete;
    
  //API
  WORD_TYPE* whereToAllocateWords(WORD_TYPE numberOfWords);
};

template <typename WORD_TYPE>
Allocator<WORD_TYPE>::Allocator(OopBuilder<WORD_TYPE>* anOopBuilder){
  this -> oopBuilder = anOopBuilder;
}

template <typename WORD_TYPE>
WORD_TYPE* Allocator<WORD_TYPE>::whereToAllocateWords(WORD_TYPE numberOfWords){
  MemorySpace<WORD_TYPE>* memorySpace = oopBuilder -> getMemorySpace();
  Oop<WORD_TYPE> firstOop =  memorySpace -> firstOop();
  Oop<WORD_TYPE> resultOop = firstOop;
  
  while(resultOop.getAddress() < memorySpace -> getEndAddress()){
    if(resultOop.isFreeOop() && resultOop.wordSize() >= numberOfWords ){ break; }
    resultOop = resultOop.nextOop();
  }
  
  if(resultOop.getAddress() >= memorySpace -> getEndAddress()){
    std::abort(); }//Maybe an error?
  
  return resultOop.getAddress();
}

#endif
