#ifndef __HEADER__FORMAT__VALUES__H__
#define __HEADER__FORMAT__VALUES__H__

namespace headerFormatValues{
  const int zeroSizedFormat = 0; // nil, true false
  const int nonIndexableWithSlotsFormat = 1; // Point
  const int indexableWithoutSlotsFormat = 2; // Array
  const int indexableWithSlotsFormat = 3; // MethodContext 
  const int weakIndexableWithSlotsFormat = 4; // Weak Array
  const int weakNonIndexableWithSlotsFormat = 5; // Ephemerons
  // 6 is unused
  const int immediateFormat = 7; // Smallinteger, Characters, BoxedFloats
  // 8 is unused
  const int i64BitIndexable = 9;

  //todo, can we do ranges ? Not an enumeration so...
  
};


#endif
