#include "task4.h"

#include <math.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>


char* read_from_stream(FILE* stream) {
    int cap = 128, len = 0, c;
    char* buf = malloc(cap);
    if (!buf) return NULL;
    while ((c = fgetc(stream)) != EOF && isspace(c));
    if (c == EOF) {
        free(buf);
        return NULL;
    }
    buf[len++] = c;
    while ((c = fgetc(stream)) != EOF && !isspace(c)) {
        if (len >= cap - 1) {
            cap *= 2;
            char* tmp = realloc(buf, cap);
            if (!tmp) { 
                free(buf); 
                return NULL;
            }
            buf = tmp;
        }
        buf[len++] = c;
    }
    if (c != EOF) ungetc(c, stream);
    buf[len] = '\0';
    return buf;
}

unsigned int* fibonachi(int* len) {
    unsigned int f1 = 1, f2 = 1, k;
    unsigned int* ans = (unsigned int*)malloc(sizeof(unsigned int) * 100);
    if (!ans) return NULL;
    ans[0] = 1;
    ans[1] = 1;
    size_t i;
    for (i = 2; i < 100; i++) {
        if ((f1 + f2) < f1 || (f1 + f2) < f2){
            break;
        }
        ans[i] = (f1 + f2);
        k = f1;
        f1 = f2;
        f2 = k + f2;
    }
    ans[i] = 0;
    *len = i;
    return ans;
}


int flag_Ro(char* num) { 
    if (!num || !*num) return -1;
    int res = 0, i = 0;
    int len = strlen(num);
    if (num[0] == '-') return -1;;
    while (i != len) {
        switch (num[i]){
        case 'I': {
            if (num[i + 1] && num[i + 1] == 'X') {
                res += 9;
                i += 2;
            } else if (num[i + 1] && num[i + 1] == 'V') {
                res += 4;
                i += 2;
            } else {
                res += 1;
                i++;
            }
        } break;
        case 'V': {
            res += 5;
            i++;
        } break;
        case 'X': {
            if (num[i + 1] && num[i + 1] == 'C') {
                res += 90;
                i += 2;
            } else if (num[i + 1] && num[i + 1] == 'L') {
                res += 40;
                i += 2;
            } else{
                res += 10;
                i++;
            }
        } break;
        case 'L': {
            res += 50;
            i++;
        } break;
        case 'C': {
            if (num[i + 1] && num[i + 1] == 'M') {
                res += 900;
                i += 2;
            } else if (num[i + 1] && num[i + 1] == 'D') {
                res += 400;
                i += 2;
            } else {
                res += 100;
                i++;
            }
        } break;
        case 'D': {
            res += 500;
            i++;
        } break;
        case 'M': {
            res += 1000;
            i++;
        } break;
        default: return -1;
        }
    }
    if (res > 4000) {
        return -1;
    }
    return res;
}

unsigned int flag_Zr(char* num) {
    if (!num || strlen(num) < 2) return 0;
    int len = strlen(num);
    for (int i = 0; i < len; i++) {
        if (num[i] != '1' && num[i] != '0') return 0;
    }
    unsigned int res = 0;
    int len_fib; 
    int i = 0, k = 0;
    unsigned int* fib = fibonachi(&len_fib);
    if (!fib) return 0;
    while(i < len_fib && num[k + 1] !='\0') {
        if (num[k] == '1'){
            res += fib[i];
            i++;
        }
        i++;
        k++;
    }
    free(fib);
    return res;
}

int flag_Cv(char* num, int base) {
    if (!num || !*num) return -1;
    long long ans = 0;
    int len = strlen(num);
    long long test;
    char* digits = "0123456789abcdefghijklmnopqrstuvwxyz";
    char* index;
    int ind;
    if (base < 2 || base > 36) base = 10;
    int i;
    for (i = 0; i < len; i++) {
        index = memchr(digits, num[i], strlen(digits));
        if (index == NULL)return -1;
        ind = index - digits;
        if (ind >= base) return -1;
        test = ind * pow(base, len - i - 1);
        if ((ans + test) > INT_MAX) return -1;
        ans += test;
    }
    return (int)ans;
}

int flag_CV(char* num, int base){
    if (!num || !*num) return -1;
    int len = strlen(num);
    char* num1 = malloc(sizeof(char) * (strlen(num) + 10));
    if (!num1) return -1;
    for (int i = 0; i < len; i++) {
        if (num[i] >= 'A' && num[i] <= 'Z') {
            num1[i] = tolower(num[i]);
        } else if (num[i] >= '0' && num[i] <= '9') {
            num1[i] = num[i];
        } else {
            free(num1);
            return -1;
    }
    }
    num1[len] = '\0';
    int ans = flag_Cv(num1, base);
    free(num1);
    return ans;
}


int oversscanf(const char* str, const char* format, ...){
    va_list args;
    va_start(args, format);
    int pos = 0, count = 0;
    size_t flen = strlen(format);
    char* dynamic_str = NULL;
    int dynamic_pos = 0;
    
    for (size_t i = 0; i < flen; i++) {
        if (format[i] != '%'){
            if (isspace(format[i])) {
                while (str[pos] && isspace(str[pos])) pos++;
            } else {
                if (str[pos] != format[i]) {
                    va_end(args);
                    return count;
                }
                pos++;
            }
            continue;
        }
        if (format[i] == '%') {
            if (format[i + 1] == '%') {
                if (str[pos] != '%') {
                    va_end(args);
                    return count;
                }
                pos++;
                i++;
                continue;
            }
            if (strncmp(&format[i], "%Ro", 3) == 0) {
                int* arg = va_arg(args, int*);
                char* result = malloc(sizeof(char) * (strlen(str) + 1));
                if (!result){
                    va_end(args);
                    return count;
                }
                if (sscanf(&str[pos], "%s", result) == 1) {
                    pos += strlen(result);
                    int res = flag_Ro(result);
                    free(result);
                    if (res == -1) {
                        va_end(args);
                        return -1;
                    }
                    *arg = res;
                    count++;
                } else {
                    free(result);
                }
                i += 2;
                continue;
            }
            if (strncmp(&format[i], "%Zr", 3) == 0) {
                unsigned int* arg = va_arg(args, unsigned int*);
                char* result = malloc(sizeof(char) * (strlen(str) + 1));
                if (!result){
                    va_end(args);
                    return count;
                }
                if (sscanf(&str[pos], "%s", result) == 1) {
                    pos += strlen(result);
                    unsigned int res = flag_Zr(result);
                    free(result);
                    if (res == 0) {
                        va_end(args);
                        return -1;
                    }
                    *arg = res;
                    count++;
                } else {
                    free(result);
                }
                i += 2;
                continue;
            }
            if (strncmp(&format[i], "%Cv", 3) == 0) {
                int* arg = va_arg(args, int*);
                int base = va_arg(args, int);
                char* result = malloc(sizeof(char) * (strlen(str) + 1));
                if (!result) {
                    va_end(args);
                    return count;
                }
                if (sscanf(&str[pos], "%s", result) == 1) {
                    pos += strlen(result);
                    int res = flag_Cv(result, base);
                    free(result);
                    if (res == -1){
                        va_end(args);
                        return -1;
                    }
                    *arg = res;
                    count++;
                } else {
                    free(result);
                }
                i += 2;
                continue;
            }
            
            if (strncmp(&format[i], "%CV", 3) == 0) {
                int* arg = va_arg(args, int*);
                int base = va_arg(args, int);
                char* result = malloc(sizeof(char) * (strlen(str) + 1));
                if (!result) {
                    va_end(args);
                    return count;
                }
                if (sscanf(&str[pos], "%s", result) == 1) {
                    pos += strlen(result);
                    int res = flag_CV(result, base);
                    free(result);
                    if (res == -1) {
                        va_end(args);
                        return -1;
                    }
                    *arg = res;
                    count++;
                } else {
                    free(result);
                }
                i += 2;
                continue;
            }
            
            char fmt[16] = {0};
            int fmt_len = 0;
            
            // Копируем спецификатор (например, "%d")
            fmt[fmt_len++] = '%';
            
            // Пропускаем возможные модификаторы (h, l, L и т.д.)
            i++;
            while (format[i] && !strchr("diuoxXfFeEgGaAscpn%", format[i])) {
                if (fmt_len < 14) fmt[fmt_len++] = format[i];
                i++;
            }
            
            // Добавляем тип спецификатора
            if (format[i]) {
                fmt[fmt_len++] = format[i];
                fmt[fmt_len] = '\0';
            } else {
                va_end(args);
                return count;
            }
            
            // Используем vsscanf для стандартных спецификаторов
            int chars_read = 0;
            va_list args_copy;
            va_copy(args_copy, args);
            
            if (strchr("diuoxXfFeEgGaAscp", format[i])) {
                // Для обычных спецификаторов
                int result = vsscanf(&str[pos], fmt, args_copy);
                if (result == 1) {
                    count++;
                    // Определяем сколько символов было прочитано
                    int temp_pos = pos;
                    while (str[temp_pos] && !isspace(str[temp_pos])) temp_pos++;
                    pos = temp_pos;
                    
                    // Пропускаем соответствующий аргумент
                    switch (format[i]) {
                        case 'd': case 'i': case 'o': case 'x': case 'X':
                        case 'u': va_arg(args, int*); break;
                        case 'f': case 'e': case 'g': case 'F': case 'E': case 'G': case 'a': case 'A':
                            va_arg(args, double*); break;
                        case 's': case 'c':
                            va_arg(args, char*); break;
                        case 'p':
                            va_arg(args, void**); break;
                    }
                }
            } else if (format[i] == 'n') {
                // Для %n
                int* n_ptr = va_arg(args, int*);
                *n_ptr = pos;
                // Не увеличиваем count, так как %n не считается за успешное преобразование
            }
            
            va_end(args_copy);
        
        }
    }
    va_end(args);
    return count;
}


int overfscanf(FILE* stream, const char* format, ...){
    va_list args;
    va_start(args, format);
    int count = 0;
    int total_read = 0;
    size_t flen = strlen(format);
    
    for (size_t i = 0; i < flen; i++) {
        if (format[i] != '%'){
            if (isspace(format[i])) {
                int c;
                while ((c = fgetc(stream)) != EOF && isspace(c)) {
                    total_read++;
                }
                if (c != EOF) ungetc(c, stream);
            } else {
                int c = fgetc(stream);
                if (c == EOF || c != format[i]) {
                    if (c != EOF) ungetc(c, stream);
                    va_end(args);
                    return count;
                }
                total_read++;
            }
            continue;
        }
        
        if (format[i] == '%'){
            if (format[i+1] == '%') {
                int c = fgetc(stream);
                if (c != '%'){
                    if (c != EOF) ungetc(c, stream);
                    va_end(args);
                    return count;
                }
                total_read++;
                i++;
                continue;
            }
            if (strncmp(&format[i], "%Ro", 3) == 0) {
                int* arg = va_arg(args, int*);
                char* result = read_from_stream(stream);
                if (result) {
                    total_read += strlen(result);
                    int res = flag_Ro(result);
                    free(result);
                    if (res == -1) {
                        va_end(args);
                        return -1;
                    }
                    *arg = res;
                    count++;
                }
                i += 2;
                continue;
            }
            if (strncmp(&format[i], "%Zr", 3) == 0) {
                unsigned int* arg = va_arg(args, unsigned int*);
                char* result = read_from_stream(stream);
                if (result) {
                    total_read += strlen(result);
                    unsigned int res = flag_Zr(result);
                    free(result);
                    if (res == 0) {
                        va_end(args);
                        return -1;
                    }
                    *arg = res;
                    count++;
                }
                i += 2;
                continue;
            }
            if (strncmp(&format[i], "%Cv", 3) == 0) {
                int* arg = va_arg(args, int*);
                int base = va_arg(args, int);
                char* result = read_from_stream(stream);
                if (result) {
                    total_read += strlen(result);
                    int res = flag_Cv(result, base);
                    free(result);
                    if (res == -1) {
                        va_end(args);
                        return -1;
                    }
                    *arg = res;
                    count++;
                }
                i += 2;
                continue;
            }
            if (strncmp(&format[i], "%CV", 3) == 0) {
                int* arg = va_arg(args, int*);
                int base = va_arg(args, int);
                char* result = read_from_stream(stream);
                if (result) {
                    total_read += strlen(result);
                    int res = flag_CV(result, base);
                    free(result);
                    if (res == -1) {
                        va_end(args);
                        return -1;
                    }
                    *arg = res;
                    count++;
                }
                i += 2;
                continue;
            }
            
            long pos_before = ftell(stream);
            int items_read = 0;
            
            // Используем switch только для определения формата
            char fmt[4] = {0};
            switch (format[i + 1]) {
                case 'd': case 'i': case 'u': case 'x': case 'X': case 'o':
                case 'f': case 'e': case 'g':
                case 's':
                case 'c':
                case 'p': {
                    snprintf(fmt, sizeof(fmt), "%%%c", format[i + 1]);
                    if (format[i + 1] == 'f' || format[i + 1] == 'e' || format[i + 1] == 'g') {
                        items_read = vfscanf(stream, "%lf", args);
                    } else {
                        items_read = vfscanf(stream, fmt, args);
                    }
                    break;
                }
                case 'n': {
                    // Обработка %n
                    int* arg = va_arg(args, int*);
                    *arg = total_read;
                    items_read = 1; // Успешно обработано
                    break;
                }
                default:
                    i++; // Пропускаем неизвестный спецификатор
                    continue;
            }
            
            if (items_read == 1) {
                long pos_after = ftell(stream);
                if (pos_before != -1L && pos_after != -1L) {
                    total_read += (int)(pos_after - pos_before);
                }
                
                // Продвигаем args на один аргумент (кроме %n)
                if (format[i + 1] != 'n') {
                    switch (format[i + 1]) {
                        case 'd': case 'i': case 'u': case 'x': case 'X': case 'o': {
                            int* arg = va_arg(args, int*);
                            (void)arg;
                            break;
                        }
                        case 'f': case 'e': case 'g': {
                            double* arg = va_arg(args, double*);
                            (void)arg;
                            break;
                        }
                        case 's': {
                            char* arg = va_arg(args, char*);
                            (void)arg;
                            break;
                        }
                        case 'c': {
                            char* arg = va_arg(args, char*);
                            (void)arg;
                            break;
                        }
                        case 'p': {
                            void** arg = va_arg(args, void**);
                            (void)arg;
                            break;
                        }
                    }
                }
                
                count++;
                i++; // Пропускаем спецификатор формата
            } else {
                // Не удалось прочитать
                va_end(args);
                return count;
            }
        }
    }
    
    va_end(args);
    return count;
}
