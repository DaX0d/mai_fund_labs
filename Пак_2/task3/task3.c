#include "task3.h"
#include <ctype.h>
#include <math.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

char* flag_Ro(int num){ 
    if (num >= 4000 || num <= -4000) return NULL;
    char* r1[] = {"","I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
    char* r2[] = {"","X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
    char* r3[] = {"","C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
    char* r4[] = {"","M", "MM", "MMM"};
    char* str = malloc(64 * sizeof(char));
    if (!str) return NULL;
    int i = 0, current;
    char* R;
    if (num< 0) {
        num *= -1;
        str[i++] = '-';
    }
    for(ssize_t j = 4; j >= 1; j--) {
        current = (num % (int)pow(10, j)) / (int)pow(10, j - 1);
        switch (j) {
            case 1:
                R = r1[current];
                for(size_t k = 0; k < strlen(R); k++){
                    str[i++] = R[k];
                }
                break;
            case 2:
                R = r2[current];
                for(size_t k = 0; k < strlen(R); k++){
                    str[i++] = R[k];
                }
                break;
            case 3:
                R = r3[current];
                for(size_t k = 0; k < strlen(R); k++){
                    str[i++] = R[k];
                }
                break;
            case 4:
                R = r4[current];
                for(size_t k = 0; k < strlen(R); k++){
                    str[i++] = R[k];
                }
                break;
        }
    }
    str[i] = '\0';
    return str;
}

char* flag_Zr(unsigned int num) {
    char* s1 = malloc(sizeof(char) * 100);
    char* s2 = malloc(sizeof(char) * 100);
    int* len = malloc(sizeof(int));
    unsigned int* fib = fibonachi(len);
    if (!s1 || !s2  || !len || !fib) {
        free(s1);
        free(s2);
        free(len);
        free(fib);
        return NULL;
    }
    if (num == 1) {
        s2[0] = '1';
        s2[1] = '1';
        s2[2] = '\0';
        free(s1);
        free(len);  
        free(fib); 
        return s2;
    }
    int k = 0, i, flag = 1;
    for (i = *len - 1; i >= 0; i--) {
        if (num >= fib[i]){
            s1[k++] = '1';
            num -= fib[i];
            s1[k++] = '0';
            i--;
            flag = 0;
        }
        else if (flag == 0){
            s1[k++] = '0';
        }
    }
    s1[k] = '\0'; 
    for(i = 0; i < k; i++) {
        s2[i] = s1[k - i - 1];
    }
    s2[k++] = '1';
    s2[k] = '\0';
    free(s1);
    free(len);
    free(fib);
    return s2;
}

char* flag_Cv(int num, int base) {
    if (base < 2 || base > 36) base = 10;
    char* digits = "0123456789abcdefghijklmnopqrstuvwxyz";
    char* tmp = malloc(sizeof(char) * 100);
    char* ans = malloc(sizeof(char) * 100);
    if (!tmp || !ans) {
        free(tmp);
        free(ans);
        return NULL;
    }
    if (num == 0) {
        strcpy(ans, "0");
        free(tmp);
        return ans;
    }
    int flag = 0;
    if (num < 0){
        flag = 1;
        num *= -1;
    }
    int i = 0, k = 0;
    while (num > 0) {
        tmp[i++] = digits[num % base];
        num /= base;
    }
    if (flag == 1) tmp[i++] = '-';
    i--;
    while (i >= 0) {
        ans[k++] = tmp[i--];
    }
    ans[k++] = '\0';
    free(tmp);
    return ans;
}

char* flag_CV(int num, int base) {
    char* ans = flag_Cv(num, base);
    if (!ans) return NULL;
    for(int i = 0; ans[i] != '\0'; i++) {
        ans[i] = toupper(ans[i]);
    }
    return ans;
}

int flag_to(char* num, int base) {
    int ans = 0;
    int len = strlen(num);
    char* dgts = "0123456789abcdefghijklmnopqrstuvwxyz";
    char* indx;
    int ind;
    if (base < 2 || base > 36) base = 10;
    int i;
    for(i = 0; i < len; i++) {
        if (num[i] >= 'A' && num[i] <= 'Z') return -1;
        indx = memchr(dgts, num[i], strlen(dgts));
        if (indx == NULL)return -1;
        ind = indx - dgts;
        if (ind >= base) return -1;
        ans += ind * pow(base, len - i - 1);
    }
    return ans;
}

int flag_TO(char* num, int base) {
    char* num1 = malloc(sizeof(char) * (strlen(num) + 10));
    if (!num1) return -1;
    for(int i = 0; i < strlen(num); i++) {
        if (num[i] >='a' && num[i] <='z') {
            free(num1);
            return -1;
        }
        num1[i] = tolower(num[i]);
    }
    num1[strlen(num)] = '\0';
    int res = flag_to(num1, base);
    free(num1);
    return res;
}

char* flag_mi(int num) {
    unsigned char* bytes = (unsigned char*)&num;
    char* ans = malloc(sizeof(char) * (4 * 8 + 4));
    if (!ans) return NULL;
    int k = 0;
    for(int i = 0; i < 4; i++) {
        for (int j = 7; j >= 0; j--) {
            ans[k++] = ((bytes[i] >> j) & 1) + '0';
        }
        if (i < 3) ans[k++] = ' ';
    }
    ans[k] = '\0';
    return ans;
}

char* flag_mu(unsigned int num) {
    unsigned char* bytes = (unsigned char*)&num;
    char* ans = malloc(sizeof(char) * (4 * 8 + 4));
    if (!ans) return NULL;
    int k = 0;
    for(int i = 0; i < 4; i++) {
        for (int j = 7; j >= 0; j--) {
            ans[k++] = ((bytes[i] >> j) & 1) + '0';
        }
        if (i < 3) ans[k++] = ' ';
    }
    ans[k] = '\0';
    return ans;
}

char* flag_md(double num) {
    unsigned char* bytes = (unsigned char*)&num;
    char* ans = malloc(sizeof(char) * (8 * 8 + 8)); 
    if (!ans) return NULL;
    int k = 0;
    for(int i = 0; i < 8; i++) {
        for (int j = 7; j >= 0; j--) {
            ans[k++] = ((bytes[i] >> j) & 1) + '0';
        }
        if (i < 7) ans[k++] = ' ';
    }
    ans[k] = '\0';
    return ans;
}

char* flag_mf(float num) {
    unsigned char* bytes = (unsigned char*)&num;
    char* ans = malloc(sizeof(char) * (4 * 8 + 4));
    if (!ans) return NULL;
    int k = 0;
    for(int i = 0; i < 4; i++) {
        for (int j = 7; j >= 0; j--) {
            ans[k++] = ((bytes[i] >> j) & 1) + '0';
        }
        if (i < 3) ans[k++] = ' ';
    }
    ans[k] = '\0';
    return ans;
}

unsigned int* fibonachi(int* n) {
    unsigned int f1 = 1, f2 = 1, k;
    unsigned int* ans = malloc(sizeof(unsigned int) * 100);
    if (!ans) return NULL;
    ans[0] = 1;
    ans[1] = 1;
    size_t i;
    for(i = 2; i < 100; i++) {
        if ((f1 + f2) < f1 || (f1 + f2) < f2){
            break;
        }
        ans[i] = (f1 + f2);
        k = f1;
        f1 = f2;
        f2 = k + f2;
    }
    ans[i] = 0;
    *n = i;
    return ans;
}


int oversprintf(char* str, const char* format, ...) {
    va_list args;
    va_start(args, format);
    size_t buf_size = 2048;
    char* buf = malloc(buf_size);
    if (!buf) {
        va_end(args);
        return -1;
    }
    int pos = 0;
    size_t flen = strlen(format);
    for (size_t i = 0; i < flen; i++) {
        if (pos >= buf_size - 512) {
            buf_size *= 2;
            char* new_buf = realloc(buf, buf_size);
            if (!new_buf) {
                free(buf);
                va_end(args);
                return -1;
            }
            buf = new_buf;
        }
        if (format[i] == '%') {
            if (strncmp(&format[i], "%Ro", 3) == 0) {
                int arg = va_arg(args, int);
                char* result = flag_Ro(arg);
                if (result) {
                    pos += snprintf(buf + pos, buf_size - pos, "%s", result);
                    free(result);
                }
                i += 2;
                continue;
            }
            if (strncmp(&format[i], "%Zr", 3) == 0) {
                unsigned int arg = va_arg(args, unsigned int);
                char* result = flag_Zr(arg);
                if (result) {
                    pos += snprintf(buf + pos, buf_size - pos, "%s", result);
                    free(result);
                }
                i += 2;
                continue;
            }
            if (strncmp(&format[i], "%Cv", 3) == 0) {
                int arg1 = va_arg(args, int);
                int arg2 = va_arg(args, int);
                char* result = flag_Cv(arg1, arg2);
                if (result) {
                    pos += snprintf(buf + pos, buf_size - pos, "%s", result);
                    free(result);
                }
                i += 2;
                continue;
            }
            if (strncmp(&format[i], "%CV", 3) == 0) {
                int arg1 = va_arg(args, int);
                int arg2 = va_arg(args, int);
                char* result = flag_CV(arg1, arg2);
                if (result) {
                    pos += snprintf(buf + pos, buf_size - pos, "%s", result);
                    free(result);
                }
                i += 2;
                continue;
            }
            if (strncmp(&format[i], "%to", 3) == 0) {
                char* arg1 = va_arg(args, char *);
                int arg2 = va_arg(args, int);
                int result = flag_to(arg1, arg2);
                pos += snprintf(buf + pos, buf_size - pos, "%d", result);
                i += 2;
                continue;
            }
            if (strncmp(&format[i], "%TO", 3) == 0) {
                char* arg1 = va_arg(args, char *);
                int arg2 = va_arg(args, int);
                int result = flag_TO(arg1, arg2);
                pos += snprintf(buf + pos, buf_size - pos, "%d", result);
                i += 2;
                continue;
            }
            if (strncmp(&format[i], "%mi", 3) == 0) {
                int arg = va_arg(args, int);
                char* result = flag_mi(arg);
                if (result) {
                    pos += snprintf(buf + pos, buf_size - pos, "%s", result);
                    free(result);
                }
                i += 2;
                continue;
            }
            if (strncmp(&format[i], "%mu", 3) == 0) {
                unsigned int arg = va_arg(args, unsigned int);
                char* result = flag_mu(arg);
                if (result) {
                    pos += snprintf(buf + pos, buf_size - pos, "%s", result);
                    free(result);
                }
                i += 2;
                continue;
            }
            if (strncmp(&format[i], "%md", 3) == 0) {
                double arg = va_arg(args, double);
                char* result = flag_md(arg);
                if (result) {
                    pos += snprintf(buf + pos, buf_size - pos, "%s", result);
                    free(result);
                }
                i += 2;
                continue;
            }
            if (strncmp(&format[i], "%mf", 3) == 0) {
                double arg = va_arg(args, double);
                char* result = flag_mf((float)arg);
                if (result) {
                    pos += snprintf(buf + pos, buf_size - pos, "%s", result);
                    free(result);
                }
                i += 2;
                continue;
            }

            char fmt_buf[64];
            int fmt_len = 0;
            fmt_buf[fmt_len++] = '%';
            
            for (size_t j = i + 1; j <= flen; j++) {
                char c = format[j];
                if (c == '\0' || strchr("diuoxXfFeEgGaAcspn%", c) != NULL) {
                    if (c != '\0') {
                        fmt_buf[fmt_len++] = c;
                    }
                    fmt_buf[fmt_len] = '\0';
                    
                    va_list args_copy;
                    va_copy(args_copy, args);
                    char temp[512];
                    int temp_len = vsnprintf(temp, sizeof(temp), fmt_buf, args_copy);
                    va_end(args_copy);
                    
                    if (temp_len > 0) {
                        if (pos + temp_len >= buf_size - 1) {
                            buf_size = pos + temp_len + 1;
                            char* new_buf = realloc(buf, buf_size);
                            if (!new_buf) {
                                free(buf);
                                va_end(args);
                                return -1;
                            }
                            buf = new_buf;
                        }
                        strcpy(buf + pos, temp);
                        pos += temp_len;
                        
                        if (strchr("diuoxXp", c)) {
                            va_arg(args, int);
                        } else if (strchr("fFeEgGaA", c)) {
                            va_arg(args, double);
                        } else if (c == 's') {
                            va_arg(args, char*);
                        } else if (c == 'c') {
                            va_arg(args, int);
                        } else if (c == 'n') {
                            va_arg(args, int*);
                        }
                    }
                    
                    i = j;
                    break;
                }
                fmt_buf[fmt_len++] = c;
            }

        } else {
            buf[pos++] = format[i];
        }
    }
    buf[pos] = '\0';
    strcpy(str, buf);
    free(buf);
    va_end(args);
    return pos;
}

int overfprintf(FILE* stream, const char* format, ...) {
    va_list args;
    va_start(args, format);
    size_t buf_size = 2048;
    char* buf = malloc(buf_size);
    if (!buf) {
        va_end(args);
        return -1;
    }
    int pos = 0;
    size_t flen = strlen(format);
    for (size_t i = 0; i < flen; i++) {
        if (pos >= buf_size - 512) {
            buf_size *= 2;
            char* new_buf = realloc(buf, buf_size);
            if (!new_buf) {
                free(buf);
                va_end(args);
                return -1;
            }
            buf = new_buf;
        }
        if (format[i] == '%') {
            if (strncmp(&format[i], "%Ro", 3) == 0) {
                int arg = va_arg(args, int);
                char* result = flag_Ro(arg);
                if (result) {
                    pos += snprintf(buf + pos, buf_size - pos, "%s", result);
                    free(result);
                }
                i += 2;
                continue;
            }
            if (strncmp(&format[i], "%Zr", 3) == 0) {
                unsigned int arg = va_arg(args, unsigned int);
                char* result = flag_Zr(arg);
                if (result) {
                    pos += snprintf(buf + pos, buf_size - pos, "%s", result);
                    free(result);
                }
                i += 2;
                continue;
            }
            if (strncmp(&format[i], "%Cv", 3) == 0) {
                int arg1 = va_arg(args, int);
                int arg2 = va_arg(args, int);
                char* result = flag_Cv(arg1, arg2);
                if (result) {
                    pos += snprintf(buf + pos, buf_size - pos, "%s", result);
                    free(result);
                }
                i += 2;
                continue;
            }
            if (strncmp(&format[i], "%CV", 3) == 0) {
                int arg1 = va_arg(args, int);
                int arg2 = va_arg(args, int);
                char* result = flag_CV(arg1, arg2);
                if (result) {
                    pos += snprintf(buf + pos, buf_size - pos, "%s", result);
                    free(result);
                }
                i += 2;
                continue;
            }
            if (strncmp(&format[i], "%to", 3) == 0) {
                char* arg1 = va_arg(args, char *);
                int arg2 = va_arg(args, int);
                int result = flag_to(arg1, arg2);
                pos += snprintf(buf + pos, buf_size - pos, "%d", result);
                i += 2;
                continue;
            }
            if (strncmp(&format[i], "%TO", 3) == 0) {
                char* arg1 = va_arg(args, char *);
                int arg2 = va_arg(args, int);
                int result = flag_TO(arg1, arg2);
                pos += snprintf(buf + pos, buf_size - pos, "%d", result);
                i += 2;
                continue;
            }
            if (strncmp(&format[i], "%mi", 3) == 0) {
                int arg = va_arg(args, int);
                char* result = flag_mi(arg);
                if (result) {
                    pos += snprintf(buf + pos, buf_size - pos, "%s", result);
                    free(result);
                }
                i += 2;
                continue;
            }
            if (strncmp(&format[i], "%mu", 3) == 0) {
                unsigned int arg = va_arg(args, unsigned int);
                char* result = flag_mu(arg);
                if (result) {
                    pos += snprintf(buf + pos, buf_size - pos, "%s", result);
                    free(result);
                }
                i += 2;
                continue;
            }
            if (strncmp(&format[i], "%md", 3) == 0) {
                double arg = va_arg(args, double);
                char* result = flag_md(arg);
                if (result) {
                    pos += snprintf(buf + pos, buf_size - pos, "%s", result);
                    free(result);
                }
                i += 2;
                continue;
            }
            if (strncmp(&format[i], "%mf", 3) == 0) {
                double arg = va_arg(args, double);
                char* result = flag_mf((float)arg);
                if (result) {
                    pos += snprintf(buf + pos, buf_size - pos, "%s", result);
                    free(result);
                }
                i += 2;
                continue;
            }
            char fmt_buf[64];
            int fmt_len = 0;
            fmt_buf[fmt_len++] = '%';
            
            for (size_t j = i + 1; j <= flen; j++) {
                char c = format[j];
                if (c == '\0' || strchr("diuoxXfFeEgGaAcspn%", c) != NULL) {
                    if (c != '\0') {
                        fmt_buf[fmt_len++] = c;
                    }
                    fmt_buf[fmt_len] = '\0';
                    
                    va_list args_copy;
                    va_copy(args_copy, args);
                    char temp[512];
                    int temp_len = vsnprintf(temp, sizeof(temp), fmt_buf, args_copy);
                    va_end(args_copy);
                    
                    if (temp_len > 0) {
                        if (pos + temp_len >= buf_size - 1) {
                            buf_size = pos + temp_len + 1;
                            char* new_buf = realloc(buf, buf_size);
                            if (!new_buf) {
                                free(buf);
                                va_end(args);
                                return -1;
                            }
                            buf = new_buf;
                        }
                        strcpy(buf + pos, temp);
                        pos += temp_len;
                        
                        if (strchr("diuoxXp", c)) {
                            va_arg(args, int);
                        } else if (strchr("fFeEgGaA", c)) {
                            va_arg(args, double);
                        } else if (c == 's') {
                            va_arg(args, char*);
                        } else if (c == 'c') {
                            va_arg(args, int);
                        } else if (c == 'n') {
                            va_arg(args, int*);
                        }
                    }
                    
                    i = j;
                    break;
                }
                fmt_buf[fmt_len++] = c;
            }
        } else {
            buf[pos++] = format[i];
        }
    }
    buf[pos] = '\0';
    fputs(buf, stream);
    free(buf);
    va_end(args);
    return pos;
}
