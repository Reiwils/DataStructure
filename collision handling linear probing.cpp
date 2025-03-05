#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 10

int hashTable[TABLE_SIZE];

// Fungsi Hash Division
int hashFunction(int key) {
    return key % TABLE_SIZE;
}

// Fungsi untuk memasukkan key ke hash table dengan linear probing
void insert(int key) {
    int hashIndex = hashFunction(key);

    // Linear Probing untuk menangani tabrakan
    while (hashTable[hashIndex] != -1) {
        hashIndex = (hashIndex + 1) % TABLE_SIZE;
    }

    hashTable[hashIndex] = key;
}

// Fungsi untuk mencari key di hash table dengan linear probing
int search(int key) {
    int hashIndex = hashFunction(key);
    int initialIndex = hashIndex;

    while (hashTable[hashIndex] != -1) {
        if (hashTable[hashIndex] == key) {
            return hashIndex; // Key ditemukan
        }
        hashIndex = (hashIndex + 1) % TABLE_SIZE;
        if (hashIndex == initialIndex) {
            break; // Kembali ke indeks awal, key tidak ditemukan
        }
    }
    return -1; // Key tidak ditemukan
}

// Fungsi untuk menampilkan hash table
void display() {
    printf("Hash Table:\n");
    for (int i = 0; i < TABLE_SIZE; i++) {
        printf("Index %d: %d\n", i, hashTable[i]);
    }
}

int main() {
    int choice, key, result;

    // Inisialisasi hash table dengan -1 (kosong)
    for (int i = 0; i < TABLE_SIZE; i++) {
        hashTable[i] = -1;
    }

    do {
        printf("\nMenu Collision Handling (Linear Probing)\n");
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

    return 0;
}
