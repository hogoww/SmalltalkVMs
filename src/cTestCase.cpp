/* preamble */

#include <stdio.h>
#include <stdlib.h>

void testPassed(){
  printf("Test passed\n");
  exit(EXIT_SUCCESS);
}

void testFailed(int line){
  printf("Assertion line: %d failed\n", line);
  exit(EXIT_FAILURE);
}


void cAssert(int line, int condition)
{
  if (condition) return;
  testFailed(line);
}

