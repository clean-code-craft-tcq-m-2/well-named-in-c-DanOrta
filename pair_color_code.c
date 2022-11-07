#include <stdio.h>
#include "pair_color_code.h"
#include "test_functions.h"

const char* MajorColorNames[] = { "White", "Red", "Black", "Yellow", "Violet" };
const char* MinorColorNames[] = { "Blue", "Orange", "Green", "Brown", "Slate" };

#define numberOfMinorColors     ((int)(sizeof(MinorColorNames) / sizeof(MinorColorNames[0])))

void ColorPairToString(const ColorPair* colorPair, char* buffer)
{
    (void)sprintf(buffer, "%s %s", MajorColorNames[colorPair->majorColor], MinorColorNames[colorPair->minorColor]);
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
