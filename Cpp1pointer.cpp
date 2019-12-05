#include <stdio.h>
#define N 6

int main()
{
	int i,j;
	double score[5][3] = {
		{55,45,67},
		{43,98,30},
		{85,25,85},
		{12,45,34},
		{55,45,40},
	};
	double (* ptr_score)[3] = score;
	for(i = 0;i < 5; i++)
	{
		for(j = 0;j < 3; j++)
		{
			//printf("%.2lf\t",score[i][j]);       //score[i] = *(score + i)    score[i][j] = *(score[i] + j)
			printf("%.2lf\t",*(*(score + i)+j));
		}
		printf("\n");
	}





/*int array[N] = {15,20,25,30,35,40};    //逆序 
	int temp;
	int i = 0;
	int * ptr_array1 = array;
	int * ptr_array2 = array + N - 1;
	
	while(i <= N / 2)        //使用交换次数判断是否停止  单数也可用具体条件判断eg while(ptr_array1 != ptr_array2)
	{
		temp = * ptr_array1;
		* ptr_array1 = * ptr_array2;
		* ptr_array2 = temp;
		ptr_array1++;                //注意变量的更新
		ptr_array2--;  
		i++;
	}
/*


/*	for (i = 0;i < N / 2; i++)              //第1个值和第N - i - 1的值交换  实现逆序 
	{
		temp = array[i];
		array[i] = array[N - i - 1];
		array[N - i - 1] = temp;
	}
*/
	



/*	for(i = 0;i < N; i++)
	{
		printf("%d\t",*(array + i));
	}
*/
	
	return 0;
}