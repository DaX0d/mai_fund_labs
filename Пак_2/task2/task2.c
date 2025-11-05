#include "task2.h"

void* memchr(const void* str, int c, size_t n) {
    const unsigned char* ptr = (const unsigned char* )str;
    unsigned char ch = (unsigned char)c;

    for (size_t i = 0; i < n; ++i) {
        if (ptr[i] == ch) {
            return (void*)(ptr + i);
        }
    }
    return NULL;
}

int memcmp(const void* str1, const void* str2, size_t n) {
    const unsigned char* ptr1 = (const unsigned char*)str1;
    const unsigned char* ptr2 = (const unsigned char*)str2;

    for (size_t i = 0; i < n; ++i) {
        if (ptr1[i] != ptr2[i]) {
            return (ptr1[i] < ptr2[i]) ? -1 : 1;
        }
    }
    return 0;
}

void* memcpy(void* dest, const void* src, size_t n) {
    unsigned char* dptr = (unsigned char*)dest;
    const unsigned char* sptr = (const unsigned char*)src;
    
    for (size_t i = 0; i < n; ++i) {
        dptr[i] = sptr[i];
    }
    return dest;
}

void* memset(void* str, int c, size_t n) {
    unsigned char* ptr = (unsigned char*)str;
    unsigned char ch = (unsigned char)c;

    for (size_t i = 0; i < n; ++i) {
        ptr[i] = ch;
    }
    return str;
}

char* strncat(char* dest, const char* src, size_t n) {
    char* dptr = dest;

    while (*dptr) ++dptr;

    size_t i = 0;
    while (i < n && src[i]) {
        dptr[i] = src[i];
        ++i;
    }
    dptr[i] = '\0';

    return dest;
}

char* strchr(const char* str, int c) {
    unsigned char ch = (unsigned char)c;
    const unsigned char* sptr = (const unsigned char*)str;

    while (*sptr) {
        if (*sptr == ch) return (char*)sptr;
        ++sptr;
    }
    if (ch == 0) return (char*)sptr;

    return NULL;
}

int strncmp(const char* str1, const char* str2, size_t n) {
    for (size_t i = 0; i < n; ++i) {
        unsigned char ch1 = (unsigned char)str1[i];
        unsigned char ch2 = (unsigned char)str2[i];

        if (ch1 != ch2) {
            return (ch1 < ch2) ? -1 : 1;
        }
        if (ch1 == '\0') {
            return 0;
        }
    }
    return 0;
}

char* strncpy(char* dest, const char* src, size_t n) {
    size_t i = 0;
    for (; i < n && src[i] != '\0'; ++i) {
        dest[i] = src[i];
    }
    for (; i < n; ++i) {
        dest[i] = '\0';
    }
    return dest;
}

size_t strcspn(const char* str1, const char* str2) {
    size_t count = 0;

    for (const char* ptr1 = str1; *ptr1 != '\0'; ++ptr1) {
        const char* ptr2;
        for (ptr2 = str2; *ptr2 != '\0'; ++ptr2) {
            if (*ptr1 == *ptr2) {
                return count;
            }
        }
        ++count;
    }

    return count;
}

size_t strlen(const char* str) {
    const char* ptr = str;
    while (*ptr) ++ptr;
    return (size_t)(ptr - str);
}

char* strpbrk(const char* str1, const char* str2) {
    for (const char* ptr1 = str1; *ptr1 != '\0'; ++ptr1) {
        for (const char* ptr2 = str2; *ptr2 != '\0'; ++ptr2) {
            if (*ptr1 == *ptr2) {
                return (char*)ptr1;
            }
        }
    }
    return NULL;
}

char* strrchr(const char* str, int c) {
    const char* last = NULL;
    unsigned char ch = (unsigned char)c;

    while (*str) {
        if (*str == ch)
            last = str;
        ++str;
    }

    if (ch == '\0')
        return (char*)str;  // указывает на терминатор строки

    return (char*)last;
}

char* strstr(const char* haystack, const char* needle) {
    if (*needle == '\0')
        return (char*)haystack;

    for (const char* hptr = haystack; *hptr != '\0'; ++hptr) {
        const char* h_iter = hptr;
        const char* n_iter = needle;

        while (*n_iter != '\0' && *h_iter == *n_iter) {
            ++h_iter;
            ++n_iter;
        }

        if (*n_iter == '\0')
            return (char*)hptr;
    }

    return NULL;
}

char* strtok(char* str, const char* delim) {
    static char* next = NULL;

    if (str != NULL)
        next = str;

    if (next == NULL)
        return NULL;

    char* start = next;
    while (*start) {
        const char* d;
        int is_delim = 0;
        for (d = delim; *d != '\0'; ++d) {
            if (*start == *d) {
                is_delim = 1;
                break;
            }
        }
        if (!is_delim)
            break;
        ++start;
    }

    if (*start == '\0') {
        next = NULL;
        return NULL;
    }

    char* end = start;
    while (*end) {
        const char* d;
        for (d = delim; *d != '\0'; ++d) {
            if (*end == *d) {
                *end = '\0';
                next = end + 1;
                return start;
            }
        }
        ++end;
    }

    next = NULL;
    return start;
}
