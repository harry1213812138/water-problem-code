#include <stdio.h>
#include <string.h>
int main()
{
	int a,b,c,n;
	scanf("%d",&n);
	a = n % 10;
	b = (n % 100 - a)/10;
	c = (n - n % 100)/100;
	printf("%d%d%d",a,b,c);


	return 0;
}