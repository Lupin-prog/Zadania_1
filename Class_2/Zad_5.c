#include <stdio.h>
#include <string.h>

#define MAX_CONTACTS 100 // Maksymalna liczba kontaktów w książce adresowej
#define MAX_NAME_LENGTH 50 // Maksymalna długość imienia i nazwiska
#define MAX_PHONE_LENGTH 15 // Maksymalna długość numeru telefonu

// Struktura Contact przechowująca dane kontaktowe
struct Contact {
    char imie[MAX_NAME_LENGTH];
    char nazwisko[MAX_NAME_LENGTH];
    char telefon[MAX_PHONE_LENGTH];
};

// Struktura reprezentująca książkę adresową
struct AddressBook {
    struct Contact kontakty[MAX_CONTACTS];
    int liczbaKontaktow;
};

// Funkcja dodająca nowy kontakt do książki adresowej
void dodajKontakt(struct AddressBook *ksiazka, const char *imie, const char *nazwisko, const char *telefon) {
    if (ksiazka->liczbaKontaktow < MAX_CONTACTS) {
        strcpy(ksiazka->kontakty[ksiazka->liczbaKontaktow].imie, imie);
        strcpy(ksiazka->kontakty[ksiazka->liczbaKontaktow].nazwisko, nazwisko);
        strcpy(ksiazka->kontakty[ksiazka->liczbaKontaktow].telefon, telefon);
        ksiazka->liczbaKontaktow++;
        printf("Dodano nowy kontakt.\n");
    } else {
        printf("Ksiazka adresowa jest pelna. Nie mozna dodac nowego kontaktu.\n");
    }
}

// Funkcja wyszukująca kontakt po nazwisku
void znajdzKontakt(const struct AddressBook *ksiazka, const char *nazwisko) {
    int znaleziono = 0;
    for (int i = 0; i < ksiazka->liczbaKontaktow; i++) {
        if (strcmp(ksiazka->kontakty[i].nazwisko, nazwisko) == 0) {
            printf("Znaleziono kontakt:\n");
            printf("Imie: %s\n", ksiazka->kontakty[i].imie);
            printf("Nazwisko: %s\n", ksiazka->kontakty[i].nazwisko);
            printf("Telefon: %s\n", ksiazka->kontakty[i].telefon);
            znaleziono = 1;
            break;
        }
    }
    if (!znaleziono) {
        printf("Nie znaleziono kontaktu o nazwisku %s.\n", nazwisko);
    }
}

// Funkcja usuwająca kontakt po nazwisku
void usunKontakt(struct AddressBook *ksiazka, const char *nazwisko) {
    int znaleziono = 0;
    for (int i = 0; i < ksiazka->liczbaKontaktow; i++) {
        if (strcmp(ksiazka->kontakty[i].nazwisko, nazwisko) == 0) {
            // Usunięcie kontaktu poprzez przesunięcie wszystkich kolejnych kontaktów o jedno miejsce w górę
            for (int j = i; j < ksiazka->liczbaKontaktow - 1; j++) {
                ksiazka->kontakty[j] = ksiazka->kontakty[j + 1];
            }
            ksiazka->liczbaKontaktow--;
            printf("Usunieto kontakt o nazwisku %s.\n", nazwisko);
            znaleziono = 1;
            break;
        }
    }
    if (!znaleziono) {
        printf("Nie znaleziono kontaktu o nazwisku %s.\n", nazwisko);
    }
}

// Funkcja wypisująca wszystkie kontakty w książce adresowej
void wypiszWszystkieKontakty(const struct AddressBook *ksiazka) {
    printf("Wszystkie kontakty w ksiazce adresowej:\n");
    for (int i = 0; i < ksiazka->liczbaKontaktow; i++) {
        printf("Imie: %s\n", ksiazka->kontakty[i].imie);
        printf("Nazwisko: %s\n", ksiazka->kontakty[i].nazwisko);
        printf("Telefon: %s\n", ksiazka->kontakty[i].telefon);
        printf("\n");
    }
}

int main() {
    struct AddressBook ksiazka = {{}, 0};
    char opcja;
    char imie[MAX_NAME_LENGTH], nazwisko[MAX_NAME_LENGTH], telefon[MAX_PHONE_LENGTH];

    do {
        printf("\nWybierz opcje:\n");
        printf("1. Dodaj kontakt\n");
        printf("2. Znajdz kontakt\n");
        printf("3. Usun kontakt\n");
        printf("4. Wypisz wszystkie kontakty\n");
        printf("q. Wyjdz\n");
        printf("Opcja: ");
        scanf(" %c", &opcja);

        switch (opcja) {
            case '1':
                printf("Podaj imie: ");
                scanf("%s", imie);
                printf("Podaj nazwisko: ");
                scanf("%s", nazwisko);
                printf("Podaj numer telefonu: ");
                scanf("%s", telefon);
                dodajKontakt(&ksiazka, imie, nazwisko, telefon);
                break;
            case '2':
                printf("Podaj nazwisko do wyszukania: ");
                scanf("%s", nazwisko);
                znajdzKontakt(&ksiazka, nazwisko);
                break;
            case '3':
                printf("Podaj nazwisko do usuniecia: ");
                scanf("%s", nazwisko);
                usunKontakt(&ksiazka, nazwisko);
                break;
            case '4':
                wypiszWszystkieKontakty(&ksiazka);
                break;
            case 'q':
                printf("Wyjscie z programu.\n");
                break;
            default:
                printf("Nieprawidlowa opcja. Wybierz ponownie.\n");
                break;
        }
    } while (opcja != 'q');

    return 0;
}
