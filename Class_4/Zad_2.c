#include <stdio.h>

// Deklaracja funkcji rekurencyjnej do wyszukiwania binarnego
int binarySearch(int arr[], int left, int right, int x) {
    if (right >= left) {
        int mid = left + (right - left) / 2; // Obliczanie środkowego indeksu

        // Jeśli element jest obecny na środku
        if (arr[mid] == x) 
            return mid;

        // Jeśli element jest mniejszy niż środkowy, musi znajdować się w lewej podtablicy
        if (arr[mid] > x) 
            return binarySearch(arr, left, mid - 1, x);

        // W przeciwnym razie element znajduje się w prawej podtablicy
        return binarySearch(arr, mid + 1, right, x);
    }

    // Element nie jest obecny w tablicy
    return -1;
}

int main() {
    int arr[] = {2, 3, 4, 10, 40}; // Przykładowa posortowana tablica
    int n = sizeof(arr)/sizeof(arr[0]); // Rozmiar tablicy
    int x = 10; // Szukany element
    int result = binarySearch(arr, 0, n - 1, x); // Wywołanie funkcji wyszukiwania binarnego

    // Wypisanie wyniku
    if (result == -1)
        printf("Element nie znajduje się w tablicy");
    else
        printf("Element znajduje się na indeksie %d", result);

    return 0;
}
