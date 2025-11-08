#pragma once

#include <stdio.h>
#include <stdarg.h>

unsigned int* fibonachi(int* n);

int overfprintf(FILE* stream, const char* format, ...);
int oversprintf(char* str, const char* format, ...);
