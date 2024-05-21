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

int remove_last(Node** head) {
    if (*head == NULL) {
        printf("Lista jest pusta.\n");
        return -1; // lub inny kod błędu
    }

    Node* temp = *head;
    Node* prev = NULL;

    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }

    int value = temp->data;

    if (prev == NULL) {
        *head = NULL;
    } else {
        prev->next = NULL;
    }

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

    int value = remove_last(&head);
    printf("Usunięto wartość: %d\n", value);
    print_list(head);

    value = remove_last(&head);
    printf("Usunięto wartość: %d\n", value);
    print_list(head);

    value = remove_last(&head);
    printf("Usunięto wartość: %d\n", value);
    print_list(head);

    return 0;
}
