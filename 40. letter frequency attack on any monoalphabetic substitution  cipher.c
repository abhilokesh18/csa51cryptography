#include <stdio.h>
#include <stdint.h>
#include <string.h>

#define BLOCK_SIZE 8



uint8_t sdes_encrypt(uint8_t block, uint16_t key) {
   
    return block ^ (key & 0xFF);
}

uint8_t sdes_decrypt(uint8_t block, uint16_t key) {
    
    return block ^ (key & 0xFF); 
}


void ctr_mode_encrypt(const uint8_t *plaintext, uint8_t *ciphertext, size_t len, uint16_t key, uint8_t counter) {
    for (size_t i = 0; i < len; i++) {
        
        uint8_t encrypted_counter = sdes_encrypt(counter, key);
        

        ciphertext[i] = plaintext[i] ^ encrypted_counter;
        
      
        counter++;
    }
}

void ctr_mode_decrypt(const uint8_t *ciphertext, uint8_t *plaintext, size_t len, uint16_t key, uint8_t counter) {

    ctr_mode_encrypt(ciphertext, plaintext, len, key, counter);
}

int main() {

    uint8_t plaintext[] = { 0x01, 0x02, 0x04 }; 
    uint16_t key = 0x1FD; 
    uint8_t counter = 0x00; 
    size_t len = sizeof(plaintext) / sizeof(plaintext[0]);
    
    uint8_t ciphertext[len];
    uint8_t decryptedtext[len];
    

    ctr_mode_encrypt(plaintext, ciphertext, len, key, counter);
    

    printf("Ciphertext: ");
    for (size_t i = 0; i < len; i++) {
        printf("%02X ", ciphertext[i]);
    }
    printf("\n");


    ctr_mode_decrypt(ciphertext, decryptedtext, len, key, counter);
    

    printf("Decrypted Plaintext: ");
    for (size_t i = 0; i < len; i++) {
        printf("%02X ", decryptedtext[i]);
    }
    printf("\n");
    
    return 0;
}

OUTPUT: 
Ciphertext: FC FE FB
Decrypted Plaintext: 01 02 04
