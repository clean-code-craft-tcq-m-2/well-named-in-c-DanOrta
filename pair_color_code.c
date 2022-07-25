#include <stdio.h>
#include <assert.h>
#include "pair_color_code.h"

const char* MajorColorNames[] = { "White", "Red", "Black", "Yellow", "Violet" };
const char* MinorColorNames[] = { "Blue", "Orange", "Green", "Brown", "Slate" };

int numberOfMajorColors = sizeof(MajorColorNames) / sizeof(MajorColorNames[0]);
const int MAX_COLORPAIR_NAME_CHARS = 16;
int numberOfMinorColors = sizeof(MinorColorNames) / sizeof(MinorColorNames[0]);

void ColorPairToString(const ColorPair* colorPair, char* buffer)
{
    sprintf(buffer, "%s %s", MajorColorNames[colorPair->majorColor], MinorColorNames[colorPair->minorColor]);
}

ColorPair GetColorFromPairNumber(int pairNumber)
{
    ColorPair colorPair;
    int zeroBasedPairNumber = pairNumber - 1;
    colorPair.majorColor = (enum MajorColor)(zeroBasedPairNumber / numberOfMinorColors);
    colorPair.minorColor = (enum MinorColor)(zeroBasedPairNumber % numberOfMinorColors);
    return colorPair;
}

int GetPairNumberFromColor(const ColorPair* colorPair)
{
    return ((colorPair->majorColor * numberOfMinorColors) + (colorPair->minorColor + 1));
}

void testNumberToPair(int pairNumber, enum MajorColor expectedMajor, enum MinorColor expectedMinor)
{
    ColorPair colorPair = GetColorFromPairNumber(pairNumber);
    char colorPairNames[MAX_COLORPAIR_NAME_CHARS];
    ColorPairToString(&colorPair, colorPairNames);
    printf("Got pair %s\n", colorPairNames);
    assert(colorPair.majorColor == expectedMajor);
    assert(colorPair.minorColor == expectedMinor);
}

void testPairToNumber(enum MajorColor major, enum MinorColor minor, int expectedPairNumber)
{
    ColorPair colorPair;
    colorPair.majorColor = major;
    colorPair.minorColor = minor;
    int pairNumber = GetPairNumberFromColor(&colorPair);
    printf("Got pair number %d\n", pairNumber);
    assert(pairNumber == expectedPairNumber);
}

void printAllPairColor(void)
{
    int counter = 1;
    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            printf("%02d. %s, %s\n", counter, MajorColorNames[i], MinorColorNames[j]);
            counter++;
        }
    }
}
