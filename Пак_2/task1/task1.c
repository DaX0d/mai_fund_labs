#include "task1.h"

int gcd(const int a, const int b) {
    int ta = a, tb = b;
    while (tb != 0) {
        int t = ta % tb;
        ta = tb;
        tb = t;
    }
    return ta;
}

bool has_finite_repr(const double x, const int base, const double eps) {
    int maxDen = (int)(1.0 / eps);
    if (maxDen < 1) maxDen = 1;

    int num = (int)(x * maxDen + 0.5);
    int den = maxDen;

    int g = gcd(num, den);
    num /= g;
    den /= g;

    for (int i = 2; i <= base && den > 1; i++) {
        if (base % i == 0) {
            while (den % i == 0)
                den /= i;
        }
    }

    return den == 1;
}

void check_fractions(const int base, const double eps, const int count, ...) {
    va_list args;
    va_start(args, count);

    printf("Система счисления %d\n", base);

    for (int i = 0; i < count; ++i) {
        double num = va_arg(args, double);

        if (has_finite_repr(num, base, eps)) {
            printf("  %.10f имеет конечное представление\n", num);
        } else {
            printf("  %.10f не имеет конечного представления\n", num);
        }
    }
    va_end(args);
}
