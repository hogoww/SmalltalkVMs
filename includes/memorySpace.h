#ifndef __MEMORY_SPACE__
#define __MEMORY_SPACE__

#define WORD_TYPE uint64_t
#include <cstdlib>
#include <iostream>

#include <stdint.h>
#include "oop.h"


class MemorySpace {
 private:
  WORD_TYPE* startAddress;
  WORD_TYPE* endAddress;
 public:
  MemorySpace (WORD_TYPE spaceSize);
  ~MemorySpace();
  WORD_TYPE* getStartAddress();
  WORD_TYPE* getEndAddress();
  WORD_TYPE memorySpaceSize();
  //oop firstOop();
};


#endif
