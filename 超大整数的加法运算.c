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
			k = m;						//k�������ַ����������ֵ
		a[k + 1] = 0;
		for(i = 0;i <= k;i++)			//����a�Ҷ���
			a[k - i] = a[m - i - 1];
		for(i = 0;i <= k - m;i++)		//����a���λ����Ϊ0
			a[i] = '0';
		for(i = 0;i < k;i++)
			b[k - i] = b[n - i - 1];	//����b�Ҷ���
		for(i = 0;i <= k - n;i++)
			b[i] = '0';					//����b���λ����Ϊ0
		j = 0;
		for(i = 0;i < k;i++)
		{
			j = (a[k - i] + b[k - i] + j - 96);		//�����λ��ʼ���ַ�ת��Ϊ������ӣ��ټӵͽ�λ������j
			a[k - i] = j % 10 + 48;		//ģ10������Ϊ��λ����
			j = j / 10;					//��Ϊ��λ��
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