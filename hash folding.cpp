#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Fungsi Hash Folding
int foldingHash(char* key, int tableSize) {
    int length = strlen(key);
    int sum = 0;
    int chunk = 3; 

    for (int i = 0; i < length; i += chunk) {
        char temp[chunk + 1];
        strncpy(temp, key + i, chunk);
        temp[chunk] = '\0';

        sum += atoi(temp);
    }

    return sum % tableSize;
}

int main() {
    int choice, tableSize, hashValue;
    char key[100];

    do {
        printf("\nMenu Hash Function Folding\n");
        printf("1. Hitung Hash Value\n");
        printf("2. Keluar\n");
        printf("Pilihan Anda: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Masukkan Key (string): ");
                scanf("%s", key);
                printf("Masukkan Table Size: ");
                scanf("%d", &tableSize);

                hashValue = foldingHash(key, tableSize);
                printf("Hash Value dari '%s' adalah %d\n", key, hashValue);
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
