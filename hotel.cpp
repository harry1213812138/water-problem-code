#include <stdio.h>
#include <stdlib.h>     
//�Զ���ͷ�ļ���ʹ��˫����

#define hotel1 872
#define hotel2 1838
#define hotel3 924
#define hotel4 899
#define hotel5 1098
#define discount 0.95

char hotelnames[4][50] = {
	"���޾Ƶ�","�������㳡�Ƶ�","��˹ͼ����˹�����������Ƶ�","˹���ﲼ�����ؾƵ�"
};

//�˵�����
int menu(void);
int night(void);
void showprice(int);


int menu(void)
{
	int choice;
	int i;
	printf("��ѡ��Ҫ��ס�ľƵ꣺\n");
	for(i = 0;i < 4; i++)
	{
		printf("%d.%s\n",i + 1,hotelnames[i]);
	}
	//printf("5.�˳�����\n");  ������
	printf("���������ѡ��");
	scanf("%d",&choice);
	if(choice > 0 && choice < 5)
		printf("���ѡ����:%s\n",hotelnames[choice - 1]);
	else
	{
		do
		{
			printf("ֻ������1-4֮������֣����������룺");
			scanf("%d",&choice);
		}while(choice < 0 || choice > 4);
		printf("���ѡ����:%s\n",hotelnames[choice - 1]); 
	}
	return choice;
}


int main()
{
	menu();
	return 0;
}

