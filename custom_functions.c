#include <stdio.h>
#include "custom_functions.h"

extern const char* MajorColorNames[];
extern const char* MinorColorNames[];

void printAllPairColor(void)
{
    int counter = 1;
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++, counter++) {
            (void)printf("%02d. %s, %s\n", counter, MajorColorNames[i], MinorColorNames[j]);
        }
    }
}
