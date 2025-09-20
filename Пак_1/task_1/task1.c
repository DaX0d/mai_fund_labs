#include "task1.h"

US_T* natural_numbers(const ULL_T number) {
    if (number > 100) {
        US_T* ans = (US_T*)malloc(sizeof(US_T));
        ans[0] = 0;
        return ans;
    }

    US_T* array = (US_T*)calloc(100, sizeof(US_T));
    if (array == NULL) {
        printf("Memory allocation failed\n");
        return NULL;
    }

    US_T j = 0;
    for (US_T i = 1; i < 101; ++i) {
        if (i % number == 0) {
            array[j++] = i;
        }
        // printf("%hu %hu %hu\n", i, j, array[j - 1]);
    }

    return array;
}

int is_prime(const ULL_T number) {
    if (number < 2) return 0;
    if (number == 2) return 1;
    if (number % 2 == 0) return 0;
    ULL_T max = (ULL_T)sqrtl((long double)number);
    for (ULL_T i = 3; i <= max; i += 2) {
        if (number % i == 0) return 0;
    }
    return 1;
}

char div_hex(const ULL_T) {
    return 0;
}

int degree_dec(const ULL_T) {
    return 0;
}

ULL_T sum_of_natural(const ULL_T) {
    return 0;
}

ULL_T factorial(const ULL_T) {
    return 0;
}
