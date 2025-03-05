#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 10

int hashTable[TABLE_SIZE];

// Fungsi Hash Pertama
int hashFunction1(int key) {
    return key % TABLE_SIZE;
}

// Fungsi Hash Kedua (untuk Rehashing)
int hashFunction2(int key) {
    return (key / TABLE_SIZE) % TABLE_SIZE; // Contoh fungsi hash kedua
}

// Fungsi untuk memasukkan key ke hash table dengan rehashing
void insert(int key) {
    int hashIndex1 = hashFunction1(key);
    int hashIndex2 = hashFunction2(key);
    int initialIndex = hashIndex1;

    if (hashTable[hashIndex1] == -1) {
        hashTable[hashIndex1] = key;
        return;
    }

    // Rehashing untuk menangani tabrakan
    int i = 1;
    do {
        int newIndex = (hashIndex1 + i * hashIndex2) % TABLE_SIZE;
        if (hashTable[newIndex] == -1) {
            hashTable[newIndex] = key;
            return;
        }
        i++;
    } while (i < TABLE_SIZE && hashIndex1 != initialIndex);

    printf("Hash Table Penuh, Key %d tidak dapat dimasukkan.\n", key);
}

// Fungsi untuk mencari key di hash table dengan rehashing
int search(int key) {
    int hashIndex1 = hashFunction1(key);
    int hashIndex2 = hashFunction2(key);
    int initialIndex = hashIndex1;

    if (hashTable[hashIndex1] == key) {
        return hashIndex1;
    }

    // Rehashing untuk mencari key
    int i = 1;
    do {
        int newIndex = (hashIndex1 + i * hashIndex2) % TABLE_SIZE;
        if (hashTable[newIndex] == key) {
            return newIndex;
        }
        if (hashTable[newIndex] == -1) {
            return -1; // Key tidak ditemukan
        }
        i++;
    } while (i < TABLE_SIZE && hashIndex1 != initialIndex);

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
        printf("\nMenu Collision Handling (Rehashing)\n");
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
