/*	cantor blank
#include<stdio.h>
int main()
{
	int sum = 0,k = 1,count,n;
	while(1){sum = 0;k = 1;
	scanf("%d",&n);
	while(sum < n)
	{
		sum += k;
		k++;
	}
	count = n - sum + --k;
	if(k % 2 == 0)
		printf("%d/%d\n",count,k-count+1);
	else
		printf("%d/%d\n",k-count+1,count);

	
}

	return 0;
}
*/



/*	caculate
#include<stdio.h>
double num=0,x=0;
char c,p;
int a[100] = {0},l=1,mid,pd,i;
int main()
{
    pd=1; 
    while(c!='=') 
    {
        c=getchar();
        if(c=='-')
            ++l,pd=-1;
        if(c=='+')
            ++l,pd=1; 
        if(c>='0'&&c<='9') 
        {
            if(!a[l])
                a[l]=(c-'0')*pd; 
            else
                a[l]=a[l]*10+(c-'0')*pd;
        }
        if(c>='a'&&c<='z')
        {
            p=c;
            if(a[l]!=0)
                x+=a[l],a[l]=0; 
            else
                x+=pd;
            --l; 
        }
    }
    mid=l,++l,pd=1; 
    while(c!='\n')
    {
        c=getchar();
        if(c=='-')
            ++l,pd=-1;
        if(c=='+')
            ++l,pd=1;
        if(c>='0'&&c<='9')
        {
            if(!a[l])
                a[l]=(c-'0')*pd;
            else
                a[l]=a[l]*10+(c-'0')*pd;
        }
        if(c>='a'&&c<='z') 
        {
            p=c;
            if(a[l]!=0)
                x-=a[l],a[l]=0;
            else
                x-=pd; 
            --l; 
        }
    }
    for(i=1;i<=l;++i)
    {
        if(i<=mid)
            num-=a[i];
        else
            num+=a[i]; 
    }
    if(!(num/x))
        printf("%c=0.000\n",p);
    else
        printf("%c=%.3lf\n",p,num/x);
 


    return 0; 
}*/


#include<stdio.h>
#include<string.h>
char a[21];
int len,flag;

void integer(int start,int end)
{
	int i,j;
	flag = 0;
	char t;
	i = start;
	j = end;
	while(i < j)
	{
		t = a[i];
		a[i] = a[j];
		a[j] = t;
		i++;
		j--;
	}
	if(end == 1)
	{
		flag = 1;
		printf("%c",a[1]);
		return;
	}
	for(i = start+1;i <= end;i++)
	{
		if(a[i] == '0' && flag == 0)
			continue;
		flag = 1;
		printf("%c",a[i]);
	}
}

int main()
{
	int len;
	gets(a);
	len = strlen(a);
	if(a[0] == '-')
	{
		printf("-");
		integer(1,len);
	}
	else
		integer(0,len);


	return 0;
}