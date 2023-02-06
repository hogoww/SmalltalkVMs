#ifndef __C_TEST_CASE_H__
#define __C_TEST_CASE_H__

#include <stdio.h>
#include <stdlib.h>

void testPassed();
void testFailed(int line);
void cAssert(int line, int condition);

#endif
