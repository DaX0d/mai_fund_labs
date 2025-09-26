#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define ULL_T unsigned long long

ULL_T prime_by_n(const int n, ULL_T* all_prime);
void generate_array_of_primes(ULL_T* array_of_primes, const int len);

int max(int* const array,const int len);
int is_prime(const ULL_T number);
