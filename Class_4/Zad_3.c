#include <stdio.h>

void swap(int* x, int* y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

void printArray(int* array, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

void permute(int* array, int start, int end) {
    if (start == end) {
        printArray(array, end + 1);
    } else {
        for (int i = start; i <= end; i++) {
            // Zamień start z i-tym elementem
            swap((array + start), (array + i));
            // Rekurencyjnie generuj permutacje dla następnego poziomu
            permute(array, start + 1, end);
            // Cofnij zmianę (backtrack)
            swap((array + start), (array + i));
        }
    }
}

int main() {
    int array[] = {1, 2, 3};
    int n = sizeof(array) / sizeof(array[0]);
    permute(array, 0, n - 1);
    return 0;
}
