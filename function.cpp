#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//自定义函数的步骤
//1、需要返回值吗？                  int
//2、函数名是什么？                  calc_circle
//3、需要给这个函数参数吗？          ()

//自定义函数由哪些组成     1、函数原型   2、函数定义   3、函数实现的代码


void calc_circle();                                      //函数原型
int calc_sum();
int search();                   //查找数组中元素，并返回下标
//double[] sort();				//冒泡排序
char * password();				//请用户输入6位密码，输入错误重新输入直到正确并返回正确值
void pass();					//请用户输入6位密码，输入错误重新输入直到正确并返回正确值
double power(double,int);		//自行实现pow函数，即求第一个参数的第二个参数次幂
double calc_circles(double);	//计算圆形面积的改良版
int validata(double);			//进行非负验证
double calc_rectangle(double,double);			//计算矩形面积



//
void calc_circle()										//函数定义
{
	double radius,s;       
	printf("请输入圆半径：");
	scanf("%lf",&radius);
	s = 3.14 * pow(radius,2);
	printf("s = %.2lf\n",s);						 	//函数实现
}

//
int calc_sum()
{
	int i;
	int sum = 0;
	for(i = 1;i <=100; i++)
	{
		if(i % 2 == 0)
			sum += i;
	}
	return sum;
}

//
int search()
{
	int find,i;
	int index = -1;
	int score[5] = {67,32,54,65,57};
	printf("请输入要查找的号码：");
	scanf("%d",&find);
	for(i = 0;i < 5; i++)
	{
		if(find == score[i])
		{
			index = i;
			break;
		}
	}
		return index;
}

//
void pass()
{
	int player,i;
	int pass = 121381;
	for(i = 0;; i++)
	{
		printf("请输入密码：");
		scanf("%d",&player);
		if(player == 121381)
		{
			printf("密码正确\n");
			break;
		}
		else
		{
			printf("密码输入错误 请重新输入\n");
			continue;
		}
	}
}

//
double power(double num1,int num2)
{
	double result = 1;
	int i;
	for(i = 0;i < num2; i++)
	{
		result *= num1;
	}
	return result;
}

double calc_circles(double radius)
{
	double s = 3.14 * pow(radius,2);
	return s;
}

//
int validate(double num)
{
	return num < 0;
}

//
double calc_rectangle(double width,double height)
{
	return width * height;
}





int main()
{
	//calc_circle();      //调用计算圆面积的函数          //调用函数
	

/*	
	int sum = calc_sum();
	printf("和为%d\n",sum);
*/



/*
	int num = search();
	if(num != -1)
	{
		printf("你查找到号码下标是%d\n",num);
	}
	else
	{
		printf("未查找到\n");
	}
*/


//	pass();


//	printf("%d的%d次幂是：%.2lf\n",5,3,power(5,3));
	

/*
	double radius,s;
	printf("请输入圆半径：");					//对输入的值进行非负判断
	do
	{
		scanf("%lf",&radius);
		if(validate(radius))
		{
			printf("输入的值不能为负数，请重新输入：");
		}
	}while(validate(radius));
	s = calc_circles(radius);
	printf("圆形的面积是：%.2lf\n",s);
*/


	double width,height,s;							//一定要先申明
		printf("请输入长和宽：");					//对输入的值进行非负判断
		do
		{
			scanf("%lf%lf",&width,&height);
			if(validate(width) || validate(height))
			{
				printf("输入的值不能为负数，请重新输入：");
			}
		}while(validate(width) || validate(height));
		s = calc_rectangle(width,height);
		printf("矩形的面积是：%.2lf\n",s);











  
/*	int i;
	int * nums;
	nums = (int *)calloc(5,sizeof(int));
	for(i = 0;i < 5; i++)
	{
		printf("请输入第%d个元素",i + 1);
		scanf("%d",&nums[i]);
	}
	for(i = 0;i < 5; i++)
	{
		printf("%d\n",*(nums + i));
	}
	free(nums);
	nums = NULL;
*/

/*	int money;
	int i = 0;
	int moneys[6];
	char unit[10][4] = {"零","壹","贰","叁","肆","伍","陆","柒","捌","玖"};
	printf("请输入金额：\n");
	scanf("%d",&money);
	while(money != 0)
	{
		moneys[i] = money % 10;
		money /= 10;
		i++;
	}
	printf("用户输入的数字有%d位\n",i);
	printf("数组中的内容：\n");
	for(i -=1;i >= 0; i--)
	{
		printf("%d - %s\t",moneys[i],unit[moneys[i]]);
	}
*/



	return 0;
}
