#include <stdio.h>
#define N 5
int main()
{
	int nums[N] = {66,43,3,9,12};
	int i,j;     //ѭ������
	int temp;    //��ʱ����
	for(i = 0;i < N - 1; i++)
	{
		for(j = 0;j < N - i - 1; j++)
		{
			if(nums[j] < nums[j + 1])
			{
				temp = nums[j];
				nums[j] = nums[j + 1];
				nums[j + 1] = temp;

			}
		}
	}
	printf("����Ľ���ǣ�\n");
	for(i = 0;i < N; i++)
	{
		printf("%d\t",nums[i]);
	}

	return 0;
}