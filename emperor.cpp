#include <stdio.h>
#include <string.h >
#define max 6
int main()
{


		/*#include <windows.h>
	#include <mmsystem.h>
	#pragma comment(lib,"winmm.lib")
	int main()
	{
		PlaySound(TEXT（"sounds\\音乐名.wav")         //音乐路径
			NULL,SND_FILENAME | SND_ASYNC | SND_LOOP);
		return 0;      
	}   */


	int i,j,temp;
	int count = 5;  //当前未打入冷宫的嫔妃个数
	int choice;     //皇帝的选择
	int tempindex;         //存放临时下标
	int levels[max] = {1,2,0,0,0,-1};       //妃子的当前等级 第六人为-1 假
	int loves[max] = {100,100,100,100,100,-1};     //妃子的好感度
	char emperorname[50];  //皇帝的名号
	char tempname[20];     //临时变量存放字符串
	char names[max][20] = {"貂蝉","杨玉环","不知火舞","西施","甄姬"};
	char level[5][10] = {"贵人","嫔妃","贵妃","皇贵妃","皇后"};  //妃子的级别
	char tempchange[20];



	for(i = 0;i < count - 1; i++)
	{
		for(j = 0;j < count - i - 1; j++)
		{
			if(levels[j] < levels[j + 1])
			{
				temp = levels[j];
				levels[j] = levels[j + 1];
				levels[j + 1] = temp;
				temp = loves[j];
				loves[j] = loves[j + 1];
				loves[j + 1] = temp;
				strcpy(tempname,names[j]);
				strcpy(names[j],names[j + 1]);
				strcpy(names[j + 1],tempname);
			}
		}
	}
	printf("\n**********************************\n");          //可自行使用冒泡排序对状态排序
	printf("测试代码：查看当前嫔妃的状态\n");
	printf("%-12s级别\t好感度\n","姓名");
	for(i = 0;i < count; i++)
	{
		printf("%-12s%s\t%d\n",names[i],level[levels[i]],loves[i]);
	}
	printf("\n**********************************\n");


	printf("请输入要登基的皇帝名号：\n");
	scanf("%s",emperorname);
	printf("欢迎%s皇帝\n",emperorname);
	printf("1、皇帝下旨选妃\n");//（增加功能）
	printf("2、翻牌宠幸\n");    //（修改状态）
	printf("3、打入冷宫\n");    //（删除功能）
	printf("4、单独召见爱妃\n");
	printf("陛下请选择：");
	scanf("%d",&choice);
	switch(choice)
	{
	case 1:      //皇帝下旨选妃            1、判断数组是否有空间   2、增加数组（nums,levels,loves）
		if(count < max)
		{
			printf("请输入妃子的名字：\n");
			scanf("%s",names[count]);
			levels[count] = 0;
			loves[count] = 100;
			count++;
		//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
		for(i = 0;i < count - 1; i++)
		{
			for(j = 0;j < count - i - 1; j++)
			{
				if(levels[j] < levels[j + 1])
				{
					temp = levels[j];
					levels[j] = levels[j + 1];
					levels[j + 1] = temp;
					temp = loves[j];
					loves[j] = loves[j + 1];
					loves[j + 1] = temp;
					strcpy(tempname,names[j]);
					strcpy(names[j],names[j + 1]);
					strcpy(names[j + 1],tempname);
				}
			}
		}
		printf("\n**********************************\n");          
		printf("测试代码：查看当前嫔妃的状态\n");
		printf("%-12s级别\t好感度\n","姓名");
		for(i = 0;i < count; i++)
		{
			printf("%-12s%s\t%d\n",names[i],level[levels[i]],loves[i]);
		}
		printf("\n**********************************\n");
		//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$


		}
		else
		{
			printf("陛下，你要保重龙体呀，后宫已经人满为患了！\n");
		}
		break;
	case 2:        //翻牌宠幸    查找与修改  1、找到下标 2、自身+10 3、其他-10
		printf("陛下，你要翻牌的妃子是：\n");
		scanf("%s",tempname);
		for(i = 0;i < count; i++)
		{
			if(strcmp(tempname,names[i]) == 0) 
			{
				loves[i] += 10;
				levels[i] = levels[i] >= 4 ? 4 : levels[i] + 1; 
			}
		}

		//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
		for(i = 0;i < count - 1; i++)
		{
			for(j = 0;j < count - i - 1; j++)
			{
				if(levels[j] < levels[j + 1])
				{
					temp = levels[j];
					levels[j] = levels[j + 1];
					levels[j + 1] = temp;
					temp = loves[j];
					loves[j] = loves[j + 1];
					loves[j + 1] = temp;
					strcpy(tempname,names[j]);
					strcpy(names[j],names[j + 1]);
					strcpy(names[j + 1],tempname);
				}
			}
		}
		printf("\n**********************************\n");          
		printf("测试代码：查看当前嫔妃的状态\n");
		printf("%-12s级别\t好感度\n","姓名");
		for(i = 0;i < count; i++)
		{
			printf("%-12s%s\t%d\n",names[i],level[levels[i]],loves[i]);
		}
		printf("\n**********************************\n");
		//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$

		break;
	case 3:        //打入冷宫    1、查找  2、后面覆盖前面  3、总数-1  4、修改其他妃子状态
		printf("陛下请输入要打入冷宫的妃子：\n");
		scanf("%s",tempname);
		for(i = 0;i < count; i++)
		{
			if(strcmp(tempname,names[i]) == 0)
			{
				tempindex = i;     //记录要查找的下标
				break;
			}
			else
			{
				tempindex = -1;
				break;
			}
		}
		if(-1 == tempindex)        //判断是否找到 若为-1 则没找到
		{
			printf("虚惊一场，无人如冷宫\n");
		}
		else
		{
			for(i = tempindex;i < count; i++)
			{
				strcpy(names[i],names[i + 1]);
				loves[i] = loves[i + 1];
				levels[i] = levels[i + 1];
			}
			count--; 
			for(i = 0;i < count; i++)
			{
				loves[i] += 10;
			}
		}
		 
		//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
		for(i = 0;i < count - 1; i++)
		{
			for(j = 0;j < count - i - 1; j++)
			{
				if(levels[j] < levels[j + 1])
				{
					temp = levels[j];
					levels[j] = levels[j + 1];
					levels[j + 1] = temp;
					temp = loves[j];
					loves[j] = loves[j + 1];
					loves[j + 1] = temp;
					strcpy(tempname,names[j]);
					strcpy(names[j],names[j + 1]);
					strcpy(names[j + 1],tempname);
				}
			}
		}
		printf("\n**********************************\n");          
		printf("测试代码：查看当前嫔妃的状态\n");
		printf("%-12s级别\t好感度\n","姓名");
		for(i = 0;i < count; i++)
		{
			printf("%-12s%s\t%d\n",names[i],level[levels[i]],loves[i]);
		}
		printf("\n**********************************\n");
		//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$

		break;
	case 4:      //单独召见爱妃    1、查找  2、修改状态
		printf("陛下要单独召见哪个爱妃呢？\n");
		scanf("%s",tempname);
		for(i = 0;i < count; i++)
		{
			if(strcmp(tempname,names[i]) == 0)
			{
				levels[i] = levels[i] >= 4 ? 4 : levels[i] +=1;
				loves[i] += 10;
			}
			else
			{
				loves[i] -= 10;
			}
		}


		//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
		for(i = 0;i < count - 1; i++)
		{
			for(j = 0;j < count - i - 1; j++)
			{
				if(levels[j] < levels[j + 1])
				{
					temp = levels[j];
					levels[j] = levels[j + 1];
					levels[j + 1] = temp;
					temp = loves[j];
					loves[j] = loves[j + 1];
					loves[j + 1] = temp;
					strcpy(tempname,names[j]);
					strcpy(names[j],names[j + 1]);
					strcpy(names[j + 1],tempname);
				}
			}
		}
		printf("\n**********************************\n");          
		printf("测试代码：查看当前嫔妃的状态\n");
		printf("%-12s级别\t好感度\n","姓名");
		for(i = 0;i < count; i++)
		{
			printf("%-12s%s\t%d\n",names[i],level[levels[i]],loves[i]);
		}
		printf("\n**********************************\n");
		//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$

		break;
	default:
		printf("君无戏言，请陛下再次选择:\n");

	} 



	return 0;
}