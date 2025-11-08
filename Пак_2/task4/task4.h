#pragma once

#include <stdio.h>

int flag_Ro(char* num);
unsigned int flag_Zr(char* num);
int flag_Cv(char* num, int base);
int flag_CV(char* num, int base);
char* read_from_stream(FILE* stream);
unsigned int* fibonachi(int* n);
int oversscanf(const char* str, const char* format, ...);
int overfscanf(FILE* stream, const char* format, ...);
