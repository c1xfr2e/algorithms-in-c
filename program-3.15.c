// Program 3. 15
// String search

#include <stdio.h>
#include <stdlib.h>

#define N 1000

int main(int argc, char *argv[]) {
    char a[N], *p = argv[1];
    int i, j;
    char c;
    for (i = 0; i < N; a[i] = c, i++) {
        if ((c = getchar()) == EOF)
            break;
    }
    a[i] = 0;
    for (i = 0; a[i] != 0; i++) {
        for (j = 0; p[j] != 0; j++) {
            if (a[i + j] != p[j])
                break;
        }
        if (p[j] == 0)
            printf("%d ", i);
    }
    printf("\n");
    return 0;
}
