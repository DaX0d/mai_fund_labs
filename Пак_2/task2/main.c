#include <stdio.h>

#include "task2.h"

int main() {
    const void* str1 = "1234";
    const void* str2 = "1345";
    printf("%d\n", memcmp(str1, str2, 3));

    return 0;
}
