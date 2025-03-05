#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Fungsi Hash Rotation
int rotationHash(int key, int tableSize, int shift) {
    int rotatedKey = (key << shift) | (key >> (sizeof(int) * 8 - shift));
    return abs(rotatedKey % tableSize);
}

int main() {
    int choice, key, tableSize, hashValue, shift;

    do {
        printf("\nMenu Hash Function Rotation\n");
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
                printf("Masukkan jumlah shift (rotasi): ");
                scanf("%d", &shift);

                hashValue = rotationHash(key, tableSize, shift);
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
