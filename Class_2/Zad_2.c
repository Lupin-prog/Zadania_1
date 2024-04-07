#include <stdio.h>

void modyfikuj(float *wskaznik) {
    *wskaznik *= 2;  
}

int main() {
    float zmienna = 3.5;  
    float *wskaznik = &zmienna;  

    printf("Wartość zmiennej przed modyfikacją: %.2f\n", zmienna);

    modyfikuj(wskaznik);

    printf("Wartość zmiennej po modyfikacji: %.2f\n", zmienna);

    return 0;
}
