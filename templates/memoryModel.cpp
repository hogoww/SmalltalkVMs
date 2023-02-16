#ifndef __MEMORY_MODEL_CPP__
#define __MEMORY_MODEL_CPP__

template <typename WORD_TYPE>
WORD_TYPE Oop<WORD_TYPE>::numberOfSlotsBits(){
  return this->header & 0xFF;
}

template <typename WORD_TYPE>
WORD_TYPE Oop<WORD_TYPE>::hashBits(){
  return (this -> header & 0x00CFFFFF) >> 10;
}

template <typename WORD_TYPE>
WORD_TYPE Oop<WORD_TYPE>::formatBits(){
  return (this->header & 0x8F00000000) >> 27;
}

template <typename WORD_TYPE>
WORD_TYPE Oop<WORD_TYPE>::classIndexBits(){
  return (this->header & 0x3FFFFF) >> 42;
}

template <typename WORD_TYPE>
WORD_TYPE Oop<WORD_TYPE>::immutableBit(){
  return (this->header & 0x10000000000) >> 40;
}

template <typename WORD_TYPE>
WORD_TYPE Oop<WORD_TYPE>::markedBit(){
  return (this->header & 0x1FF) >> 8;
}

template <typename WORD_TYPE>
WORD_TYPE Oop<WORD_TYPE>::pinnedBit(){
  return (this->header & 0x200000000) >> 33;
}

template <typename WORD_TYPE>
WORD_TYPE Oop<WORD_TYPE>::greyBit(){
  return (this->header & 0x100000000) >> 32;
}

template <typename WORD_TYPE>
WORD_TYPE Oop<WORD_TYPE>::rememberedBit(){
  return (this->header & 0x10000000000) >> 34;
}

#endif
