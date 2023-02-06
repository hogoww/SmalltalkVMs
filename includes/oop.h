#ifndef __OOP__
#define __OOP__

#define WORD_TYPE uint64_t

class oop {
 private:
  WORD_TYPE header;

 public:
  bool isInteger();
  bool isOOP();
  WORD_TYPE classIndex();
};


#endif
