#include <stdio.h>
int main()
{
	//四个同学的三门课成绩       二维数组
	int i,j;    //外层循环行 内层循环列
	double score[4][3] = {
		{86,99,78},
		{96,66,75},
		{98,97,94},
		{87,92,90}       };
	//打印各位同学的成绩
	printf("成绩表：\n");
	printf("语文\t数学\t英语\n");
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