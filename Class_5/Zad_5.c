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

int remove_by_value(Node** head, int value) {
    if (*head == NULL) {
        printf("Lista jest pusta.\n");
        return -1; // lub inny kod błędu
    }

    Node* temp = *head;
    Node* prev = NULL;

    if (temp != NULL && temp->data == value) {
        *head = temp->next;
        free(temp);
        return value;
    }


    while (temp != NULL && temp->data != value) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Element o wartości %d nie został znaleziony.\n", value);
        return -1; // lub inny kod błędu
    }

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
    add_first(&head, 40);

    print_list(head);

    int value = 20;
    int result = remove_by_value(&head, value);
    if (result != -1) {
        printf("Usunięto wartość: %d\n", value);
    }
    print_list(head);

    value = 40;
    result = remove_by_value(&head, value);
    if (result != -1) {
        printf("Usunięto wartość: %d\n", value);
    }
    print_list(head);

    value = 50; 
    result = remove_by_value(&head, value);
    if (result != -1) {
        printf("Usunięto wartość: %d\n", value);
    }
    print_list(head);

    return 0;
}
