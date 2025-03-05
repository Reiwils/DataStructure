#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 10

// Struktur Node untuk Chaining
typedef struct Node {
    int key;
    struct Node* next;
} Node;

Node* hashTable[TABLE_SIZE];

// Fungsi Hash Division
int hashFunction(int key) {
    return key % TABLE_SIZE;
}

// Fungsi untuk memasukkan key ke hash table dengan chaining
void insert(int key) {
    int hashIndex = hashFunction(key);
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;
    newNode->next = hashTable[hashIndex];
    hashTable[hashIndex] = newNode;
}

// Fungsi untuk mencari key di hash table dengan chaining
int search(int key) {
    int hashIndex = hashFunction(key);
    Node* current = hashTable[hashIndex];

    while (current != NULL) {
        if (current->key == key) {
            return hashIndex; // Key ditemukan
        }
        current = current->next;
    }
    return -1; // Key tidak ditemukan
}

// Fungsi untuk menampilkan hash table
void display() {
    printf("Hash Table:\n");
    for (int i = 0; i < TABLE_SIZE; i++) {
        printf("Index %d: ", i);
        Node* current = hashTable[i];
        while (current != NULL) {
            printf("%d -> ", current->key);
            current = current->next;
        }
        printf("NULL\n");
    }
}

int main() {
    int choice, key, result;

    // Inisialisasi hash table dengan NULL (kosong)
    for (int i = 0; i < TABLE_SIZE; i++) {
        hashTable[i] = NULL;
    }

    do {
        printf("\nMenu Collision Handling (Chaining)\n");
        printf("1. Masukkan Key\n");
        printf("2. Cari Key\n");
        printf("3. Tampilkan Hash Table\n");
        printf("4. Keluar\n");
        printf("Pilihan Anda: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Masukkan Key: ");
                scanf("%d", &key);
                insert(key);
                break;
            case 2:
                printf("Masukkan Key yang ingin dicari: ");
                scanf("%d", &key);
                result = search(key);
                if (result != -1) {
                    printf("Key %d ditemukan di index %d\n", key, result);
                } else {
                    printf("Key %d tidak ditemukan\n", key);
                }
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Terima kasih!\n");
                break;
            default:
                printf("Pilihan tidak valid.\n");
        }
    } while (choice != 4);

    // Bebaskan memori yang dialokasikan untuk node
    for (int i = 0; i < TABLE_SIZE; i++) {
        Node* current = hashTable[i];
        while (current != NULL) {
            Node* temp = current;
            current = current->next;
            free(temp);
        }
    }

    return 0;
}
