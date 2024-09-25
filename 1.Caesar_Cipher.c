#include <stdio.h>
#include <string.h>

int main() 
{
    char message[100];
    int key, i;

    printf("Enter a message: ");
    gets(message);
  
    printf("Enter the key (shift): ");
    scanf("%d", &key);

    for (i = 0; message[i] != '\0'; i++) 
    {
        char character = message[i];

        if (character >= 'a' && character <= 'z') 
        {
            character = (character - 'a' + key) % 26 + 'a';
        } 
        else if (character >= 'A' && character <= 'Z') 
        {
            character = (character - 'A' + key) % 26 + 'A';
        }

        message[i] = character;
    }

    printf("Encrypted message: %s\n", message);

    for (i = 0; message[i] != '\0'; i++) 
    {
        char character = message[i];

        if (character >= 'a' && character <= 'z') 
        {
            character = (character - 'a' - key + 26) % 26 + 'a';
        } 
        else if (character >= 'A' && character <= 'Z') 
        {
            character = (character - 'A' - key + 26) % 26 + 'A';
        }

        message[i] = character;
    }

    printf("Decrypted message: %s\n", message);

    return 0;
}
