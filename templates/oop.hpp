#ifndef __OOP__HPP__
#define __OOP__HPP__

#include "specialClassIndexes.h"
#include <cstdlib> // for NULL

template <typename WORD_TYPE>
class Oop {
 protected:
  WORD_TYPE* address;

 public:
  #include "memoryModel.h"
  //constructors
  Oop(WORD_TYPE* address);
  Oop();
  
  //Accessing
  WORD_TYPE getHeader();
  void setHeader(const WORD_TYPE anHeader);
  WORD_TYPE* getAddress();
  //  bool isInteger();
  //  bool isOOP();
  bool isFreeOop();

  //Navigating
  Oop<WORD_TYPE> nextOop();

  //Size
  WORD_TYPE bitSize();
};


template <typename WORD_TYPE>
Oop<WORD_TYPE>::Oop(WORD_TYPE* anAddress){
  this -> address = anAddress;
}

//This constructor should be only used for its Mock subclass.
template <typename WORD_TYPE>
Oop<WORD_TYPE>::Oop(){
  this -> address = NULL;
}

template <typename WORD_TYPE>
void Oop<WORD_TYPE>::setHeader(const WORD_TYPE anHeader){
  *this -> address = anHeader;
}

template <typename WORD_TYPE>
WORD_TYPE Oop<WORD_TYPE>::getHeader(){
  return *this -> address;
}

template <typename WORD_TYPE>
WORD_TYPE* Oop<WORD_TYPE>::getAddress(){
  return this -> address;
}

template <typename WORD_TYPE>
bool Oop<WORD_TYPE>::isFreeOop(){
  return this-> classIndexBits() == specialClassIndexes::freeObject;
}

template <typename WORD_TYPE>
Oop<WORD_TYPE>  Oop<WORD_TYPE>::nextOop(){
  Oop<WORD_TYPE> nextOop(this -> address + this -> bitSize());
  return nextOop;
}

template <typename WORD_TYPE>
WORD_TYPE Oop<WORD_TYPE>::bitSize(){
  return this -> numberOfSlotsBits() * sizeof(WORD_TYPE);
}

#include "memoryModel.cpp"

#endif
