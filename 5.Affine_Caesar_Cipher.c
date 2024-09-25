#include <stdio.h>
#include <string.h>

int main() 
{
    int a = 5; 
    int b = 4;
    char plaintext[] = "HELLO BHARGAV";
    int n = strlen(plaintext);
    char ciphertext[n + 1]; 
    for(int i = 0; i < n; i++) 
    {
        char p = plaintext[i];
        if(p >= 'A' && p <= 'Z') 
        {
            ciphertext[i] = 'A' + (a * (p - 'A') + b) % 26;
        }
        else 
        {
            ciphertext[i] = p;
        }
    }
    ciphertext[n] = '\0'; 

    printf("\nPlaintext = %s\n", plaintext);
    printf("\nCiphertext = %s\n", ciphertext);

    return 0;
}
