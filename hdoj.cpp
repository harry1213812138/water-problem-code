#include<stdio.h>
int main()
{
	int a[10],n,i,count = 0;
	for(i = 0;i < 10;i++)
	{
		scanf("%d",&a[i]);
	}
	scanf("%d",&n);
	for(i = 0;i < 10;i++)
	{
		if(n + 30 >= a[i])
			count++;
	}
	printf("%d",count);


	return 0;
}
