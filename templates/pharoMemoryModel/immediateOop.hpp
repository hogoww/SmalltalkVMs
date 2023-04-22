#ifndef __IMMEDIATE__OOP__HPP__
#define __IMMEDIATE__OOP__HPP__

#include "specialClassIndexes.h"
#include "headerFormatValues.h"
#include "oop.hpp"
#include <cstdlib> // for NULL
#include <iostream>


template <typename WORD_TYPE>
class ImmediateOop : public Oop<WORD_TYPE> {
public:
  static bool isImmediateOop(WORD_TYPE* oop);
  
};

template <typename WORD_TYPE>
bool ImmediateOop<WORD_TYPE>::isImmediateOop(WORD_TYPE* oop){
  return OopHeader(oop).formatBits() == headerFormatValues::immediateFormat;
}


#endif
