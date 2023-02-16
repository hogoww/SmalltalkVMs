#ifndef __MEMORY_MODEL_H__
#define __MEMORY_MODEL_H__

WORD_TYPE numberOfSlotsBits();
WORD_TYPE hashBits();
WORD_TYPE formatBits();
WORD_TYPE classIndexBits();

WORD_TYPE immutableBit();
WORD_TYPE markedBit();
WORD_TYPE pinnedBit();
WORD_TYPE greyBit();
WORD_TYPE rememberedBit();

#endif
