// Program 3.17
// Sort an array of strings

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N_MAX 1000
#define M_MAX 10000
char buf[M_MAX];
int M = 0;

int compare(const void *i, const void *j) {
    return strcmp(*(char **)i, *(char **)j);
}

int main(int argc, char *argv[]) {
    int N;
    char *a[N_MAX];
    for (N = 0; N < N_MAX; N++) {
        a[N] = &buf[M];
        if (scanf("%s", a[N]) == EOF)
            break;
        M += strlen(a[N]) + 1;
    }
    qsort(a, N, sizeof(char *), compare);
    for (int i = 0; i < N; i++)
        printf("%s\n", a[i]);
    return 0;
}
