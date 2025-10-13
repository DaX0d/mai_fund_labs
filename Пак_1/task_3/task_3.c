#include "task_3.h"


static const bool equal(const double eps, const double a, const double b) {
    return fabs(a - b) <= eps;
}

static void solve(const double eps, double* params) {
    double a = params[0], b = params[1], c = params[2];

    printf("Уравнение: (%.4f)x^2 + (%.4f)x + (%.4f) = 0\n", a, b, c);

    if (equal(eps, a, 0)) {
        if (equal(eps, b, 0)) {
            if (equal(eps, c, 0)) {
                printf("  x = c; c - любое число\n\n");
                return;
            }
            printf("  Решений нет\n\n");
            return;
        }
        printf("  x = %.4f\n\n", -c / b);
        return;
    }

    double D = pow(b, 2) - 4 * a * c;
    if (equal(eps, D, 0)) {
        printf("  x = %.4f\n\n", -b / (2 * a));
        return;
    }
    if (D < 0) {
        printf("  Решений нет\n\n");
        return;
    }

    double x1 = (-b + sqrt(D)) / (2 * a),
           x2 = (-b - sqrt(D)) / (2 * a);
    printf("  x = %.4f\n  x = %.4f\n\n", x1, x2);
}


int q_function(
    const double eps,
    const double a,
    const double b,
    const double c)
{
    double permutations[6][3] = {
        {a, b, c},
        {a, c, b},
        {b, a, c},
        {b, c, a},
        {c, a, b},
        {c, b, a}
    };

    for (unsigned short i = 0; i < 6; ++i) {
        bool skip = false;
        for (unsigned short j = 0; j < i; ++j) {
            if (equal(eps, permutations[i][0], permutations[j][0])
                && equal(eps, permutations[i][1], permutations[j][1])
                && equal(eps, permutations[i][2], permutations[j][2]))
            {
                skip = true;
                break;
            }
        }
        if (!skip)
            solve(eps, permutations[i]);
    }

    return 0;
}

int m_function(const long long first, const long long second) {
    if (first % second == 0) {
        printf("Число %lld кратно числу %lld\n", first, second);
    } else {
        printf("Число %lld не кратно числу %lld\n", first, second);
    }
    return 0;
}

int t_tunction(
    const double eps,
    const double a,
    const double b,
    const double c)
{
    if (equal(eps, a, 0) || equal(eps, b, 0) || equal(eps, c, 0)
        || a < 0 || b < 0 || c < 0) {
        printf("Длина стороны не может быть меньше или равна нулю\n");
        return 1;
    }

    double arr[] = {a, b, c};
    for (unsigned short i = 0; i < 3; ++i) {
        if (equal(eps, pow(arr[i], 2), pow(arr[(i + 1) % 3], 2) + pow(arr[(i + 2) % 3], 2))) {
            printf("Числа могут являться длинами сторон прямоугоького треугоьлника\n");
            return 0;
        }
    }

    printf("Числа не могут являться длинами сторон прямоугоького треугоьлника\n");

    return 0;
}
