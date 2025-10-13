#include "task_3.h"

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: %s -<flag>(/<flag>) <parameters>\n", argv[0]);
        return 1;
    }

    char* flag = argv[1];
    if (flag[0] != '-' && flag[0] != '/') {
        printf("Usage: %s -<flag>(/<flag>) <parameters>\n", argv[0]);
        return 1;
    }

    switch (flag[1]) {
        case 'q':
            if (argc != 6) {
                printf("Usage: %s -q <eps> <float> <float> <float>\n", argv[0]);
                return 1;
            }
            {
                char* endptr;
                double eps = strtod(argv[2], &endptr);
                if (*endptr != 0) {
                    printf("Error: invalid parameter %s Must be <eps>\n", argv[2]);
                    return 1;
                }
                if (eps <= 0) {
                    printf("Error: eps must be more then zero\n");
                    return 1;
                }
                double a = strtod(argv[3], &endptr);
                if (*endptr != 0) {
                    printf("Error: invalid parameter %s Must be <float>\n", argv[3]);
                    return 1;
                }
                double b = strtod(argv[4], &endptr);
                if (*endptr != 0) {
                    printf("Error: invalid parameter %s Must be <float>\n", argv[4]);
                    return 1;
                }
                double c = strtod(argv[5], &endptr);
                if (*endptr != 0) {
                    printf("Error: invalid parameter %s Must be <float>\n", argv[5]);
                    return 1;
                }
                return q_function(eps, a, b, c);
            }
        break;
        case 'm':
            if (argc != 4) {
                printf("Usage: %s -m <int> <int>\n", argv[0]);
                return 1;
            }
            {
                char* endptr;
                long long first = strtoll(argv[2], &endptr, 10);
                if (*endptr != 0) {
                    printf("Error: invalid parameter %s. Must be <int>\n", argv[2]);
                    return 1;
                }
                long long second = strtoll(argv[3], &endptr, 10);
                if (*endptr != 0) {
                    printf("Error: invalid parameter %s. Must be <int>\n", argv[3]);
                    return 1;
                }
                if (first == 0 || second == 0) {
                    printf("Error: parameter can't be equal to zero\n");
                    return -1;
                }
                return m_function(first, second);
            }
        break;
        case 't':
            if (argc != 6) {
                printf("Usage: %s -q <eps> <float> <float> <float>\n", argv[0]);
                return 1;
            }
            char* endptr;
                double eps = strtod(argv[2], &endptr);
                if (*endptr != 0) {
                    printf("Error: invalid parameter %s Must be <eps>\n", argv[2]);
                    return 1;
                }
                if (eps <= 0) {
                    printf("Error: eps must be more then zero\n");
                    return 1;
                }
                double a = strtod(argv[3], &endptr);
                if (*endptr != 0) {
                    printf("Error: invalid parameter %s Must be <float>\n", argv[3]);
                    return 1;
                }
                double b = strtod(argv[4], &endptr);
                if (*endptr != 0) {
                    printf("Error: invalid parameter %s Must be <float>\n", argv[4]);
                    return 1;
                }
                double c = strtod(argv[5], &endptr);
                if (*endptr != 0) {
                    printf("Error: invalid parameter %s Must be <float>\n", argv[5]);
                    return 1;
                }
                t_tunction(eps, a, b, c);
        break;
    }
    
    return 0;
}
