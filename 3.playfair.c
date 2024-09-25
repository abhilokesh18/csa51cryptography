#include <stdio.h>
#include <string.h>

int main() {
    int keyMatrix[3][3];
    char input[100];
    int len;

    printf("Enter the 3x3 key matrix:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            scanf("%d", &keyMatrix[i][j]);
        }
    }

    printf("Enter the plaintext (in uppercase): ");
    scanf("%s", input);
    len = strlen(input);
    while (len % 3 != 0) { 
        input[len] = 'X';  
        len++;
    }
    input[len] = '\0';  
    int encrypted[len];
    printf("Plaintext: %s\n", input);
    for (int i = 0; i < len; i += 3) {
        for (int j = 0; j < 3; j++) {
            encrypted[i + j] = 0;
            for (int k = 0; k < 3; k++) {
                encrypted[i + j] += keyMatrix[j][k] * (input[i + k] - 'A');
            }
            encrypted[i + j] = (encrypted[i + j] % 26 + 26) % 26; 
        }
    }

    printf("Ciphertext: ");
    for (int i = 0; i < len; i++) {         
        printf("%c", encrypted[i] + 'A'); 
    }
    printf("\n");

    return 0;
}
