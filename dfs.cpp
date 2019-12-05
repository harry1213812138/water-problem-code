#include<stdio.h>
int a[51][51],book[51][51],p,q,n,m,min = 999999;

void dfs(int x,int y,int step)
{
	int tx,ty,k;
	int next[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};

	if(x == p && y == q)			//find final ,return
	{
		if(step < min)
			min = step;				//update the min
		return;
	}

	for(k = 0;k < 3;k++)
	{
		tx = x + next[k][0];
		ty = y + next[k][1];
		if(tx < 0 || ty < 0 || tx >= m || ty >= n)
			continue;
		if(a[tx][ty] == 0 && book [tx][ty] == 0)
		{
			book[tx][ty] = 1;
			dfs(tx,ty,step+1);
			book[tx][ty] = 0;
		}
	}
	return;
}




int main()
{
	int i,j,startx,starty;
	scanf("%d%d",&n,&m);
	for(i = 0;i < n;i++)
		for(j = 0;j < m;j++)
			scanf("%d",&a[i][j]);
	scanf("%d%d%d%d",&startx,&starty,&p,&q);

	book[startx][starty] = 1;
	dfs(startx,starty,0);

	printf("%d",min);

	

	return 0;
}