#include "./setUp.cpp"


int main(){
  setUp();
  cAssertInts(__LINE__, oop.classIndexBits(), 0x3FFFFF);
  testPassed();
}
