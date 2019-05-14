// ./a.out CACBACABB

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FLAG_A 'A'
#define FLAG_B 'B'
#define FLAG_C 'C'

#define exch(a, b)  \
    {               \
        char t = a; \
        a = b;      \
        b = t;      \
    }

void two_partiton_2(char *AB, int Len) {
    int i = -1;
    for (int j = 0; j < Len; j++) {
        if (AB[j] == FLAG_A) {
            i++;
            exch(AB[i], AB[j]);
        }
    }
}

void partiton_3(char *ABC, int Len) {
    int i = -1, j = 0, k = Len;
    while (j < k) {
        if (ABC[j] == FLAG_A) {
            i++;
            exch(ABC[i], ABC[j]);
            j++;
            continue;
        }
        if (ABC[j] == FLAG_C) {
            k--;
            exch(ABC[j], ABC[k]);
            continue;
        }
        j++;
    }
}

#define MAX 50

int main(int argc, char *argv[]) {
    char s[MAX];
    strcpy(s, argv[1]);
    partiton_3(s, strlen(s));
    printf("%s\n", s);
    return 0;
}
