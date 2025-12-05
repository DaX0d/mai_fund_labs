#include "task4.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    printf("=== Тестирование программы ===\n\n");
    
    // Тестирование flag_Ro
    printf("1. Тестирование flag_Ro (римские числа):\n");
    printf("   I -> %d (expected: 1)\n", flag_Ro("I"));
    printf("   V -> %d (expected: 5)\n", flag_Ro("V"));
    printf("   IV -> %d (expected: 4)\n", flag_Ro("IV"));
    printf("   IX -> %d (expected: 9)\n", flag_Ro("IX"));
    printf("   XL -> %d (expected: 40)\n", flag_Ro("XL"));
    printf("   XC -> %d (expected: 90)\n", flag_Ro("XC"));
    printf("   CD -> %d (expected: 400)\n", flag_Ro("CD"));
    printf("   CM -> %d (expected: 900)\n", flag_Ro("CM"));
    printf("   MMMCMXCIX -> %d (expected: 3999)\n", flag_Ro("MMMCMXCIX"));
    printf("   ABC -> %d (expected: -1, invalid)\n", flag_Ro("ABC"));
    printf("\n");
    
    // Тестирование flag_Cv и flag_CV
    printf("2. Тестирование flag_Cv и flag_CV (системы счисления):\n");
    printf("   flag_Cv('1010', 2) -> %d (expected: 10)\n", flag_Cv("1010", 2));
    printf("   flag_Cv('FF', 16) -> %d (expected: 255)\n", flag_Cv("ff", 16));
    printf("   flag_Cv('255', 10) -> %d (expected: 255)\n", flag_Cv("255", 10));
    printf("   flag_Cv('377', 8) -> %d (expected: 255)\n", flag_Cv("377", 8));
    printf("   flag_Cv('ZZ', 36) -> %d (expected: 1295)\n", flag_Cv("zz", 36));
    printf("   flag_Cv('GG', 16) -> %d (expected: -1, invalid)\n", flag_Cv("gg", 16));
    printf("   flag_CV('FF', 16) -> %d (expected: 255)\n", flag_CV("FF", 16));
    printf("   flag_CV('ABC', 16) -> %d (expected: 2748)\n", flag_CV("ABC", 16));
    printf("   flag_CV('XYZ', 36) -> %d (expected: 44027)\n", flag_CV("XYZ", 36));
    printf("\n");
    
    // Тестирование oversscanf
    printf("3. Тестирование oversscanf:\n");
    
    // Тест 1: Стандартные спецификаторы
    char str1[] = "Hello 123 45.67 World";
    char s1[20];
    int num1;
    double dbl1;
    
    int count1 = oversscanf(str1, "Hello %d %lf %s", &num1, &dbl1, s1);
    printf("   oversscanf('Hello 123 45.67 World', 'Hello %%d %%lf %%s') ->\n");
    printf("   Count: %d (expected: 3), num: %d, double: %.2f, str: %s\n", 
           count1, num1, dbl1, s1);
    
    // Тест 2: Спецификатор %Ro
    char str2[] = "Roman: XIV Arabic: 100";
    char label1[10], label2[10];
    int roman_num, arabic_num;
    
    int count2 = oversscanf(str2, "Roman: %Ro Arabic: %d", &roman_num, &arabic_num);
    printf("\n   oversscanf('Roman: XIV Arabic: 100', 'Roman: %%Ro Arabic: %%d') ->\n");
    printf("   Count: %d (expected: 2), Roman: %d, Arabic: %d\n", 
           count2, roman_num, arabic_num);
    
    // Тест 3: Спецификатор %Zr
    char str3[] = "Fib: 1010 Dec: 7";
    char label3[10], label4[10];
    unsigned int fib_num, dec_num;
    
    int count3 = oversscanf(str3, "Fib: %Zr Dec: %u", &fib_num, &dec_num);
    printf("\n   oversscanf('Fib: 1010 Dec: 7', 'Fib: %%Zr Dec: %%u') ->\n");
    printf("   Count: %d (expected: 2), Fib: %u, Dec: %u\n", 
           count3, fib_num, dec_num);
    
    printf("\n=== Тестирование завершено ===\n");

    return 0;
}
