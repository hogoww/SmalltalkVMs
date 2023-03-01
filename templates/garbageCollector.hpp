#ifndef __GARBAGE__COLLECTOR__HPP__
#define __GARBAGE__COLLECTOR__HPP__

#include <cstdlib>
#include <iostream>
#include <stdint.h>
#include <vector>
#include <stack>

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
  void collectFromRoots(std::vector<WORD_TYPE*> roots);

  //internals
  void markOopsFromRoots(std::vector<WORD_TYPE*> roots);
  void sweepOops();
  void mergeFreeOops();
};

template <typename WORD_TYPE>
GarbageCollector<WORD_TYPE>::GarbageCollector(MemorySpace<WORD_TYPE>* aMemorySpace){
  this -> memorySpace = aMemorySpace;
}

template <typename WORD_TYPE>
void GarbageCollector<WORD_TYPE>::collectFromRoots(std::vector<WORD_TYPE*> roots){
  this -> markOopsFromRoots(roots);
  this -> sweepOops();
  this -> mergeFreeOops();
}

template <typename WORD_TYPE>
void GarbageCollector<WORD_TYPE>::markOopsFromRoots(std::vector<WORD_TYPE*> roots){
  std::stack<WORD_TYPE*> oopToMark;
  for (auto aRoot = roots.cbegin(); aRoot != roots.cend(); ++aRoot){
    oopToMark.push(*aRoot);
  }

  while (not oopToMark.empty()){
    Oop<WORD_TYPE> anOop(oopToMark.top());
    oopToMark.pop();
    
    if( not anOop.markedBit() ){
      std::cout << "marking :" << anOop.getAddress() << std::endl;
      anOop.setMarkedBit();
      //FLAG should NOT iterate over slots. This is the Oop responsibility
      for (WORD_TYPE anIndex = 1; anIndex <= anOop.numberOfSlotsBits() ; ++anIndex){
	oopToMark.push(anOop.slotAt(anIndex).getAddress());
      }
    }
  }    
}

template <typename WORD_TYPE>
void GarbageCollector<WORD_TYPE>::sweepOops(){
  Oop<WORD_TYPE> currentOop = memorySpace -> firstOop();
  while ( currentOop.getAddress() < memorySpace -> getEndAddress() ){
    if(currentOop.markedBit()){
      currentOop.unsetMarkedBit();
    }
    else {
      currentOop.becomeFreeOop();
    }
    
    currentOop = currentOop.nextOop();
  }
}

template <typename WORD_TYPE>
void GarbageCollector<WORD_TYPE>::mergeFreeOops(){
  WORD_TYPE* endAddress = memorySpace -> getEndAddress();
  Oop<WORD_TYPE> currentOop = memorySpace -> firstOop();
  Oop<WORD_TYPE> nextOop = currentOop.nextOop();
    
  while ( currentOop.getAddress() < endAddress ){
    if(currentOop.isFreeOop() && currentOop.nextOop().getAddress() < endAddress && currentOop.nextOop().isFreeOop()){
      // + 1 because the header has the same size as a slot (at this time)
      currentOop.setNumberOfSlotsBits(currentOop.numberOfSlotsBits() + nextOop.numberOfSlotsBits() + 1);
    }
    
    currentOop = currentOop.nextOop();
    nextOop = currentOop.nextOop();
  }
}


#endif

