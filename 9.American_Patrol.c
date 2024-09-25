
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define SIZE 200
void findPosition(char keySquare[5][5],char letter,int *row,int *col)
{
    if(letter=='J')
        letter='I';
    for(*row=0;*row<5;(*row)++) 
    {
        for(*col=0;*col<5;(*col)++) 
        {
            if(keySquare[*row][*col]==letter)
                return;
        }
    }
}
void decryptPlayfair(char *cipherText,char key[5][5]) 
{
    int len=strlen(cipherText);
    char decryptedText[SIZE];
    int row1,col1,row2,col2;
    for (int i=0;i<len;i+=2) 
    {
        findPosition(key,cipherText[i],&row1,&col1);
        findPosition(key,cipherText[i+1],&row2,&col2);
        if(row1==row2) 
        {
            decryptedText[i]=key[row1][(col1-1+5)%5];
            decryptedText[i+1]=key[row2][(col2-1+5)%5];
        }
        else if(col1==col2) 
        {
            decryptedText[i]=key[(row1-1+5)%5][col1];
            decryptedText[i+1]=key[(row2-1+5)%5][col2];
        }
        else 
        {
            decryptedText[i]=key[row1][col2];
            decryptedText[i+1]=key[row2][col1];
        }
    }
    decryptedText[len]='\0';
    printf("\nDecrypted Message = \n%s\n",decryptedText);
}
int main() 
{
    char key[5][5]= 
    {
        {'K','Y','J','E','X'},
        {'U','R','E','B','Z'},
        {'W','H','T','Y','F'},
        {'S','K','R','O','L'},
        {'A','C','D','G','M'}
    };
    char ciphertext[]="KXJEY UREBE ZWEHE WRYTU HEYFS KREHE GOYFI WTTTU OLKSY CAJPO BOTEI ZONTX BYBNT GONEY CUZWR GDSON SXBOU YWRHE BAAHY USEDQ";
    int j=0;
    for(int i=0;ciphertext[i];i++)
    {
        if(ciphertext[i]!=' ') 
        {
            ciphertext[j++]=toupper(ciphertext[i]);
        }
    }
    ciphertext[j]='\0';
    decryptPlayfair(ciphertext,key);
}
