#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 2 
void multiplyMatrices(int a[SIZE][SIZE], int b[SIZE][1], int result[SIZE][1]) {
    for (int i = 0; i < SIZE; i++) {
        result[i][0] = 0;
        for (int k = 0; k < SIZE; k++) {
            result[i][0] += a[i][k] * b[k][0];
        }
        result[i][0] %= 26; 
    }
}

void inverseMatrix(int key[SIZE][SIZE], int inv[SIZE][SIZE]) {
    int det = (key[0][0] * key[1][1] - key[0][1] * key[1][0]) % 26;
    if (det < 0) det += 26; 
    int invDet = 0;

    for (int i = 1; i < 26; i++) {
        if ((det * i) % 26 == 1) {
            invDet = i;
            break;
        }
    }

    inv[0][0] = (key[1][1] * invDet) % 26;
    inv[0][1] = (-key[0][1] * invDet) % 26;
    inv[1][0] = (-key[1][0] * invDet) % 26;
    inv[1][1] = (key[0][0] * invDet) % 26;

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (inv[i][j] < 0) inv[i][j] += 26; 
        }
    }
}

int charToInt(char c) {
    return c - 'a';
}

char intToChar(int i) {
    return i + 'a';
}

void encryptHillCipher(char* plaintext, int key[SIZE][SIZE], char* ciphertext) {
    int length = strlen(plaintext);
    int plaintextMatrix[SIZE][1];
    int keyMatrix[SIZE][SIZE] = {0};
    int resultMatrix[SIZE][1];

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            keyMatrix[i][j] = key[i][j];
        }
    }

    for (int i = 0; i < length; i += SIZE) {
        for (int j = 0; j < SIZE; j++) {
            if (i + j < length) {
                plaintextMatrix[j][0] = charToInt(plaintext[i + j]);
            } else {
                plaintextMatrix[j][0] = 0; 
            }
        }

        multiplyMatrices(keyMatrix, plaintextMatrix, resultMatrix);

        for (int j = 0; j < SIZE; j++) {
            ciphertext[i + j] = intToChar(resultMatrix[j][0]);
        }
    }
    ciphertext[length] = '\0'; 
}

void decryptHillCipher(char* ciphertext, int key[SIZE][SIZE], char* plaintext) {
    int length = strlen(ciphertext);
    int ciphertextMatrix[SIZE][1];
    int keyMatrix[SIZE][SIZE] = {0};
    int invKeyMatrix[SIZE][SIZE] = {0};
    int resultMatrix[SIZE][1];

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            keyMatrix[i][j] = key[i][j];
        }
    }

    inverseMatrix(keyMatrix, invKeyMatrix);

    for (int i = 0; i < length; i += SIZE) {
        for (int j = 0; j < SIZE; j++) {
            ciphertextMatrix[j][0] = charToInt(ciphertext[i + j]);
        }

        multiplyMatrices(invKeyMatrix, ciphertextMatrix, resultMatrix);

        for (int j = 0; j < SIZE; j++) {
            plaintext[i + j] = intToChar(resultMatrix[j][0]);
        }
    }
    plaintext[length] = '\0'; 
}

int main() {
    char plaintext[100];
    int key[SIZE][SIZE] = {{9, 4}, {5, 7}};
    char ciphertext[100];
    char decryptedtext[100];

    printf("Enter plaintext (lowercase letters only): ");
    fgets(plaintext, sizeof(plaintext), stdin);
    plaintext[strcspn(plaintext, "\n")] = '\0'; 
    char temp[100];
    int index = 0;
    for (int i = 0; plaintext[i] != '\0'; i++) {
        if (plaintext[i] != ' ') {
            temp[index++] = plaintext[i];
        }
    }
    temp[index] = '\0';
    strcpy(plaintext, temp);

    encryptHillCipher(plaintext, key, ciphertext);
    printf("Ciphertext: %s\n", ciphertext);

    decryptHillCipher(ciphertext, key, decryptedtext);
    printf("Decrypted text: %s\n", decryptedtext);

    return 0;
}
