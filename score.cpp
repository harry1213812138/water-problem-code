#include <stdio.h>
int main()
{
	//�ĸ�ͬѧ�����ſγɼ�       ��ά����
	int i,j;    //���ѭ���� �ڲ�ѭ����
	double score[4][3] = {
		{86,99,78},
		{96,66,75},
		{98,97,94},
		{87,92,90}       };
	//��ӡ��λͬѧ�ĳɼ�
	printf("�ɼ���\n");
	printf("����\t��ѧ\tӢ��\n");
	for(i = 0;i < 4; i++)
	{
		for(j = 0;j < 3; j++)
		{
			printf("%-8.2lf",score[i][j]);
		}
		printf("\n");
	}



	return 0;
}