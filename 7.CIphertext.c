#include <stdio.h>
#include <string.h>

#define MAX_CHARS 256

// Function to count frequency of characters
void countFrequency(const char *ciphertext, int freq[MAX_CHARS]) {
    for (int i = 0; ciphertext[i] != '\0'; i++) {
        freq[(unsigned char)ciphertext[i]]++;
    }
}

// Function to print frequency of characters
void printFrequency(int freq[MAX_CHARS]) {
    printf("Character Frequencies:\n");
    for (int i = 0; i < MAX_CHARS; i++) {
        if (freq[i] > 0) {
            printf("'%c': %d\n", i, freq[i]);
        }
    }
}

// Function to decrypt using a simple substitution cipher
void decrypt(const char *ciphertext, const char *substitution, char *plaintext) {
    for (int i = 0; ciphertext[i] != '\0'; i++) {
        if (ciphertext[i] >= '0' && ciphertext[i] <= '9') {
            plaintext[i] = substitution[ciphertext[i] - '0'];
        } else {
            plaintext[i] = ciphertext[i]; // Keep non-numeric as is
        }
    }
    plaintext[strlen(ciphertext)] = '\0'; // Null-terminate
}

int main() {
    const char *ciphertext = "53‡‡†305))6*;4826)4‡.)4‡);806*;48†8¶60))85;;]8*;:‡*8†83 (88)5*†;46(;88*96*?;8)*‡(;485);5*†2:*‡(;4956*2(5*—4)8¶8*;4069285);)6†8)4‡‡;1(‡9;48081;8:8‡1;48†85;4)485†528806*81 (‡9;48;(88;4(‡?34;48)4‡;161;:188;‡?";
    
    int freq[MAX_CHARS] = {0};
    countFrequency(ciphertext, freq);
    
    // Print character frequencies
    printFrequency(freq);
    
    // Define substitution mapping based on analysis (example only)
    // This should be adjusted based on actual analysis
    const char substitution[10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
    
    char plaintext[strlen(ciphertext) + 1];
    
    decrypt(ciphertext, substitution, plaintext);
    
    printf("Decrypted Text: %s\n", plaintext);
    
    return 0;
}
