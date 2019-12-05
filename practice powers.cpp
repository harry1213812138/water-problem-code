#include <stdio.h>
#define N 5
int main()
{
	int nums[N] = {66,43,3,9,12};
	int i,j;     //循环变量
	int temp;    //临时变量
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
	printf("排序的结果是：\n");
	for(i = 0;i < N; i++)
	{
		printf("%d\t",nums[i]);
	}

	return 0;
}