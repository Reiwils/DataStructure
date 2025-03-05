#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Linked list push mid
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void push_mid(struct Node** head, int data) {
    struct Node* newNode = createNode(data);

    // Jika list kosong, node baru menjadi head
    if (*head == NULL) {
        *head = newNode;
        return;
    }

    // Mencari node tengah
    struct Node* slow = *head;
    struct Node* fast = *head;
    while (fast->next != NULL && fast->next->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Menambahkan node baru setelah node tengah
    newNode->next = slow->next;
    newNode->prev = slow;
    if (slow->next != NULL) {
        slow->next->prev = newNode;
    }
    slow->next = newNode;
}

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

    // Menambahkan beberapa node
    push_mid(&head, 1);
    push_mid(&head, 3);
    push_mid(&head, 5);

    printf("Double Linked List setelah push_mid:\n");
    printList(head);

    return 0;
}
