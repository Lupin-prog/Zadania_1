#include <stdio.h>
int main()
{
    char name[100];
    printf("Wprowadz swoje imie: ");
    scanf("%s", name);
    printf("Twoje imie to: %s", name);

    getchar();
    getchar();
    return 0;
}