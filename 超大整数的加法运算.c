#include <stdio.h>
#include <string.h>

int main()
{
/*	char a[101],b[101];
	int i,j,m,n,k,h,count = 0;
	scanf("%d",&h);
	while(count < h)
	{
		scanf("%s",&a);
		scanf("%s",&b);
		m = strlen(a);
		k = n = strlen(b);
		if(m > k)
			k = m;						//k是两个字符串长度最大值
		a[k + 1] = 0;
		for(i = 0;i <= k;i++)			//数组a右对齐
			a[k - i] = a[m - i - 1];
		for(i = 0;i <= k - m;i++)		//数组a最高位重置为0
			a[i] = '0';
		for(i = 0;i < k;i++)
			b[k - i] = b[n - i - 1];	//数组b右对齐
		for(i = 0;i <= k - n;i++)
			b[i] = '0';					//数组b最高位重置为0
		j = 0;
		for(i = 0;i < k;i++)
		{
			j = (a[k - i] + b[k - i] + j - 96);		//从最低位开始，字符转换为整数相加，再加低进位，赋给j
			a[k - i] = j % 10 + 48;		//模10的余数为该位的数
			j = j / 10;					//作为进位数
		}
		if(a[0] == '0')
			printf("%s\n",a + 1);
		else
			printf("%s\n",a);
		count++;
	}
*/


	int n,j;
	scanf("%d",&n);
	for(j = 0;j < n;j++)
	{
		int i,ka,kb,k,count = 0;
		char a[101] = {0},b[101] = {0},c[101] = {0};
		scanf("%s",a);
		scanf("%s",b);
		ka = strlen(a);
		k = kb = strlen(b);
		if(ka > k)
			k = ka;				//k is the max of ka and kb
		for(i = 0;i <= ka;i++)
			a[k - i] = a[ka - i - 1];		//right shift array a
		for(i = 0;i <= k - ka;i++)
			a[i] = '0';						//highest position place 0
		for(i = 0;i <= k;i++)
			b[k - i] = b[kb - i - 1];		//right shift array b
		for(i = 0;i <= k - kb;i++)
			b[i] = '0';						//highest position place 0
		for(i = k;i > 0;i--)
		{
			count = a[i] + b[i] + count - '0' - '0';
			c[i] = count % 10 + '0';
			count /= 10;
		}
		if(0 == count)
		{
			printf("%s\n",c + 1);
		}
		else
		{
			c[0] = count % 10 + '0';
			printf("%s\n",
				c);
		}
	}



	

	return 0;
} 