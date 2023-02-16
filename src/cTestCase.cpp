
#include "cTestCase.h"

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

void cAssertInts(int line, int64_t anInteger, int64_t anotherInteger)
{
  if (anInteger == anotherInteger) return;
  std::cout << "Expected " << std::hex << anotherInteger << " Actual " << std::hex << anInteger << std::endl;
  testFailed(line);
}
