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

    if (flag[1] == 'h' || flag[0] == 'T') {
        if (number == 0) {
            printf("Can't divide by zero\n");
            return 0;
        }
        printf("%llu\n", number);
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
    }

    return 0;
}
