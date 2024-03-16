#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


int generateComputerMove() {
    return rand() % 3; // 0 - kamień, 1 - papier, 2 - nożyce
}


int main() {
    char userMove[10];
    int win = 0, lose = 0, draw = 0; 

    srand(time(NULL)); 

    printf("Gra w papier, kamień, nożyce. Wpisz 'exit' aby zakończyć.\n");

    while (1) {
        printf("Wybierz (papier, kamien, nozyce): ");
        scanf("%s", userMove);

        if (strcmp(userMove, "exit") == 0) {
            break;
        }

        int computerMove = generateComputerMove();
        
        if ((strcmp(userMove, "kamien") == 0 && computerMove == 2) ||
            (strcmp(userMove, "papier") == 0 && computerMove == 0) ||
            (strcmp(userMove, "nozyce") == 0 && computerMove == 1)) {
            printf("Wygrales!\n");
            win++;
        } else if ((strcmp(userMove, "kamien") == 0 && computerMove == 1) ||
                   (strcmp(userMove, "papier") == 0 && computerMove == 2) ||
                   (strcmp(userMove, "nozyce") == 0 && computerMove == 0)) {
            printf("Przegrales.\n");
            lose++;
        } else {
            printf("Remis.\n");
            draw++;
        }
    }

    printf("Podsumowanie: Wygrane: %d, Przegrane: %d, Remisy: %d\n", win, lose, draw);

    return 0;
}
