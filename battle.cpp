#include <stdio.h>
int main()
{
	double powers[] = {30829,40767,87678,90009,20101};
	double deletepower;     //Ҫɾ����ս��ֵ
	int index = -1;         //Ҫɾ����ս��ֵ���±�
	int i;                  //ѭ������
	int addpower;           //Ҫ���ӵ�ս��ֵ
	int count = 5;
	printf("������Ҫɾ����ս��ֵ��\n");
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
		printf("ɾ��ʧ��\n");
	}else
	{
		for(i = index;i < count; i++)
		{
			powers[i] = powers[i + 1];
		}
		count--;
	}
	printf("ɾ���Ľ���ǣ�\n");
	for(i = 0;i < count; i++)
	{
		printf("%.2lf\t",powers[i]);
	}
	printf("\n������Ҫ�����ս��ֵ��\n");
	scanf("%lf",&addpower);
	powers[count] = addpower;
	count++;
	printf("���ӵĽ���ǣ�\n");
	for(i = 0;i < count; i++)
	{
		printf("%.2lf\t",powers[i]);
	}
	printf("\n");


	return 0;
}