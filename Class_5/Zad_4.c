#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* create_node(int value) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    if (new_node == NULL) {
        printf("Błąd przy alokacji pamięci.\n");
        exit(1);
    }
    new_node->data = value;
    new_node->next = NULL;
    return new_node;
}

void add_first(Node** head, int value) {
    Node* new_node = create_node(value);
    new_node->next = *head;
    *head = new_node;
}

int remove_by_index(Node** head, int index) {
    if (*head == NULL) {
        printf("Lista jest pusta.\n");
        return -1; // lub inny kod błędu
    }

    Node* temp = *head;
    Node* prev = NULL;

    if (index == 0) {
        *head = temp->next;
        int value = temp->data;
        free(temp);
        return value;
    }

    for (int i = 0; temp != NULL && i < index; i++) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Indeks poza zakresem.\n");
        return -1; // lub inny kod błędu
    }

    int value = temp->data;
    prev->next = temp->next;
    free(temp);

    return value;
}

void print_list(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    Node* head = NULL;

    add_first(&head, 10);
    add_first(&head, 20);
    add_first(&head, 30);

    print_list(head);

    int index = 1;
    int value = remove_by_index(&head, index);
    printf("Usunięto wartość na indeksie %d: %d\n", index, value);
    print_list(head);

    index = 0;
    value = remove_by_index(&head, index);
    printf("Usunięto wartość na indeksie %d: %d\n", index, value);
    print_list(head);

    index = 2;
    value = remove_by_index(&head, index);
    printf("Usunięto wartość na indeksie %d: %d\n", index, value);
    print_list(head);

    return 0;
}
