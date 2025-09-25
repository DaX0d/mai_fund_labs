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

char* div_hex(const ULL_T number) {
    if (number == 0) {
        char* ans = (char*)malloc(2 * sizeof(char));
        if (ans == NULL) {
            printf("Memory allocation failed\n");
            return NULL;
        }
        ans[0] = '0'; ans[1] = '\0';
        return ans;
    }
    const char alphabet[] = "0123456789ABCDEF";
    ULL_T tmp_num = number;
    char ans_rev[17];
    US_T len = 0;
    while (tmp_num > 0) {
        ans_rev[len++] = alphabet[tmp_num % 16];
        tmp_num /= 16;
    }
    char* ans = (char*)calloc(len + 1, sizeof(char));
    if (ans == NULL) {
        printf("Memory allocation failed\n");
        return NULL;
    }
    for (US_T i = 0; i < len; ++i) {
        ans[i] = ans_rev[len - 1 - i];
    }
    ans[len] = '\0';
    return ans;
}

ULL_T** degree_dec(const ULL_T number) {
    ULL_T** ans = (ULL_T**)calloc(10, sizeof(ULL_T*));
    if (ans == NULL) {
        printf("Memory allocation failed\n");
        return NULL;
    }
    for (US_T i = 0; i < 10; ++i) {
        ans[i] = (ULL_T*)calloc(number, sizeof(ULL_T));
        if (ans[i] == NULL) {
            printf("Memory allocation failed\n");
            return NULL;
        }
        for (US_T j = 0; j < number; ++j) {
            ans[i][j] = (ULL_T)powl(i + 1, j + 1);
        }
    }
    return ans;
}

ULL_T sum_of_natural(const ULL_T number) {
    ULL_T ans = number;
    for (ULL_T i = number - 1; i > 0; --i) {
        if (ULLONG_MAX - ans < i) return 0;
        ans += i;
    }
    return ans;
}

ULL_T factorial(const ULL_T number) {
    ULL_T ans = 1;
    for (ULL_T i = 2; i <= number; ++i) {
        if (ans > ULLONG_MAX / i) return 0;
        ans *= i;
    }
    return ans;
}

void free_matrix(ULL_T** matrix) {
    for (US_T i = 0; i < 10; ++i) {
        free(matrix[i]);
    }
    free(matrix);
}
