#ifndef __OOP__MOCK__HPP__
#define __OOP__MOCK__HPP__

#include "oop.hpp"

template <typename WORD_TYPE>
class OopMock : public Oop<WORD_TYPE> {
 public:
  #include "memoryModel.h"
  //constructors
  OopMock();
  ~OopMock();
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
