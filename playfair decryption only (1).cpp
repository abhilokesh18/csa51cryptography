#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define SIZE 5

int main() {
    char key[] = "PT109"; // Example key
    char cipherText[] = "KXJEYUREBEZWEHEWRYTUBEYFSKREHEGOYFIWTTTUOLKSYCAJPOBOTEIZONTXBYBNTGONEYCUZWRGDSONSXBOUYWRHEBAAHYUSEDQ";
    char grid[SIZE][SIZE];
    char plainText[256];
    int alpha[26] = {0};
    int k = 0;

    // Create Playfair grid
    int i, j;
    for (i = 0; key[i]; i++) {
        char ch = toupper(key[i]);
        if (ch == 'J') ch = 'I'; // Treat 'J' as 'I'
        if (isalpha(ch) && !alpha[ch - 'A']) {
            grid[k / SIZE][k % SIZE] = ch;
            alpha[ch - 'A'] = 1;
            k++;
        }
    }

    for (char ch = 'A'; ch <= 'Z'; ch++) {
        if (ch == 'J') continue; // Skip 'J'
        if (!alpha[ch - 'A']) {
            grid[k / SIZE][k % SIZE] = ch;
            k++;
        }
    }

    // Decrypt the cipher text
    k = 0; // Reset index for plainText
    for (i = 0; cipherText[i]; i += 2) {
        char first = toupper(cipherText[i]);
        char second = toupper(cipherText[i + 1]);
        int r1, c1, r2, c2;

        // Find positions of first character
        for (j = 0; j < SIZE; j++) {
            for (int m = 0; m < SIZE; m++) {
                if (grid[j][m] == first) {
                    r1 = j;
                    c1 = m;
                }
                if (grid[j][m] == second) {
                    r2 = j;
                    c2 = m;
                }
            }
        }

        // Decrypt using Playfair rules
        if (r1 == r2) { // Same row
            plainText[k++] = grid[r1][(c1 + SIZE - 1) % SIZE];
            plainText[k++] = grid[r2][(c2 + SIZE - 1) % SIZE];
        } else if (c1 == c2) { // Same column
            plainText[k++] = grid[(r1 + SIZE - 1) % SIZE][c1];
            plainText[k++] = grid[(r2 + SIZE - 1) % SIZE][c2];
        } else { // Rectangle
            plainText[k++] = grid[r1][c2];
            plainText[k++] = grid[r2][c1];
        }
    }
    plainText[k] = '\0'; // Null terminate the string

    // Print the decrypted plain text
    printf("Decrypted Message: %s\n", plainText);

    return 0;
}

