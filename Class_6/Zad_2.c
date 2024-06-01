#include <stdio.h>

int main() {
    int arr[10];
    for (int i = 0; i < 10; i++) {
        arr[i] = i;
    }

    int *ptr = arr;

    for (int i = 0; i < 10; i++) {
        printf("Element %d: %d\n", i, *(ptr + i));
    }

    return 0;
}
