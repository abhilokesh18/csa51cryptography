#include <stdio.h>
#include <string.h>
#include <ctype.h>

void generateCipher(char *keyword,char *cipher) 
{
    int used[26]={0};
    int keyLen=strlen(keyword);
    int index=0;
    strcpy(cipher,keyword);
    for(int i=0;i<keyLen;i++) 
    {
        if(isalpha(keyword[i])) 
        {
            keyword[i]=toupper(keyword[i]);
            used[keyword[i]-'A']=1;
        }
    }
    for(char ch='A';ch<='Z';ch++) 
    {
        if(!used[ch-'A'])
        {
            cipher[keyLen+index]=ch;
            index++;
        }
    }
    cipher[26]='\0';
}
void encrypt(char *plaintext,char *cipher,char *encrypted) 
{
    int len=strlen(plaintext);
    for (int i=0;i<len;i++) 
    {
        if(isalpha(plaintext[i])) 
        {
            char original=toupper(plaintext[i]);
            encrypted[i]=cipher[original-'A'];
        } 
        else 
        {
            encrypted[i]=plaintext[i];
        }
    }
    encrypted[len]='\0';
}
int main() 
{
    char keyword[]="CIPHER";
    char plaintext[]="HELLO WORLD";
    char cipher[27];
    char encrypted[100];
    generateCipher(keyword,cipher);
    encrypt(plaintext,cipher,encrypted);
    printf("\nPlaintext = %s\n",plaintext);
    printf("\nEncrypted text = %s\n",encrypted);
}
