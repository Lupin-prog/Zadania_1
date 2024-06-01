#include <stdio.h>

int add(int a, int b) {
    return a + b;
}

int multiply(int a, int b) {
    return a * b;
}

int subtract(int a, int b) {
    return a - b;
}

int main() {
    int choice, x, y;
    int (*func_ptr)(int, int);

    printf("Wybierz operację:\n");
    printf("1. Dodawanie\n");
    printf("2. Mnożenie\n");
    printf("3. Odejmowanie\n");
    printf("Twój wybór: ");
    scanf("%d", &choice);

    printf("Wprowadź dwie liczby: ");
    scanf("%d %d", &x, &y);

    switch(choice) {
        case 1:
            func_ptr = &add;
            break;
        case 2:
            func_ptr = &multiply;
            break;
        case 3:
            func_ptr = &subtract;
            break;
        default:
            printf("Nieprawidłowy wybór!\n");
            return 1;
    }

    int result = func_ptr(x, y);
    printf("Wynik: %d\n", result);

    return 0;
}
