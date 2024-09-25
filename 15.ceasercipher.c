#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define ALPHABET_SIZE 26
#define MAX_LEN 100
#define TOP_N 10

// Function to convert a character to its numeric representation (0-25)
int charToNum(char c) {
    return toupper(c) - 'A';
}

// Function to convert a number (0-25) to its corresponding uppercase character
char numToChar(int num) {
    return num + 'A';
}

// Function to perform frequency analysis and return letter frequencies
void analyzeFrequency(const char *text, int *frequency) {
    int i;
    for (i = 0; i < ALPHABET_SIZE; i++) {
        frequency[i] = 0;
    }

    while (*text) {
        if (isalpha(*text)) {
            frequency[charToNum(*text)]++;
        }
        text++;
    }
}

// Function to shift ciphertext by a given shift value
void shiftCiphertext(const char *ciphertext, int shift, char *plaintext) {
    int i;
    for (i = 0; ciphertext[i] != '\0'; i++) {
        if (isalpha(ciphertext[i])) {
            int num = charToNum(ciphertext[i]);
            num = (num - shift + ALPHABET_SIZE) % ALPHABET_SIZE;
            plaintext[i] = numToChar(num);
        } else {
            plaintext[i] = ciphertext[i];
        }
    }
    plaintext[i] = '\0';
}

// Function to print the top N plaintexts
void printTopPlaintexts(const char *ciphertext, int topN) {
    int i;
    char plaintext[MAX_LEN];
    
    printf("Top %d possible plaintexts:\n", topN);
    for (i = 0; i < ALPHABET_SIZE && i < topN; i++) {
        shiftCiphertext(ciphertext, i, plaintext);
        printf("%2d: %s\n", i, plaintext);
    }
}

int main() {
    char ciphertext[MAX_LEN];
    int topN;

    // Input ciphertext
    printf("Enter the ciphertext (only letters and spaces): ");
    fgets(ciphertext, sizeof(ciphertext), stdin);
    ciphertext[strcspn(ciphertext, "\n")] = '\0'; // Remove newline character

    // Input the number of top possible plaintexts to display
    printf("Enter the number of top possible plaintexts to display: ");
    scanf("%d", &topN);
    if (topN <= 0 || topN > ALPHABET_SIZE) {
        printf("Invalid number of top plaintexts.\n");
        return 1;
    }

    // Print the top N possible plaintexts
    printTopPlaintexts(ciphertext, topN);

    return 0;
}
