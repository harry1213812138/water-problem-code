#include <stdio.h>
#include <math.h>

void crate(int a[][100],int n)
{
	int p = 0,q = n - 1;
	int count = 0,i;							//p q为不变的行和列，i为变化的行列进行回形赋值   p是行 q是列

	while(count < n * n)
	{
		for(i = p;i <= q;i++)					//从上面向右赋值
			a[p][i] = ++count;

		for(i = p+1;i <= q;i++)					//从右边向下赋值
			a[i][q] = ++count;

		for(i= q-1;i >= p;i--)					//从下面向左赋值
			a[q][i] = ++count;

		for(i = q-1;i >= p+1;i--)				//从左边向上赋值
			a[i][p] = ++count;
		p++;
		q--;
	}
}


void print(int a[][100],int n)
{
	int i,j;
	for(i = 0;i < n;i++)
	{
		for(j = 0;j < n;j++)
			printf("%3d",a[i][j]);
		printf("\n");
	}
}


int main()
{
/*	int a[100][100];
	int c,m,n,i,j;
	int t = 1;									//初始化数组第一位数
	printf("请输入回形矩阵的行和列:\n");
	scanf("%d%d\n",&m,&n);						//m是行 n是列
	if(m > n)
	{
		if(n % 2 == 0)
			c = n / 2;
		else
			c = n / 2 + 1;
	}
	else
	{
		if(m % 2 == 0)
			c = m / 2;
		else
			c = m / 2 + 1;
	}
	for(i = 0;i < c;i++)
	{
		for(j = i;j < n-i-1;j++)	//输入当前行数
			a[i][j] = t++;
		for(j = i;j < m-i-1;j++)	//输入当前列数
			a[j][n-i-1] = t++;
		for(j = m-i-1;j > i;j--)
		{
			if(t <= m * n)
				a[m-i-1][j] = t++;	//输入第m - i - 1行的数
		}
		for(j = m-i-1;j > i;j--)
		{
			if(t <= m * n)
				a[j][i] = t++;
		}
	}
	if(t - 1 < m * n)				//判断当输入行和列是奇数时最中心的那个数有没有输入，即最后一个数有没有输入
		a[m/2][n/2] = m * n;

	printf("\n");
	for(i = 0;i < m;i++)
	{
		for(j = 0;j < n;j++)
		{
			printf("%4d",a[i][j]);
			if(((j + 1) % n) == 0)
				printf("\n");
		}
	}
*/
	int n,a[100][100];
	scanf("%d",&n);
	crate(a,n);
	print(a,n);


    return 0;
}