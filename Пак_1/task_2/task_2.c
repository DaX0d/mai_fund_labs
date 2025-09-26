#include "task_2.h"

ULL_T prime_by_n(const int n, ULL_T* all_prime) {
    return all_prime[n];
}

void generate_array_of_primes(ULL_T* array_of_primes, const int len) {
    int i = 0;
    ULL_T num = 1;
    while (i < len) {
        if (is_prime(++num)) array_of_primes[i++] = num;
    }
}

int max(int* const array, const int len) {
    int ans = 0;
    for (int i = 0; i < len; ++i) {
        if (array[i] > ans) ans = array[i];
    }
    return ans;
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
