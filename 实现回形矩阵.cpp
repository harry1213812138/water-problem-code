#include <stdio.h>
#include <math.h>

void crate(int a[][100],int n)
{
	int p = 0,q = n - 1;
	int count = 0,i;							//p qΪ������к��У�iΪ�仯�����н��л��θ�ֵ   p���� q����

	while(count < n * n)
	{
		for(i = p;i <= q;i++)					//���������Ҹ�ֵ
			a[p][i] = ++count;

		for(i = p+1;i <= q;i++)					//���ұ����¸�ֵ
			a[i][q] = ++count;

		for(i= q-1;i >= p;i--)					//����������ֵ
			a[q][i] = ++count;

		for(i = q-1;i >= p+1;i--)				//��������ϸ�ֵ
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
	int t = 1;									//��ʼ�������һλ��
	printf("��������ξ�����к���:\n");
	scanf("%d%d\n",&m,&n);						//m���� n����
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
		for(j = i;j < n-i-1;j++)	//���뵱ǰ����
			a[i][j] = t++;
		for(j = i;j < m-i-1;j++)	//���뵱ǰ����
			a[j][n-i-1] = t++;
		for(j = m-i-1;j > i;j--)
		{
			if(t <= m * n)
				a[m-i-1][j] = t++;	//�����m - i - 1�е���
		}
		for(j = m-i-1;j > i;j--)
		{
			if(t <= m * n)
				a[j][i] = t++;
		}
	}
	if(t - 1 < m * n)				//�жϵ������к���������ʱ�����ĵ��Ǹ�����û�����룬�����һ������û������
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