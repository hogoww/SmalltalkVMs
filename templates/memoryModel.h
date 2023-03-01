#ifndef __MEMORY_MODEL_H__
#define __MEMORY_MODEL_H__

WORD_TYPE numberOfSlotsBits();
void setNumberOfSlotsBits(WORD_TYPE numberOfSlots);
WORD_TYPE hashBits();
void setHashBits(WORD_TYPE hash);
WORD_TYPE formatBits();
void setFormatBits(WORD_TYPE format);
WORD_TYPE classIndexBits();
void setClassIndexBits(WORD_TYPE classIndex);

WORD_TYPE immutableBit();
void setImmutableBit();
WORD_TYPE markedBit();
void setMarkedBit();
void unsetMarkedBit();
WORD_TYPE pinnedBit();
void setPinnedBit();
WORD_TYPE greyBit();
void setGreyBit();
WORD_TYPE rememberedBit();
void setRememberedBit();

#endif
