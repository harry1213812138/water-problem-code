#include <stdio.h>
int main()
{
	/*int math = 87,eng = 72,comp = 93;
	printf("math = 87, eng = 72, comp = 93, average = %d\n",(math + eng + comp) / 3);*/
	int a,b;
	scanf("%d%d",&a,&b);
	printf("%d + %d = %d\n",a,b,a + b);
	printf("%d - %d = %d\n",a,b,a - b);
	printf("%d * %d = %d\n",a,b,a * b);
	printf("%d / %d = %d\n",a,b,a / b);
	return 0;
}