#include "task1.h"

int main(int argc, char* argv[]) {
    // Проверка правильности ввода команды 
    if (argc != 3) {
        printf("Usage: <number> -<flag>\n");
        return 1;
    }
    if (argv[1][0] == '-') {
        printf("Number can't be negative\n");
        return 1;
    }

    char* endptr;
    ULL_T number = strtoull(argv[1], &endptr, 10);

    // Валидация
    if (*endptr != '\0') {
        printf("Unexpected input");
        return 1;
    }
    if (number == ULLONG_MAX) {
        printf("Too large number\n");
        return 1;
    }
    
    char* flag = argv[2];
    // printf("%s\n", flag);

    if (flag[1] == 'h' || flag[0] == 'H') {
        if (number == 0) {
            printf("Can't divide by zero\n");
            return 0;
        }
        // printf("%llu\n", number);
        US_T* ans = natural_numbers(number);
        if (ans == NULL) {
            return 2;
        }
        if (ans[0] == 0) {
            printf("No results found\n");
            free(ans);
            return 0;
        }
        US_T i = 0;
        while (ans[i] != 0 && i < 100) {
            printf("%hu ", ans[i++]);
        }
        free(ans);
    } else {
    if (flag[1] == 'p' || flag[0] == 'P') {
        if (is_prime(number)) {
            printf("This is a prime number\n");
        } else {
            printf("This is NOT a prime number\n");
        }
    } else {
    if (flag[1] == 's' || flag[0] == 'S') {
        char* hex_str = div_hex(number);
        if (hex_str == NULL) return 2;
        for (US_T i = 0; hex_str[i] != '\0'; ++i) {
            printf("%c ", hex_str[i]);
        }
        printf("\n");
        free(hex_str);
    } else {
    if (flag[1] == 'e' || flag[0] == 'E') {
        if (number > 10) {
            printf("Number must not be more then 10\n");
            return 0;
        }
        ULL_T** matrix = degree_dec(number);
        if (matrix == NULL) return 2;
        for (US_T i = 0; i < 10; ++i) {
            for (US_T j = 0; j < number; ++j) {
                printf("%11llu ", matrix[i][j]);
            }
            printf("\n");
        }
        free_matrix(matrix);
    } else {
    if (flag[1] == 'a' || flag[0] == 'A') {
        if (number == 0) {
            printf("Number must not be less then 1\n");
            return 1;
        }
        ULL_T ans = sum_of_natural(number);
        if (ans == 0) {
            printf("Too big number\n");
            return 1;
        }
        printf("%llu\n", ans);
    }}}}}

    return 0;
}
