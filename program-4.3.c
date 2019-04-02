// Program 4.3
// Infix-to-postfix conversion
// gcc -std=c11 -g program-4.3.c program-4.4.c -o program-4.3
// ./program-4.3 "( 5 * ( ( ( 9 + 8 ) * ( 4 * 6 ) ) + 7 ) )"

#include <stdio.h>
#include <string.h>

#include "item_int.h"
#include "STACK.h"

int main(int argc, char *argv[]) {
    char *a = argv[1];
    int i, N = strlen(a);
    STACKinit(N);
    for (i = 0; i < N; i++) {
        if (a[i] == ')')
            printf("%c ", STACKpop());
        if ((a[i] == '+') || (a[i] == '*'))
            STACKpush(a[i]);
        if ((a[i] >= '0') && (a[i] <= '9'))
            printf("%c ", a[i]);
    }
    printf("\n");
    return 0;
}