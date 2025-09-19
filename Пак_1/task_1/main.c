#include <stdio.h>
#include "task1.h"

int main(int argc, char **argv) {
    if (argc != 3) {
        printf("Usage: <number> -<flag>\n");
        return 0;
    }

    char* str_number = argv[1];
    ULL_T number = 0;
    US_T len = 0;
    
    for (US_T i = 0; str_number[i] != 0; ++i) {
        ++len;
    }

    return 0;
}
