#include "task5.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define WIDTH 80

void justify_and_write(char **words, int wc, FILE *file2) {
    if (wc == 0) return;

    // Если всего одно слово, просто выводим его
    if (wc == 1) {
        fprintf(file2, "%s\n", words[0]);
        return;
    }

    int letters = 0;
    for (int i = 0; i < wc; i++)
        letters += strlen(words[i]);

    int gaps = wc - 1;
    int total_spaces = WIDTH - letters;
    
    // Если строка уже длиннее или равна WIDTH, выводим без форматирования
    if (total_spaces <= 0) {
        for (int i = 0; i < wc; i++) {
            fprintf(file2, "%s", words[i]);
            if (i != wc - 1) fputc(' ', file2);
        }
        fputc('\n', file2);
        return;
    }

    // Распределяем пробелы
    int base = total_spaces / gaps;
    int extra = total_spaces % gaps;

    for (int i = 0; i < wc - 1; i++) {
        fprintf(file2, "%s", words[i]);
        for (int s = 0; s < base; s++)
            fputc(' ', file2);
        if (extra--) fputc(' ', file2);
    }
    fprintf(file2, "%s\n", words[wc - 1]);
}

int copy_text_from_file_to_file(FILE *in, FILE *out) {
    char raw[2048];

    while (fgets(raw, sizeof(raw), in)) {
        int L = strlen(raw);
        if (L > 0 && raw[L-1] == '\n') raw[L-1] = 0;

        char *p = raw;
        char *words[256];
        int wc = 0;

        while (*p) {
            while (*p == ' ') p++;
            if (!*p) break;

            char *start = p;
            while (*p && *p != ' ') p++;

            int wlen = p - start;
            char *word = malloc(wlen + 1);
            strncpy(word, start, wlen);
            word[wlen] = 0;

            // Если одно слово длиннее WIDTH, обрабатываем его отдельно
            if (wlen >= WIDTH) {
                // Сначала выводим накопленные слова, если они есть
                if (wc > 0) {
                    justify_and_write(words, wc, out);
                    for (int i = 0; i < wc; i++)
                        free(words[i]);
                    wc = 0;
                }
                // Выводим длинное слово как отдельную строку
                fprintf(out, "%s\n", word);
                free(word);
                continue;
            }

            // Расчет текущей длины строки
            int letters = 0;
            for (int i = 0; i < wc; i++)
                letters += strlen(words[i]);
            
            // Текущая длина: буквы + пробелы
            int current_len = letters + (wc > 0 ? wc - 1 : 0);
            
            // Новая длина с добавлением текущего слова
            int new_len = current_len + (wc > 0 ? 1 : 0) + wlen;
            
            if (wc > 0 && new_len > WIDTH) {
                // Если не помещается, выводим текущую строку
                justify_and_write(words, wc, out);
                for (int i = 0; i < wc; i++)
                    free(words[i]);
                wc = 0;
            }

            // Добавляем слово
            words[wc++] = word;
        }

        // Выводим оставшиеся слова
        if (wc > 0) {
            justify_and_write(words, wc, out);
            for (int i = 0; i < wc; i++)
                free(words[i]);
        }
    }

    return 0;
}
