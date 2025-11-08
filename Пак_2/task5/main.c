#include "task5.h"

#include <stdio.h>
#include <stdlib.h>
#include "string.h"


int main() {
    char in[256], out[256];
    printf("Введите путь к входному файлу: ");
    if (!fgets(in, sizeof(in), stdin)) {
        printf("Не удалось считать путь входного файла\n");
        return 1;
    }
    in[strcspn(in, "\n")] = '\0';

    printf("Введите путь к выходному файлу: ");
    if (!fgets(out, sizeof(out), stdin)) {
        printf("Не удалось считать путь выходного файла\n");
        return 1;
    }
    out[strcspn(out, "\n")] = '\0';

    if (!strcmp(in, out)) {
        printf("Входной и выходной файлы должны быть разными\n");
        return 1;
    }

    FILE* in_file = NULL, * out_file = NULL;
    if (!(in_file = fopen(in, "r"))) {
        printf("Не удается открыть входной файл\n");
        return 2;
    }
    if (!(out_file = fopen(out, "w"))) {
        printf("Не удается открыть выходной файл\n");
        fclose(in_file);
        return 2;
    }

    return copy_text_from_file_to_file(in_file, out_file);
}
