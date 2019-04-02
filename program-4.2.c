// Program 4.2
// Postfix-expression evaluation
// gcc -std=c11 -g program-4.2.c program-4.4.c -o program-4.2

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "item_int.h"
#include "STACK.h"

int main(int argc, char *argv[]) {
    char *a = argv[1];
    int i, N = strlen(a);
    STACKinit(N);
    for (i = 0; i < N; i++) {
        if (a[i] == '+')
            STACKpush(STACKpop() + STACKpop());
        if (a[i] == '*')
            STACKpush(STACKpop() * STACKpop());
        if ((a[i] >= '0') && (a[i] <= '9'))
            STACKpush(0);
        while ((a[i] >= '0') && (a[i] <= '9'))
            STACKpush(10 * STACKpop() + (a[i++] - '0'));
    }
    printf("%d \n", STACKpop());
    return 0;
}
