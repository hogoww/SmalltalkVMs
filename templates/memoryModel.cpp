#ifndef __MEMORY_MODEL_CPP__
#define __MEMORY_MODEL_CPP__

// Multiple bits
template <typename WORD_TYPE>
WORD_TYPE OopHeader<WORD_TYPE>::numberOfSlotsBits(){
  return this->headerValue() & 0xFF;
}

template <typename WORD_TYPE>
void OopHeader<WORD_TYPE>::setNumberOfSlotsBits(WORD_TYPE numberOfSlots){
  this -> setHeader((this->headerValue() & 0xFFFFFFFFFFFFFF00) | numberOfSlots);
}

template <typename WORD_TYPE>
WORD_TYPE OopHeader<WORD_TYPE>::hashBits(){
  return (this->headerValue() & 0xFFFFFC00) >> 10;
}

template <typename WORD_TYPE>
void OopHeader<WORD_TYPE>::setHashBits(WORD_TYPE hash){
  this -> setHeader((this->headerValue() & 0xFFFFFFFF000003FF) | hash << 10);
}

template <typename WORD_TYPE>
WORD_TYPE OopHeader<WORD_TYPE>::formatBits(){
  return (this->headerValue() & 0xFE00000000) >> 35;
}

template <typename WORD_TYPE>
void OopHeader<WORD_TYPE>::setFormatBits(WORD_TYPE format){
  this -> setHeader((this->headerValue() & 0xFFFFFF01FFFFFFFF) | format << 35);
}

template <typename WORD_TYPE>
WORD_TYPE OopHeader<WORD_TYPE>::classIndexBits(){
  return (this->headerValue() & 0xFFFFFC0000000000) >> 42;
}

template <typename WORD_TYPE>
void OopHeader<WORD_TYPE>::setClassIndexBits(WORD_TYPE classIndex){
  this -> setHeader((this->headerValue() & 0x000003FFFFFFFFFF) | classIndex << 42);
}


// Individual Bits
template <typename WORD_TYPE>
WORD_TYPE OopHeader<WORD_TYPE>::immutableBit(){
  return (this->headerValue() & 0x10000000000) >> 40;
}

template <typename WORD_TYPE>
void OopHeader<WORD_TYPE>::setImmutableBit(){
  this -> setHeader((this->headerValue() | 0x10000000000));
}

template <typename WORD_TYPE>
WORD_TYPE OopHeader<WORD_TYPE>::markedBit(){
  return (this->headerValue() & 0x1FF) >> 8;
}

template <typename WORD_TYPE>
void OopHeader<WORD_TYPE>::setMarkedBit(){
  this -> setHeader((this->headerValue() | 0x100));
}

template <typename WORD_TYPE>
void OopHeader<WORD_TYPE>::unsetMarkedBit(){
  this -> setHeader((this->headerValue() & 0xFFFFFFFFFFFFFEFF));
}

template <typename WORD_TYPE>
WORD_TYPE OopHeader<WORD_TYPE>::pinnedBit(){
  return (this->headerValue() & 0x200000000) >> 33;
}

template <typename WORD_TYPE>
void OopHeader<WORD_TYPE>::setPinnedBit(){
  this -> setHeader((this->headerValue() | 0x200000000));
}

template <typename WORD_TYPE>
WORD_TYPE OopHeader<WORD_TYPE>::greyBit(){
  return (this->headerValue() & 0x100000000) >> 32;
}

template <typename WORD_TYPE>
void OopHeader<WORD_TYPE>::setGreyBit(){
  this -> setHeader((this->headerValue() | 0x100000000));
}

template <typename WORD_TYPE>
WORD_TYPE OopHeader<WORD_TYPE>::rememberedBit(){
  return (this->headerValue() & 0x10000000000) >> 40;
}

template <typename WORD_TYPE>
void OopHeader<WORD_TYPE>::setRememberedBit(){
  this -> setHeader((this->headerValue() | 0x10000000000));
}

#endif
