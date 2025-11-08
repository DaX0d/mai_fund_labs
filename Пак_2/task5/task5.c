#include "task5.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


int justify_and_write(char** words, int wc, FILE* file2) {
    if (wc == 0) return 0;

    int letters = 0;
    for (int i = 0; i < wc; ++i)
        letters += strlen(words[i]);

    if (letters >= 80) {
        for (int i = 0; i < wc; i++) {
            fprintf(file2, "%s", words[i]);
            if (i != wc - 1) fputc(' ', file2);
        }
        fputc('\n', file2);
        return 0;
    }

    int gaps = wc - 1;

    if (gaps == 0) {
        fprintf(file2, "%s\n", words[0]);
        return 0;
    }

    int total_spaces = 80 - letters;
    int base = total_spaces / gaps;
    int extra = total_spaces % gaps;

    for (int i = 0; i < wc - 1; ++i) {
        fprintf(file2, "%s", words[i]);
        for (int s = 0; s < base; ++s)
            fputc(' ', file2);
        if (extra--) fputc(' ', file2);
    }
    fprintf(file2, "%s\n", words[wc - 1]);

    return 0;
}


int copy_text_from_file_to_file(FILE* file1, FILE* file2) {
    char raw[1024];

    while (fgets(raw, sizeof(raw), file1)) {
        size_t len = strlen(raw);
        if (len > 0 && raw[len - 1] == '\n') raw[len - 1] = '\0';

        char* p = raw;

        char* words[256];
        int wc = 0;

        while (*p) {
            while (*p == ' ') ++p;
            if (!*p) break;

            char* start = p;
            while (*p && *p != ' ') ++p;
            int wlen = p - start;

            char* w = malloc(wlen + 1);
            strncpy(w, start, wlen);
            w[wlen] = '\0';

            int letters = 0;
            for (int i = 0; i < wc; ++i)
                letters += strlen(words[i]);
            int new_letters = letters + strlen(w);

            if (wc == 0) {
                words[wc++] = w;
            }
            else {
                if (new_letters + wc > 80) {
                    justify_and_write(words, wc, file2);

                    for (int i = 0; i < wc; ++i) free(words[i]);
                    wc = 0;

                    words[wc++] = w;
                } else {
                    words[wc++] = w;
                }
            }
        }

        if (wc > 0) {
            justify_and_write(words, wc, file2);
            for (int i = 0; i < wc; ++i) free(words[i]);
        }
    }

    return 0;
}