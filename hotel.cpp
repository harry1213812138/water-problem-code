#include <stdio.h>
#include <stdlib.h>     
//自定义头文件名使用双引号

#define hotel1 872
#define hotel2 1838
#define hotel3 924
#define hotel4 899
#define hotel5 1098
#define discount 0.95

char hotelnames[4][50] = {
	"贝罗酒店","香榭丽舍广场酒店","阿斯图里亚斯特拉奥培拉酒店","斯克里布索菲特酒店"
};

//菜单函数
int menu(void);
int night(void);
void showprice(int);


int menu(void)
{
	int choice;
	int i;
	printf("请选择要入住的酒店：\n");
	for(i = 0;i < 4; i++)
	{
		printf("%d.%s\n",i + 1,hotelnames[i]);
	}
	//printf("5.退出程序\n");  待升级
	printf("请输入你的选择：");
	scanf("%d",&choice);
	if(choice > 0 && choice < 5)
		printf("你的选择是:%s\n",hotelnames[choice - 1]);
	else
	{
		do
		{
			printf("只能输入1-4之间的数字，请重新输入：");
			scanf("%d",&choice);
		}while(choice < 0 || choice > 4);
		printf("你的选择是:%s\n",hotelnames[choice - 1]); 
	}
	return choice;
}


int main()
{
	menu();
	return 0;
}

