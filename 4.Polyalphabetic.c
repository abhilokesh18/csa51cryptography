#include<stdio.h>
#include<string.h>
int main(){
	char key[100];
	char plain[100];
	char cipher[100];
	printf("Enter key: ");
	scanf("%s",key);
	printf("Enter plain text: ");
	scanf("%s",plain);
	int i,l=strlen(plain),l2=strlen(key);
	for(i=0;i<l;i++){
		char c1=plain[i];
		char c2=key[i%l2];
		if(c1>='A'&&c1<='Z'){
			cipher[i]=((c1-'A')+(c2-'A'))%26+'A';
		}
	}
	printf("Cipher text : %s",cipher);
	return 0;
}
