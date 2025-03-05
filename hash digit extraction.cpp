#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Fungsi Hash Digit Extraction
int digitExtractionHash(int key, int tableSize, int* digits, int numDigits) {
    char keyStr[20];
    sprintf(keyStr, "%d", key);
    int length = strlen(keyStr);

    char hashStr[10];
    int hashIndex = 0;
    for (int i = 0; i < numDigits; i++) {
        if (digits[i] < length) {
            hashStr[hashIndex++] = keyStr[digits[i]];
        }
    }
    hashStr[hashIndex] = '\0';

    if (strlen(hashStr) == 0) {
        return 0; 
    }

    return atoi(hashStr) % tableSize;
}

int main() {
    int choice, key, tableSize, hashValue, numDigits;
    int digits[10]; 

    do {
        printf("\nMenu Hash Function Digit Extraction\n");
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
                printf("Masukkan jumlah digit yang akan diekstrak: ");
                scanf("%d", &numDigits);
                printf("Masukkan indeks digit yang akan diekstrak (dipisahkan dengan spasi): ");
                for (int i = 0; i < numDigits; i++) {
                    scanf("%d", &digits[i]);
                }

                hashValue = digitExtractionHash(key, tableSize, digits, numDigits);
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
