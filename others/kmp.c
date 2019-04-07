
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void kmp_gen_next(char *s, int *N, int len) {
    N[0] = 0;
    int i, k;
    for (i = 1; i < len; i++) {
        for (k = N[i - 1]; (s[i] != s[k]) && (--k != -1); k = N[k])
            ;
        N[i] = k + 1;
    }
}

int main(int argc, char *argv[]) {
    char *s = argv[1];
    int i, len = strlen(s);
    int *N = malloc(len * sizeof(int));
    kmp_gen_next(s, N, len);
    for (char *c = s; *c; c++) {
        printf("%2c ", *c);
    }
    printf("\n");
    for (i = 0; i < len; i++)
        printf("%2d ", N[i]);
}
