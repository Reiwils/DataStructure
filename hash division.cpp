#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Fungsi Hash Division
int divisionHash(int key, int tableSize) {
    return key % tableSize;
}

int main() {
    int choice, key, tableSize, hashValue;

    do {
        printf("\nMenu Hash Function Division\n");
        printf("1. Hitung Hash Value\n");
        printf("2. Keluar\n");
        printf("Pilihan Anda: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Masukkan Key (angka): ");
                scanf("%d", &key);
                printf("Masukkan Table Size: ");
                scanf("%d", &tableSize);

                hashValue = divisionHash(key, tableSize);
                printf("Hash Value dari %d adalah %d\n", key, hashValue);
                break;
            case 2:
                printf("Terima kasih!\n");
                break;
            default:
                printf("Pilihan tidak valid.\n");
        }
    } while (choice != 2);

    return 0;
}
