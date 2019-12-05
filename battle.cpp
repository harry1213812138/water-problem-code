#include <stdio.h>
int main()
{
	double powers[] = {30829,40767,87678,90009,20101};
	double deletepower;     //要删除的战力值
	int index = -1;         //要删除的战力值的下标
	int i;                  //循环变量
	int addpower;           //要增加的战力值
	int count = 5;
	printf("请输入要删除的战力值：\n");
	scanf("%lf",&deletepower);
	for(i = 0;i < count; i++)
	{
		if(deletepower == powers[i])
		{
			index = i;
			break;
		}	
	}
	if(-1 == index)
	{
		printf("删除失败\n");
	}else
	{
		for(i = index;i < count; i++)
		{
			powers[i] = powers[i + 1];
		}
		count--;
	}
	printf("删除的结果是：\n");
	for(i = 0;i < count; i++)
	{
		printf("%.2lf\t",powers[i]);
	}
	printf("\n请输入要插入的战力值：\n");
	scanf("%lf",&addpower);
	powers[count] = addpower;
	count++;
	printf("增加的结果是：\n");
	for(i = 0;i < count; i++)
	{
		printf("%.2lf\t",powers[i]);
	}
	printf("\n");


	return 0;
}