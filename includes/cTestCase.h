#ifndef __C_TEST_CASE_H__
#define __C_TEST_CASE_H__

#include <iostream>

void testPassed();
void testFailed(int line);
void cAssert(int line, int condition);
void cAssertInts(int line, int64_t anInteger, int64_t anotherInteger);

#endif
