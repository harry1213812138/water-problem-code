#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define X 5
#define Y 5

void print_chess();
int next(int *x,int *y,int step);
int traver(int x,int y,int count);
int traver_chess(int x,int y,int tag);

int chess[X][Y];		//define chess

int main()
{
	clock_t start,end;		//record time
	int i,j;
	for(i = 0;i < X;i++)	//initialization the chess
	{
		for(j = 0;j < Y;j++)
		{
			chess[i][j] = 0;
		}
	}
	start = clock();
	//Methon one
//	chess[2][0] = 1;
//	int result = traver(2,0,2);

	//Methon two
	int result = traver_chess(2,0,2);
	end = clock();
	if(result == 1)
	{
		printf("ok\n");
		print_chess();
		printf("record time = %f\n",(double)(end - start) /	CLOCKS_PER_SEC);
	}
	else
	{
		printf("error");
	}

	return 0;
}


int next(int *x,int *y,int step)
{
	switch(step)
	{
	case 0:
		if(*y+2 < Y-1 && *x-1 >= 0 && chess[*x-1][*y+2] == 0)
		{
			*y += 2;
			*x += 1;
			return 1;
		}
		break;
	case 1:
		if(*y+2 <= Y-1 && *x+1 <= X-1 && chess[*x+1][*y+2] == 0)
		{
			*y += 2;
			*x += 1;
			return 1;
		}
		break;
	case 2:
		if(*y+1 <= Y-1 && *x+2 <= X-1 && chess[*x+2][*y+1] == 0)
		{
			*y += 1;
			*x += 2;
			return 1;
		}
		break;
	case 3:
		if(*y-1 >= 0 && *x+2 <= X-1 && chess[*x+2][*y-1] == 0)
		{
			*y -= 1;
			*x += 2;
			return 1;
		}
		break;
	case 4:
		if(*y-2 >= 0 && *x+1 <= X-1 && chess[*x+1][*y-2] == 0)
		{
			*y -= 2;
			*x += 1;
			return 1;
		}
		break;
	case 5:
		if(*y-2 >= 0 && *x-1 >= 0 && chess[*x-1][*y-2] == 0)
		{
			*y -= 2;
			*x -=1;
			return 1;
		}
		break;
	case 6:
		if(*y-1 >= 0 && *x-2 >= 0 && chess[*x-2][*y-1] == 0)
		{
			*y -= 1;
			*x -= 2;
			return 1;
		}
		break;
	case 7:
		if(*y+1 <= Y-1 && *x-2 >= 0 && chess[*x-2][*y+1] == 0)
		{
			*y += 1;
			*x -= 2;
			return 1;
		}
		break;
	default:
		break;
	}
	return 0;
}


/**
*Method one
*trave all chess 
*(x,y) is the location of coordinate
*count is the frequency of jump
**/
int traver(int x,int y,int count)
{
	int x1 = x,y1 = y;					//define new location
	if(count > x * y)					//trave all chess return 
		return 1;
	int flag,result,i;
	for(i = 0;i < 8;i++)
	{
		flag = next(&x1,&y1,i);			//find next step
		if(flag == 1)
		{
			chess[x1][y1] = count;		//mark the new step
			result = traver(x1,y1,count++);	//accord to new location go next step
			if(result)					//all chess  is used
				return 1;
			else						//the new step cannot go next,to flash back
			{
				chess[x1][y1] = 0;		//resume the chess step
				x1 = x;					//to flash back location of coordinate
				y1 = y;
			}
		}
	}
	return 0;
}



/**
*Method two
*(x,y) is the location of the coordinate
*tag is the frequency of jump
**/
int traver_chess(int x,int y,int tag)
{
	int x1 = x,y1 = y,flag = 0,count = 0;
	chess[x][y] = tag;						//mark the step of chess
	if(tag == X * Y)						//all trave,return
		return 1;
	flag = next(&x1,&y1,count);
	while(flag == 0 && count <= 7)
	{
		count++;
		flag = next(&x1,&y1,count);
	}
	while(flag)
	{
		if(traver_chess(x1,y1,tag++))		//all trave,return
			return 1;
		x1 = x;								//to flash back
		y1 = y;
		count++;
		flag = next(&x1,&y1,count);
		while(flag == 0 && count <= 7)
		{
			count++;
			flag = next(&x1,&y1,count);
		}
	}
	if(flag == 0)
	{
		chess[x][y] = 0;
	}
	return 0;
}


/**
*print the chess
**/
void print_chess()
{
	int i,j;
	for(i = 0;i < X;i++)
	{
		for(j = 0;j < Y;j++)
		{
			printf("%d\t",chess[i][j]);
		}
		printf("\n");
	}
}