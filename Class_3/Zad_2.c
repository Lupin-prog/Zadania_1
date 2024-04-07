#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int rows, cols;
    printf("Podaj liczbe wierszy: ");
    scanf("%d", &rows);
    printf("Podaj liczbe kolumn: ");
    scanf("%d", &cols);

    // Alokuje pamięć dla wskaźników do wierszy
    int **matrix = (int **)malloc(rows * sizeof(int *));
    if(matrix == NULL) {
        printf("Nie udalo sie zaalokowac pamieci.\n");
        return -1;
    }

    // Alokuje pamięć dla każdego wiersza
    for(int i = 0; i < rows; i++) {
        matrix[i] = (int *)malloc(cols * sizeof(int));
        if(matrix[i] == NULL) {
            printf("Nie udalo sie zaalokowac pamieci dla wiersza %d.\n", i);
            // Zwolnienie pamięci zaalokowanej do tej pory przed wyjściem z programu
            for(int j = 0; j < i; j++) {
                free(matrix[j]);
            }
            free(matrix);
            return -1;
        }
    }

    // Inicjalizacja generatora liczb losowych
    srand(time(NULL));

    // Wypełnianie macierzy losowymi liczbami i wyświetlanie jej
    printf("Wygenerowana macierz:\n");
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            matrix[i][j] = rand() % 100; // Liczby losowe od 0 do 99
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    // Zwolnienie pamięci
    for(int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}
