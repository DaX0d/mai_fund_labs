#include "task2.h"

void* memchr(const void* str, int c, size_t n) {
    const unsigned char* ptr = (const unsigned char* )str;
    unsigned char uc = (unsigned char)c;

    for (size_t i = 0; i < n; ++i) {
        if (ptr[i] == uc) {
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

}

char* strncat(char* dest, const char* src, size_t n) {

}

char *strchr(const char *str, int c) {

}

int strncmp(const char* str1, const char* str2, size_t n) {

}

char* strncpy(char* dest, const char* src, size_t n) {

}

size_t strcspn(const char* str1, const char* str2) {

}

char* strerror(int errnum) {

}

size_t strlen(const char* str) {

}

char* strpbrk(const char* str1, const char* str2) {

}

char* strrchr(const char* str, int c) {

}

char* strstr(const char* haystack, const char* needle) {

}

char* strtok(char* str, const char* delim) {

}
