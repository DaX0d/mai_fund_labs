#include <stdio.h>

#include "task2.h"

int main() {
    {
        char a[] = "12345";
        char b[] = "12435";
        int result = memcmp(a, b, 4);
        printf("%d\n", result);
    }

    {
        const char data[] = "abcdefg";
        const char* res = memchr(data, 'c', 7);
        printf("%c\n", *res);
    }

    {
        char src[] = "Hello";
        char dst[10];
        memcpy(dst, src, 6);
        printf("%s\n", dst);
    }

    {
        char buf[10] = "abcdefg";
        memset(&buf[2], 'X', 3);
        printf("%s (ожидаем abXXXfg)\n", buf);
    }

    {
        char d[20] = "Hello";
        const char* s = "World!";
        strncat(d, s, 3);
        printf("%s\n", d);
    }

    {
        const char* t = "abc\0def";
        char* p = strchr(t, 'b');
        printf("%ld\n", p ? (long)(p - t) : -1);
        char* p2 = strchr(t, '\0');
        printf("%ld\n", p2 ? (long)(p2 - t) : -1);
    }

    {
        printf("%d\n", strncmp("abc", "abd", 2));
        printf("%d\n", strncmp("abc", "abd", 3));
    }

    {
        char dst[10];
        strncpy(dst, "Hi", 5);
        printf("%s\n", dst);
    }

    {
        size_t pos = strcspn("abcdef", "de");
        printf("%zu\n", pos);
    }

    {
        printf("%zu\n", strlen("Hello"));
    }

    {
        const char* s1 = "xyz123";
        const char* s2 = "345";
        char* p = strpbrk(s1, s2);
        printf("%c\n", p ? *p : '?');
    }

    {
        const char* s = "abacada";
        char* p = strrchr(s, 'a');
        printf("%ld\n", p ? (long)(p - s) : -1);
    }

    {
        const char* h = "This is a simple test";
        const char* n = "simple";
        char* found = strstr(h, n);
        printf("%s\n", found ? found : "не найдено");
    }

    {
        char text[] = "one,two,three";
        char* token = strtok(text, ",");
        while (token) {
            printf("%s ", token);
            token = strtok(NULL, ",");
        }
        printf("\n");
    }
    return 0;
}
