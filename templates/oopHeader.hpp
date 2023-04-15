#ifndef __OOP__HEADER__HPP__
#define __OOP__HEADER__HPP__

#include "specialClassIndexes.h"
#include <cstdlib> // for NULL
#include <iostream>

template <typename WORD_TYPE>
class OopHeader {
 protected:
  WORD_TYPE* address;

 public:
  #include "memoryModel.h"
  //constructors
  OopHeader(WORD_TYPE* address);
  OopHeader();

  //Memory model
  #include "memoryModel.h"
  
  //Accessing
  WORD_TYPE headerValue();
  void setHeader(const WORD_TYPE anHeader);
  WORD_TYPE* getAddress();

  //Size
  WORD_TYPE bitSize();
  WORD_TYPE wordSize();
};


template <typename WORD_TYPE>
OopHeader<WORD_TYPE>::OopHeader(WORD_TYPE* anAddress){
  this -> address = anAddress;
}

//This constructor should be only used for its Mock subclass.
template <typename WORD_TYPE>
OopHeader<WORD_TYPE>::OopHeader(){
  std::cout << "should never be called" << std::endl;
  this -> address = NULL;
}

template <typename WORD_TYPE>
void OopHeader<WORD_TYPE>::setHeader(const WORD_TYPE anHeader){
  *(this -> address) = anHeader;
}

template <typename WORD_TYPE>
WORD_TYPE OopHeader<WORD_TYPE>::headerValue(){
  return *(this -> address);
}

template <typename WORD_TYPE>
WORD_TYPE* OopHeader<WORD_TYPE>::getAddress(){
  return this -> address;
}

template <typename WORD_TYPE>
WORD_TYPE OopHeader<WORD_TYPE>::bitSize(){
  return this -> wordSize() * sizeof(WORD_TYPE) * 8;
}

template <typename WORD_TYPE>
WORD_TYPE OopHeader<WORD_TYPE>::wordSize(){
  return this -> numberOfSlotsBits() + 1;
}

#include "memoryModel.cpp"

#endif
