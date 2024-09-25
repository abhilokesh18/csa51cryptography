#include <stdio.h>
#include <math.h>
int main()
{
	int q,alpha,a,b,x1,x2,y1,y2,i,j,h,k1,k2,e;
	printf("Enter the q value: ");
	scanf("%d",&q);
	printf("Enter alpha value: ");
	scanf("%d",&alpha);
	printf("Enter a value: ");
	scanf("%d",&a);
	printf("Enter b value: ");
	scanf("%d",&b);
	if(a<q)
	{
		i=pow(alpha,a);
		y1=i%q;
	}
	else
	{
		printf("invalid");
	}
	printf("\nThe y1 value: %d",y1);
	if(b<q)
	{
		j=pow(alpha,b);
		y2=j%q;
	}
	else
	{
		printf("invalid");
	}
	printf("\nThe y2 value: %d",y2);
	h=pow(y2,a);
	k1=h%q;
	printf("\nThe key1 is %d",k1);
	e=pow(y1,b);
	k2=e%q;
	printf("\nThe key2 is %d",k2);
	if(k1=k2)
	{
		printf("\nkey is valid");
	}
	else
	{
		printf("\nkey is Invalid");
	}
	return 0;
}
output:
Enter the q value: 3
Enter alpha value: 9
Enter a value: 7
Enter b value: 1
invalid
The y1 value: 0
The y2 value: 0
The key1 is 0
The key2 is 0
key is Invalid
