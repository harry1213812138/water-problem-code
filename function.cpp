#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//�Զ��庯���Ĳ���
//1����Ҫ����ֵ��                  int
//2����������ʲô��                  calc_circle
//3����Ҫ���������������          ()

//�Զ��庯������Щ���     1������ԭ��   2����������   3������ʵ�ֵĴ���


void calc_circle();                                      //����ԭ��
int calc_sum();
int search();                   //����������Ԫ�أ��������±�
//double[] sort();				//ð������
char * password();				//���û�����6λ���룬���������������ֱ����ȷ��������ȷֵ
void pass();					//���û�����6λ���룬���������������ֱ����ȷ��������ȷֵ
double power(double,int);		//����ʵ��pow�����������һ�������ĵڶ�����������
double calc_circles(double);	//����Բ������ĸ�����
int validata(double);			//���зǸ���֤
double calc_rectangle(double,double);			//����������



//
void calc_circle()										//��������
{
	double radius,s;       
	printf("������Բ�뾶��");
	scanf("%lf",&radius);
	s = 3.14 * pow(radius,2);
	printf("s = %.2lf\n",s);						 	//����ʵ��
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
	printf("������Ҫ���ҵĺ��룺");
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
		printf("���������룺");
		scanf("%d",&player);
		if(player == 121381)
		{
			printf("������ȷ\n");
			break;
		}
		else
		{
			printf("����������� ����������\n");
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
	//calc_circle();      //���ü���Բ����ĺ���          //���ú���
	

/*	
	int sum = calc_sum();
	printf("��Ϊ%d\n",sum);
*/



/*
	int num = search();
	if(num != -1)
	{
		printf("����ҵ������±���%d\n",num);
	}
	else
	{
		printf("δ���ҵ�\n");
	}
*/


//	pass();


//	printf("%d��%d�����ǣ�%.2lf\n",5,3,power(5,3));
	

/*
	double radius,s;
	printf("������Բ�뾶��");					//�������ֵ���зǸ��ж�
	do
	{
		scanf("%lf",&radius);
		if(validate(radius))
		{
			printf("�����ֵ����Ϊ���������������룺");
		}
	}while(validate(radius));
	s = calc_circles(radius);
	printf("Բ�ε�����ǣ�%.2lf\n",s);
*/


	double width,height,s;							//һ��Ҫ������
		printf("�����볤�Ϳ�");					//�������ֵ���зǸ��ж�
		do
		{
			scanf("%lf%lf",&width,&height);
			if(validate(width) || validate(height))
			{
				printf("�����ֵ����Ϊ���������������룺");
			}
		}while(validate(width) || validate(height));
		s = calc_rectangle(width,height);
		printf("���ε�����ǣ�%.2lf\n",s);











  
/*	int i;
	int * nums;
	nums = (int *)calloc(5,sizeof(int));
	for(i = 0;i < 5; i++)
	{
		printf("�������%d��Ԫ��",i + 1);
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
	char unit[10][4] = {"��","Ҽ","��","��","��","��","½","��","��","��"};
	printf("�������\n");
	scanf("%d",&money);
	while(money != 0)
	{
		moneys[i] = money % 10;
		money /= 10;
		i++;
	}
	printf("�û������������%dλ\n",i);
	printf("�����е����ݣ�\n");
	for(i -=1;i >= 0; i--)
	{
		printf("%d - %s\t",moneys[i],unit[moneys[i]]);
	}
*/



	return 0;
}
