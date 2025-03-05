#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// Fungsi untuk membuat node baru
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Fungsi untuk menambahkan node di belakang double linked list
void push_back(struct Node** head, int data) {
    struct Node* newNode = createNode(data);

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    struct Node* current = *head;
    while (current->next != NULL) {
        current = current->next;
    }

    current->next = newNode;
    newNode->prev = current;
}

// Fungsi untuk menghapus node di belakang double linked list
void delete_back(struct Node** head) {
    if (*head == NULL) {
        printf("List kosong, tidak ada yang bisa dihapus.\n");
        return;
    }

    // Jika hanya ada satu node
    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        return;
    }

    struct Node* current = *head;
    while (current->next->next != NULL) {
        current = current->next;
    }

    struct Node* temp = current->next;
    current->next = NULL;
    free(temp);
}

// Fungsi untuk print double linked list
void printList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d <-> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;

    // Menambahkan beberapa node di belakang
    push_back(&head, 1);
    push_back(&head, 2);
    push_back(&head, 3);

    printf("Double Linked List sebelum delete_back:\n");
    printList(head);

    // Menghapus node di belakang
    delete_back(&head);

    printf("Double Linked List setelah delete_back:\n");
    printList(head);

    return 0;
}
