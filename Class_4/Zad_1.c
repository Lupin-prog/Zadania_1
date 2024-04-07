#include <stdio.h>

// Deklaracja funkcji
long factorial(int n);

int main() {
    int number;
    printf("Wprowadź liczbę z której należy policzyć silnię: ");
    scanf("%d", &number);

    // Sprawdzenie, czy podana liczba nie jest ujemna
    if (number < 0) {
        printf("Nie istnieje silnia z liczby ujemnej.\n");
    } else {
        printf("Silnia z liczby %d = %ld\n", number, factorial(number));
    }

    return 0;
}

// Definicja funkcji
long factorial(int n) {
    if (n == 0) // Warunek bazowy
        return 1;
    else
        return n * factorial(n - 1); // Rekurencyjne wywołanie funkcji
}
