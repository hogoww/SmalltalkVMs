#ifndef __OOP__HPP__
#define __OOP__HPP__

template <typename WORD_TYPE>
class Oop {
 private:
  WORD_TYPE header;

 public:
  #include "memoryModel.h"

  void setHeader(const WORD_TYPE anHeader);
  bool isInteger();
  bool isOOP();
  bool isFreeOop(){
    return header;
  };
};

template <typename WORD_TYPE>
void Oop<WORD_TYPE>::setHeader(const WORD_TYPE anHeader){
  this-> header = anHeader;
}

#include "memoryModel.cpp"

#endif
