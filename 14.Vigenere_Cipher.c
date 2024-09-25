#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void encryptMessage(char *plaintext, int *key, int len) {
    for (int i = 0; i < len; i++) {
        if (plaintext[i] >= 'a' && plaintext[i] <= 'z') { 
            printf("%c", ((plaintext[i] - 'a' + key[i]) % 26) + 'A'); 
        } else if (plaintext[i] >= 'A' && plaintext[i] <= 'Z') { 
            printf("%c", ((plaintext[i] - 'A' + key[i]) % 26) + 'A');
        } else {
            printf("%c", plaintext[i]);
        }
    }
    printf("\n");
}

int main() {
    char plaintext[100];
    int key[100], len;

    printf("Enter the plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);
    len = strlen(plaintext);
    if (plaintext[len - 1] == '\n') plaintext[--len] = '\0';

    srand(time(0)); 
    for (int i = 0; i < len; i++) key[i] = rand() % 26;

    printf("Encrypted message: ");
    encryptMessage(plaintext, key, len);

    return 0;
}
