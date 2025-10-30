#pragma once

#include <stdio.h>
#include <stdarg.h>
#include <stdbool.h>

int gcd(const int a, const int b);
bool has_finite_repr(const double x, const int base, double eps);
void check_fractions(const int base, const double eps, const int count, ...);
