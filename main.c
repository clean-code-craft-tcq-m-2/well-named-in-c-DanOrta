#include <stdio.h>
#include "pair_color_code.h"
#include "test_functions.h"
#include "custom_functions.h"

int main(void) {
    testNumberToPair(4, WHITE, BROWN);
    testNumberToPair(5, WHITE, SLATE);

    testPairToNumber(BLACK, ORANGE, 12);
    testPairToNumber(VIOLET, SLATE, 25);

    printAllPairColor();

    return 0;
}
