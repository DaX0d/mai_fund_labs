#include "task_2.h"

int main() {
    int T;
    scanf("%d", &T);
    if (T < 1) {
        printf("This value needs to be more then 0\n");
        return 1;
    }
    int* array_of_n = (int*)calloc(T, sizeof(int));
    int tmp;
    for (int i = 0; i < T; ++i) {
        scanf("%d", &tmp);
        if (tmp < 1) {
            printf("This value needs to be more then 0\n");
            return 1;
        }
        array_of_n[i] = tmp;
    }
    int m = max(array_of_n, T);
    ULL_T* array_of_primes = (ULL_T*)calloc(m, sizeof(ULL_T));
    generate_array_of_primes(array_of_primes, m);
    printf("=============\n");
    for (int i = 0; i < T; ++i) {
        printf("%llu\n", prime_by_n(array_of_n[i] - 1, array_of_primes));
    }
    free(array_of_n);
    free(array_of_primes);
    return 0;
}
