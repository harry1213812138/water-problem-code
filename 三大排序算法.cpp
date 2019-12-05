/*#include <stdio.h>
#include <stdlib.h>


void insert_sort(int*x,int n);		//插入排序
void select_sort(int *x,int n);		//选择排序
void bubble_sort(int *x,int n);		//冒泡排序
void quick_sort(int *a,int left,int right);
void bucket_sort(int *a,int n);

					




void insert_sort(int *x,int n)						
{
	int i,j,t;
	for(i = 1;i < n;i++)			//共循环n - 1次，从下标为1开始循环，a[0]默认为排好的序列
	{
		t = *(x + i);
		for(j = i - 1;j >= 0 && t < *(x + j);j--)		//找到拿出来的数的位置
		{
			*(x + j + 1) = *(x + j);					//把他后面所有的数向后移一位
		}
		*(x + j + 1) = t;								//找到并且移好位置后把他放进去
	}													//大循环结束 如此共循环n - 1次
}


void select_sort(int *x,int n)
{
	int i,j,min,t;
	for(i = 0;i < n - 1;i++)				//共n个数，比较n - 1遍
	{	
		min = i;							//将a[i]视为最小数 记录下标i
		for(j = i + 1;j < n;j++)			//每个数比较n - i - 1次
		{
			if(*(x + j) < *(x + min))
			{
				min = j;				//如果出现更小的数，标记
			}
		}
		if(min != i)					//如果有最小数，交换	//不能赋值，只能交换
		{
			t = *(x + i);
			*(x + i) = *(x + min);
			*(x + min) = t;
		}
	}
}


void bubble_sort(int *x,int n)
{
	int i,j,t;
	for(i = 0;i < n - 1;i++)
	{
		for(j = 0;j < n - i - 1;j++)
		{
			if(*(x + j + 1) < *(x + j))
			{
				t = *(x + j + 1);
				*(x + j + 1) = *(x + j);
				*(x + j) = t;
			}
		}
	}
}



void quick_sort(int *a,int left,int right)
{
	int i,j,t,damo;
	i = left;
	j = right;
	damo = a[left];


	if(left >= right)
		return;

	while(i < j)
	{
		while(a[j] >= damo && i < j)
			j--;
		while(a[i] <= damo && i < j)
			i++;
		t = a[i];
		a[i] = a[j];
		a[j] = t;
	}
	a[left] = a[i];
	a[i] = damo;


	quick_sort(a,left,i-1);
	quick_sort(a,i+1,right);
}



void bucket_sort(int *a,int n)
{
	int book[10] = {0},i;
	for(i = 0;i < n;i++)
	{
		book[a[i]] = 1;
	}
	for(i = 0;i < 10;i++)
	{
		if(book[i] != 0)
			printf("%d",i);
	}
	printf("\n");
}








int main()
{
	int a[5] = {7,5,2,6,4},i;
//	insert_sort(a,5);
//	select_sort(a,5);
//	bubble_sort(a,5);
	quick_sort(a,0,4);
//	bucket_sort(a,5);
	for(i = 0;i < 5;i++)
		printf("%d\t",a[i]);


    return 0;
}
*/










#include<stdio.h>
#include<string.h>
int n,h[999];


void swap(int x,int y)
{
	int t;
	t = h[x];
	h[x] = h[y];
	h[y] = t;
}


void siftdown(int i)
{
	int t,flag = 0;
	while(i * 2 <= n && flag == 0)
	{
		if(h[i] > h[i*2])
			t = i * 2;
		else
			t = i;
		if(i*2+1 <= n && h[t] > h[i*2+1])
			t = i * 2 + 1;
		if(t != i)
		{
			swap(i,t);
			i = t;
		}
		else
			flag = 1;
	}
}


void creat()
{
	int i;
	for(i = n / 2;i >= 1;i--)
		siftdown(i);
}


int deletemin()
{
	int t;
	t = h[1];
	h[1] = h[n];
	n--;
	siftdown(1);
	return t;
}

int main()
{
	int i,num;
	scanf("%d",&num);
	n = num;
	for(i = 1;i <= num;i++)
	scanf("%d",&h[i]);
	creat();	
	for(i = 1;i <= num;i++)
		printf("%d ",deletemin());



	return 0;
}
