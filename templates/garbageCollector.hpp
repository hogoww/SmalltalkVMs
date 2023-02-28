#ifndef __GARBAGE__COLLECTOR__HPP__
#define __GARBAGE__COLLECTOR__HPP__

#include <cstdlib>
#include <iostream>
#include <stdint.h>
#include <vector>

template <typename WORD_TYPE>
class GarbageCollector;

#include "oop.hpp"
#include "memorySpace.hpp"

template <typename WORD_TYPE>
class GarbageCollector {
private:
  MemorySpace<WORD_TYPE>* memorySpace;

public:
  //constructors
  GarbageCollector(MemorySpace<WORD_TYPE>* aMemorySpace);
  GarbageCollector(GarbageCollector const& anotherGarbageCollector) = delete;
  void operator=(GarbageCollector const& anotherMemorySpace) = delete;
    
  //API
  void collectFromRoots(std::vector<WORD_TYPE> roots);
};

template <typename WORD_TYPE>
GarbageCollector<WORD_TYPE>::GarbageCollector(MemorySpace<WORD_TYPE>* aMemorySpace){
  this -> memorySpace = aMemorySpace;
}

template <typename WORD_TYPE>
void GarbageCollector<WORD_TYPE>::collectFromRoots(std::vector<WORD_TYPE> roots){
  
}

#endif
