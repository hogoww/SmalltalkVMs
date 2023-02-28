#ifndef SETUP__CPP
#define SETUP__CPP

#include "oopMock.hpp"
#include "cTestCase.h"

#ifndef WORD_TYPE
#define WORD_TYPE uint64_t
#endif

MemorySpace<WORD_TYPE> ms(640);

void setUp(){
}

#endif
