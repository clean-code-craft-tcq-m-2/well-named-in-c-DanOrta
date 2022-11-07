#ifndef __TEST_FUNCTIONS_C__
#define __TEST_FUNCTIONS_C__

#include "pair_color_code.h"

void testNumberToPair(int pairNumber, enum MajorColor expectedMajor, enum MinorColor expectedMinor);
void testPairToNumber(enum MajorColor major, enum MinorColor minor, int expectedPairNumber);

#endif