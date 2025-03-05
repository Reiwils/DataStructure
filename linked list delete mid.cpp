#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struktur node untuk double linked list
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

// Fungsi untuk menghapus node di tengah double linked list
void delete_mid(struct Node** head) {
    if (*head == NULL) {
        printf("List kosong, tidak ada yang bisa dihapus.\n");
        return;
    }

    struct Node* slow = *head;
    struct Node* fast = *head;
    struct Node* prev_slow = NULL;

    while (fast != NULL && fast->next != NULL) {
        fast = fast->next->next;
        prev_slow = slow;
        slow = slow->next;
    }

    // Jika list hanya memiliki satu node
    if (slow == *head && slow->next == NULL) {
        free(slow);
        *head = NULL;
        return;
    }

    // Menghapus node tengah
    if (prev_slow != NULL) {
        prev_slow->next = slow->next;
    } else {
        *head = slow->next;
    }

    if (slow->next != NULL) {
        slow->next->prev = prev_slow;
    }

    free(slow);
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
    push_back(&head, 4);
    push_back(&head, 5);

    printf("Double Linked List sebelum delete_mid:\n");
    printList(head);

    // Menghapus node di tengah
    delete_mid(&head);

    printf("Double Linked List setelah delete_mid:\n");
    printList(head);

    return 0;
}
