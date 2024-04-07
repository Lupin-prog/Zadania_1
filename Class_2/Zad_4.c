#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define STUDENTS_COUNT 100
#define NAME_LENGTH 50

// Definicja struktury Student
typedef struct {
    char name[NAME_LENGTH];
    float finalGrade;
} Student;

// Funkcja sortująca
void sortStudents(Student *students, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (students[j].finalGrade < students[j + 1].finalGrade) {
                // Zamiana miejscami
                Student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
}

int main() {
    // Inicjalizacja generatora liczb losowych
    srand(time(NULL));

    // Inicjalizacja tablicy struktur Student przykładowymi danymi
    Student students[STUDENTS_COUNT];
    for (int i = 0; i < STUDENTS_COUNT; i++) {
        snprintf(students[i].name, NAME_LENGTH, "Student%d", i + 1);
        // Generowanie losowej oceny z zakresu 2.00 do 5.00
        students[i].finalGrade = 2.0f + (float)(rand() % 301) / 100.0f;
    }

    // Sortowanie studentów według ocen końcowych w porządku malejącym
    sortStudents(students, STUDENTS_COUNT);

    // Wypisanie posortowanej listy studentów
    for (int i = 0; i < STUDENTS_COUNT; i++) {
        printf("%s: %.2f\n", students[i].name, students[i].finalGrade);
    }

    return 0;
}
