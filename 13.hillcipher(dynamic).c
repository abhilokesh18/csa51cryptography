#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LEN 100

// Function to convert a character to its numeric representation (0-25)
int charToNum(char c) {
    if (isupper(c)) {
        return c - 'A';
    } else if (islower(c)) {
        return c - 'a';
    }
    return -1; // Return -1 for non-alphabet characters
}

// Function to convert a number (0-25) to its corresponding uppercase character
char numToChar(int num) {
    return num + 'A';
}

// Function to encrypt plaintext using Hill cipher
void encryptHill(char *text, int *keyMatrix, int keySize) {
    int i, j, k;
    int textLen = strlen(text);
    int encrypted[MAX_LEN] = {0};

    for (i = 0; i < textLen; i += keySize) {
        for (j = 0; j < keySize; j++) {
            int sum = 0;
            for (k = 0; k < keySize; k++) {
                sum += keyMatrix[j * keySize + k] * charToNum(text[i + k]);
            }
            encrypted[i + j] = sum % 26;
        }
    }

    for (i = 0; i < textLen; i++) {
        text[i] = numToChar(encrypted[i]);
    }
    text[textLen] = '\0'; // Null-terminate the encrypted text
}

int main() {
    char plaintext[MAX_LEN];
    int keySize;

    printf("Enter the plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);
    plaintext[strcspn(plaintext, "\n")] = '\0'; // Remove newline character

    printf("Enter the size of the key matrix: ");
    scanf("%d", &keySize);

    if (keySize <= 0 || keySize > MAX_LEN) {
        printf("Invalid key size.\n");
        return 1;
    }

    int i, j;
    int keyMatrix[MAX_LEN * MAX_LEN];

    printf("Enter the key matrix (row by row):\n");
    for (i = 0; i < keySize; i++) {
        for (j = 0; j < keySize; j++) {
            scanf("%d", &keyMatrix[i * keySize + j]);
        }
    }

    int textLen = strlen(plaintext);
    int padding = keySize - (textLen % keySize);

    if (padding < keySize) {
        for (i = 0; i < padding; i++) {
            plaintext[textLen + i] = 'X'; // Padding character
        }
        plaintext[textLen + padding] = '\0';
    }

    encryptHill(plaintext, keyMatrix, keySize);
    printf("Encrypted text: %s\n", plaintext);

    return 0;
}
