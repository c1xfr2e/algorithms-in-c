#include <stdio.h>

typedef int (*PREV)(int);

void insert_ordered_array(int arr[], int first, int pos, int item, PREV prev) {
    int x = pos, y = prev(x);
    while (y >= first) {
        if (item < arr[y]) {
            arr[x] = arr[y];
            x = y, y = prev(y);
            continue;
        }
        break;
    }
    arr[x] = item;
}

int array_prev(int i) {
    return i - 1;
}

int heap_prev(int i) {
    return (i - 1) / 2;
}

void test_array_insert() {
    int a[] = {1, 2, 4, 5, 3};
    int x = 4;
    insert_ordered_array(a, 0, x, a[x], array_prev);
    for (int i = 0; i < 5; i++)
        printf("%d ", a[i]);
}

void test_heap_insert() {
    int a[22];
    a[0] = 1, a[1] = 3, a[4] = 4, a[10] = 5, a[21] = 2;
    int x = 21;
    insert_ordered_array(a, 0, x, a[x], heap_prev);
    printf("%d %d %d %d %d\n", a[0], a[1], a[4], a[10], a[21]);
}

int main(int argc, char *argv[]) {
    test_array_insert();
    printf("\n");
    test_heap_insert();
    return 0;
}
