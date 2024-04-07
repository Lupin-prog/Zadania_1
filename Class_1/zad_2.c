#include <stdio.h>

int main() {
    int grades[2][5]; 
    int sumMath = 0, sumPhysics = 0;
    float averageMath, averagePhysics;

    printf("Wprowadz oceny z matematyki dla 5 uczniów:\n");
    for(int i = 0; i < 5; i++) {
        do {
            scanf("%d", &grades[0][i]);
            if(grades[0][i] < 2 || grades[0][i] > 5) {
                printf("Nieprawidłowa ocena. Wprowadź ocenę od 2 do 5:\n");
            }
        } while(grades[0][i] < 2 || grades[0][i] > 5);
        sumMath += grades[0][i];
    }

    printf("Wprowadz oceny z fizyki dla 5 uczniów:\n");
    for(int i = 0; i < 5; i++) {
        do {
            scanf("%d", &grades[1][i]);
            if(grades[1][i] < 2 || grades[1][i] > 5) {
                printf("Nieprawidłowa ocena. Wprowadź ocenę od 2 do 5:\n");
            }
        } while(grades[1][i] < 2 || grades[1][i] > 5);
        sumPhysics += grades[1][i];
    }

    averageMath = (float)sumMath / 5;
    averagePhysics = (float)sumPhysics / 5;

    printf("Średnia ocen z matematyki: %.2f\n", averageMath);
    printf("Średnia ocen z fizyki: %.2f\n", averagePhysics);

    return 0;
}
