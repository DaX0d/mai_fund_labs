#include <stdio.h>
#include <stdint.h>

#include "task3.h"

int main() {
    char buffer[1024];

    overfprintf(stdout, "Standard formats: int=%d, float=%f, string=%s\n", 42, 3.14, "hello");
    oversprintf(buffer, "Buffer test: int=%d, string=%s", -7, "world");
    overfprintf(stdout, "%s\n", buffer);

    overfprintf(stdout, "Roman: 1999 -> %Ro\n", 1999);
    overfprintf(stdout, "Roman: 0 -> %Ro\n", 0);
    overfprintf(stdout, "Roman: -42 -> %Ro\n", -42);

    overfprintf(stdout, "Zeckendorf: 15 -> %Zr\n", 15u);
    overfprintf(stdout, "Zeckendorf: 255 -> %Zr\n", 255u);

    overfprintf(stdout, "Cv: 255 base16 lower -> %Cv\n", 255, 16);
    overfprintf(stdout, "CV: 255 base16 upper -> %CV\n", 255, 16);
    overfprintf(stdout, "Cv: -123 base2 -> %Cv\n", -123, 2);
    overfprintf(stdout, "CV: -123 base2 -> %CV\n", -123, 2);

    overfprintf(stdout, "to: \"ff\" base16 -> %to\n", "ff", 16);
    overfprintf(stdout, "TO: \"FF\" base16 -> %TO\n", "FF", 16);
    overfprintf(stdout, "to: \"1011\" base2 -> %to\n", "1011", 2);
    overfprintf(stdout, "TO: \"1011\" base2 -> %TO\n", "1011", 2);

    int mi_val = 1234;
    uint32_t mu_val = 123;
    float mf_val = 3.14f;
    double md_val = 3.141;

    overfprintf(stdout, "Dump int32: %mi\n", mi_val);
    overfprintf(stdout, "Dump uint32: %mu\n", mu_val);
    overfprintf(stdout, "Dump float: %mf\n", mf_val);
    overfprintf(stdout, "Dump double: %md\n", md_val);

    return 0;
}
