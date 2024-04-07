#include <stdio.h>

// Funkcja pomocnicza do obliczenia silni
long long silnia(int n) {
    long long wynik = 1;
    for(int i = 1; i <= n; i++) {
        wynik *= i;
    }
    return wynik;
}

// Funkcja do obliczenia współczynnika dwumianowego (n po k)
long long dwumian(int n, int k) {
    return silnia(n) / (silnia(k) * silnia(n - k));
}

// Funkcja wyświetlająca trójkąt Pascala o wysokości N
void wyswietlTrojkatPascala(int N) {
    for(int n = 0; n < N; n++) {
        // Wyświetlenie odpowiedniej liczby spacji przed każdym wierszem
        for(int i = 0; i < N - n - 1; i++) {
            printf(" ");
        }
        for(int k = 0; k <= n; k++) {
            printf("%lld ", dwumian(n, k));
        }
        printf("\n");
    }
}

int main() {
    int N;
    printf("Podaj wysokość trójkąta Pascala: ");
    scanf("%d", &N);
    wyswietlTrojkatPascala(N);
    return 0;
}
