#include "task_3.h"

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: %s -<flag>(/<flag>) <parameters>\n", argv[0]);
        return 1;
    }

    char* flag = argv[1];
    if (flag[0] != '-' || flag[0] != '/') {
        printf("Usage: %s -<flag>(/<flag>) <parameters>\n", argv[0]);
        return 1;
    }

    switch (flag[1]) {
        case 'q':
            if (argc != 6) {
                printf("Usage: %s -q <eps> <float> <float> <float>\n");
                return 1;
            }
            // q_function();
        break;
        case 'm':
            if (argc != 4) {
                printf("Usage: %s -m <int> <int>\n", argv[0]);
                return 1;
            }
            {
                char* endptr;
                long long first = strtoll(argv[2], &endptr, 10);
                long long second = strtoll(argv[3], &endptr, 10);
                return m_function(first, second);
            }
        break;
        case 't':
            if (argc != 6) {
                printf("Usage: %s -q <eps> <float> <float> <float>\n");
                return 1;
            }
        break;
    }
    return 0;
}
