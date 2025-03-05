#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Fungsi Hash Mid-Square
int midSquareHash(int key, int tableSize) {
    long long square = (long long)key * key;
    char squareStr[20];
    sprintf(squareStr, "%lld", square);

    int length = strlen(squareStr);
    int middle = length / 2;
    int digitCount = (int)log10(tableSize) + 1;
    int startIndex = middle - digitCount / 2;

    if (startIndex < 0) {
        startIndex = 0;
    }

    char hashStr[10];
    int hashIndex = 0;
    for (int i = startIndex; i < startIndex + digitCount && squareStr[i] != '\0'; i++) {
        hashStr[hashIndex++] = squareStr[i];
    }
    hashStr[hashIndex] = '\0';

    return atoi(hashStr) % tableSize;
}

int main() {
    int choice, key, tableSize, hashValue;

    do {
        printf("\nMenu Hash Function Mid-Square\n");
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

                hashValue = midSquareHash(key, tableSize);
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
