#include <stdio.h>

unsigned long long factorial(int n);
void calculateFactorials(int array[], int size);

int main() {
    int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    int size = sizeof(array) / sizeof(array[0]);

    calculateFactorials(array, size);

    return 0;
}

unsigned long long factorial(int n) {
    if (n == 0) return 1;
    return n * factorial(n - 1);
}

void calculateFactorials(int array[], int size) {
    for (int i = 0; i < size; i++) {
        printf("Silnia liczby %d = %llu\n", array[i], factorial(array[i]));
    }
}
