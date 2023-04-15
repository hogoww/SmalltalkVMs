#ifndef __IMMEDIATE__OOP__HPP__
#define __IMMEDIATE__OOP__HPP__

#include "specialClassIndexes.h"
#include "oop.h"
#include ""
#include <cstdlib> // for NULL
#include <iostream>


template <typename WORD_TYPE>
class ImmediateOop : public Oop<WORD_TYPE> {

  static bool isImmediateOop(WORD_TYPE* oop){
    return OopHeader(oop).getFormat() == ;
  }
};

template <typename WORD_TYPE>
OopMock<WORD_TYPE>::OopMock(){
  this -> address = new WORD_TYPE[1];
}

template <typename WORD_TYPE>
OopMock<WORD_TYPE>::~OopMock(){
  if(this -> address == NULL)
    { return; }
  
  delete[] this -> address;
}


#endif
