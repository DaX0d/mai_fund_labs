#pragma once

#include <stdio.h>

int copy_text_from_file_to_file(FILE* file1, FILE* file2);

int justify_and_write(char** words, int wc, FILE* file2);
