#ifndef __OOP__HPP__
#define __OOP__HPP__

#include "oopHeader.hpp"
#include "specialClassIndexes.h"
#include <cstdlib> // for NULL
#include <iostream>

template <typename WORD_TYPE>
class Oop {
 protected:
  WORD_TYPE* address;
  OopHeader<WORD_TYPE> header;
 public:
  //constructors
  Oop(WORD_TYPE* address);
  
  //Accessing
  OopHeader<WORD_TYPE> getHeader();
  WORD_TYPE headerValue();
  void setHeader(const WORD_TYPE anHeader);
  WORD_TYPE* getAddress();

  //Testing
  //  bool isInteger();
  //  bool isOOP();
  bool isFreeOop();
  void becomeFreeOop();

  //Accessing Slots
  Oop<WORD_TYPE> slotAt(WORD_TYPE anIndex);
  void slotAtPut(WORD_TYPE anIndex, WORD_TYPE* anOopAddress);
    
  //Navigating
  Oop<WORD_TYPE> nextOop();

  //Size
  WORD_TYPE bitSize();
  WORD_TYPE wordSize();
};


template <typename WORD_TYPE>
Oop<WORD_TYPE>::Oop(WORD_TYPE* anAddress):address(anAddress), header(anAddress)
{}

template <typename WORD_TYPE>
void Oop<WORD_TYPE>::setHeader(const WORD_TYPE anHeader){
  this -> header.setHeader(anHeader);
}

template <typename WORD_TYPE>
OopHeader<WORD_TYPE> Oop<WORD_TYPE>::getHeader(){
  return this -> header;
}

//shortcut
template <typename WORD_TYPE>
WORD_TYPE Oop<WORD_TYPE>::headerValue(){
  return this -> header.headerValue();
}

template <typename WORD_TYPE>
WORD_TYPE* Oop<WORD_TYPE>::getAddress(){
  return this -> address;
}

template <typename WORD_TYPE>
bool Oop<WORD_TYPE>::isFreeOop(){
  return this -> header.classIndexBits() == specialClassIndexes::freeObject;
}

template <typename WORD_TYPE>
void Oop<WORD_TYPE>::becomeFreeOop(){
  this -> header.setClassIndexBits(specialClassIndexes::freeObject);
}

template <typename WORD_TYPE>
Oop<WORD_TYPE>  Oop<WORD_TYPE>::nextOop(){
  Oop<WORD_TYPE> nextOop(this -> address + this -> bitSize());
  return nextOop;
}

template <typename WORD_TYPE>
WORD_TYPE Oop<WORD_TYPE>::bitSize(){
  return this -> header.bitSize();
}

template <typename WORD_TYPE>
WORD_TYPE Oop<WORD_TYPE>::wordSize(){
  return this -> header.wordSize();
}

template <typename WORD_TYPE>
Oop<WORD_TYPE> Oop<WORD_TYPE>::slotAt(WORD_TYPE anIndex){
  Oop<WORD_TYPE> slot( (WORD_TYPE*) this -> address[anIndex]);
  return slot;
}

template <typename WORD_TYPE>
void Oop<WORD_TYPE>::slotAtPut(WORD_TYPE anIndex, WORD_TYPE* anOopAddress){
  this -> address[anIndex] = (WORD_TYPE) anOopAddress;
}

#endif
