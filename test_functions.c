#include <stdio.h>
#include <assert.h>
#include "test_functions.h"

void testNumberToPair(int pairNumber, enum MajorColor expectedMajor, enum MinorColor expectedMinor)
{
    ColorPair colorPair = GetColorFromPairNumber(pairNumber);
    char colorPairNames[MAX_COLORPAIR_NAME_CHARS];

    ColorPairToString(&colorPair, colorPairNames);
    (void)printf("Got pair %s\n", colorPairNames);

    assert(colorPair.majorColor == expectedMajor);
    assert(colorPair.minorColor == expectedMinor);
}

void testPairToNumber(enum MajorColor major, enum MinorColor minor, int expectedPairNumber)
{
    ColorPair colorPair;
    int pairNumber = GetPairNumberFromColor(&colorPair);

    colorPair.majorColor = major;
    colorPair.minorColor = minor;

    (void)printf("Got pair number %d\n", pairNumber);

    assert(pairNumber == expectedPairNumber);
}