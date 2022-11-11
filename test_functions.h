#ifndef __TEST_FUNCTIONS_H__
#define __TEST_FUNCTIONS_H__

#include "pair_color_code.h"

void testNumberToPair(int pairNumber, enum MajorColor expectedMajor, enum MinorColor expectedMinor);
void testPairToNumber(enum MajorColor major, enum MinorColor minor, int expectedPairNumber);

#endif