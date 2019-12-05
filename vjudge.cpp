#include<stdio.h>
#include<math.h>
int main()
{
	int t,n,i,count;
	scanf("%d",&t);
	while(t--)
	{
		count = 0;
		scanf("%d",&n);
		for(i = 1;i < sqrt(n);i++)
		{
			if((i+1)*(i+2) == (n+1))
				continue;
			if((n+1) % (i+1) == 0)
				count++;
		}
		printf("%d\n",count);
	}



	return 0;
}