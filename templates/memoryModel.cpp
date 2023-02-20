#ifndef __MEMORY_MODEL_CPP__
#define __MEMORY_MODEL_CPP__

// Multiple bits
template <typename WORD_TYPE>
WORD_TYPE Oop<WORD_TYPE>::numberOfSlotsBits(){
  return this->getHeader() & 0xFF;
}

template <typename WORD_TYPE>
void Oop<WORD_TYPE>::setNumberOfSlotsBits(WORD_TYPE numberOfSlots){
  this -> setHeader((this->getHeader() & 0xFFFFFFFFFFFFFF00) | numberOfSlots);
}

template <typename WORD_TYPE>
WORD_TYPE Oop<WORD_TYPE>::hashBits(){
  return (this->getHeader() & 0xFFFFFC00) >> 10;
}

template <typename WORD_TYPE>
void Oop<WORD_TYPE>::setHashBits(WORD_TYPE hash){
  this -> setHeader((this->getHeader() & 0xFFFFFFFF000003FF) | hash << 10);
}

template <typename WORD_TYPE>
WORD_TYPE Oop<WORD_TYPE>::formatBits(){
  return (this->getHeader() & 0xFE00000000) >> 35;
}

template <typename WORD_TYPE>
void Oop<WORD_TYPE>::setFormatBits(WORD_TYPE format){
  this -> setHeader((this->getHeader() & 0xFFFFFF01FFFFFFFF) | format << 35);
}

template <typename WORD_TYPE>
WORD_TYPE Oop<WORD_TYPE>::classIndexBits(){
  return (this->getHeader() & 0xFFFFFC0000000000) >> 42;
}

template <typename WORD_TYPE>
void Oop<WORD_TYPE>::setClassIndexBits(WORD_TYPE classIndex){
  this -> setHeader((this->getHeader() & 0x000003FFFFFFFFFF) | classIndex << 42);
}


// Individual Bits
template <typename WORD_TYPE>
WORD_TYPE Oop<WORD_TYPE>::immutableBit(){
  return (this->getHeader() & 0x10000000000) >> 40;
}

template <typename WORD_TYPE>
void Oop<WORD_TYPE>::setImmutableBit(){
  this -> setHeader((this->getHeader() | 0x10000000000));
}

template <typename WORD_TYPE>
WORD_TYPE Oop<WORD_TYPE>::markedBit(){
  return (this->getHeader() & 0x1FF) >> 8;
}

template <typename WORD_TYPE>
void Oop<WORD_TYPE>::setMarkedBit(){
  this -> setHeader((this->getHeader() | 0x1FF));
}

template <typename WORD_TYPE>
WORD_TYPE Oop<WORD_TYPE>::pinnedBit(){
  return (this->getHeader() & 0x200000000) >> 33;
}

template <typename WORD_TYPE>
void Oop<WORD_TYPE>::setPinnedBit(){
  this -> setHeader((this->getHeader() | 0x200000000));
}

template <typename WORD_TYPE>
WORD_TYPE Oop<WORD_TYPE>::greyBit(){
  return (this->getHeader() & 0x100000000) >> 32;
}

template <typename WORD_TYPE>
void Oop<WORD_TYPE>::setGreyBit(){
  this -> setHeader((this->getHeader() | 0x100000000));
}

template <typename WORD_TYPE>
WORD_TYPE Oop<WORD_TYPE>::rememberedBit(){
  return (this->getHeader() & 0x10000000000) >> 34;
}

template <typename WORD_TYPE>
void Oop<WORD_TYPE>::setRememberedBit(){
  this -> setHeader((this->getHeader() | 0x10000000000));
}

#endif
