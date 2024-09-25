#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define SIZE 100
void preparePlainText(char *plaintext) 
{
    int len=strlen(plaintext);
    for(int i=0;i<len;i++) 
    {
        if(!isalpha(plaintext[i])) 
        {
            for(int j=i;j<len;j++) 
            {
                plaintext[j]=plaintext[j+1];
            }
            len--;
            i--;
        } 
        else if(plaintext[i]=='J') 
        {
            plaintext[i]='I';
        }
    }
    if (len%2!=0) 
    {
        plaintext[len++]='X';
    }
    plaintext[len]='\0';
}
void findPosition(char matrix[5][5],char letter,int *row,int *col) 
{
    if(letter=='J') 
    {
        letter='I';
    }
    for(*row=0;*row<5;(*row)++) 
    {
        for(*col=0;*col<5;(*col)++) 
        {
            if(matrix[*row][*col]==letter) 
            {
                return;
            }
        }
    }
}
void encryptPlayfair(char *plaintext,char matrix[5][5],char *encryptedText) 
{
    int len=strlen(plaintext);
    int row1,col1,row2,col2;
    int index=0;
    for(int i=0;i<len;i+=2) 
    {
        findPosition(matrix,plaintext[i],&row1,&col1);
        findPosition(matrix,plaintext[i+1],&row2,&col2);

        if(row1==row2) 
        {
            encryptedText[index++]=matrix[row1][(col1+1)%5];
            encryptedText[index++]=matrix[row2][(col2+1)%5];
        } 
        else if(col1==col2) 
        {
            encryptedText[index++]=matrix[(row1+1)%5][col1];
            encryptedText[index++]=matrix[(row2+1)%5][col2];
        } 
        else 
        {
            encryptedText[index++]=matrix[row1][col2];
            encryptedText[index++]=matrix[row2][col1];
        }
    }
    encryptedText[index]='\0';
}
int main() 
{
    char keyMatrix[5][5] = 
    {
        {'M','F','H','I','K'},
        {'U','N','O','P','Q'},
        {'Z','V','W','X','Y'},
        {'E','L','A','R','G'},
        {'D','S','T','B','C'}
    };
    char plaintext[] ="Must see you over Cadogan West. Coming at once";
    char processedText[SIZE];
    char encryptedText[SIZE*2];
    strcpy(processedText,plaintext);
    preparePlainText(processedText);
    encryptPlayfair(processedText,keyMatrix,encryptedText);
    printf("\nPlaintext = %s\n",plaintext);
    printf("\nEncrypted text = %s\n",encryptedText);
}
