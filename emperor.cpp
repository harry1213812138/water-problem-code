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
		PlaySound(TEXT��"sounds\\������.wav")         //����·��
			NULL,SND_FILENAME | SND_ASYNC | SND_LOOP);
		return 0;      
	}   */


	int i,j,temp;
	int count = 5;  //��ǰδ�����乬����������
	int choice;     //�ʵ۵�ѡ��
	int tempindex;         //�����ʱ�±�
	int levels[max] = {1,2,0,0,0,-1};       //���ӵĵ�ǰ�ȼ� ������Ϊ-1 ��
	int loves[max] = {100,100,100,100,100,-1};     //���ӵĺøж�
	char emperorname[50];  //�ʵ۵�����
	char tempname[20];     //��ʱ��������ַ���
	char names[max][20] = {"����","����","��֪����","��ʩ","�缧"};
	char level[5][10] = {"����","����","����","�ʹ���","�ʺ�"};  //���ӵļ���
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
	printf("\n**********************************\n");          //������ʹ��ð�������״̬����
	printf("���Դ��룺�鿴��ǰ������״̬\n");
	printf("%-12s����\t�øж�\n","����");
	for(i = 0;i < count; i++)
	{
		printf("%-12s%s\t%d\n",names[i],level[levels[i]],loves[i]);
	}
	printf("\n**********************************\n");


	printf("������Ҫ�ǻ��Ļʵ����ţ�\n");
	scanf("%s",emperorname);
	printf("��ӭ%s�ʵ�\n",emperorname);
	printf("1���ʵ���ּѡ��\n");//�����ӹ��ܣ�
	printf("2�����Ƴ���\n");    //���޸�״̬��
	printf("3�������乬\n");    //��ɾ�����ܣ�
	printf("4�������ټ�����\n");
	printf("������ѡ��");
	scanf("%d",&choice);
	switch(choice)
	{
	case 1:      //�ʵ���ּѡ��            1���ж������Ƿ��пռ�   2���������飨nums,levels,loves��
		if(count < max)
		{
			printf("���������ӵ����֣�\n");
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
		printf("���Դ��룺�鿴��ǰ������״̬\n");
		printf("%-12s����\t�øж�\n","����");
		for(i = 0;i < count; i++)
		{
			printf("%-12s%s\t%d\n",names[i],level[levels[i]],loves[i]);
		}
		printf("\n**********************************\n");
		//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$


		}
		else
		{
			printf("���£���Ҫ��������ѽ�����Ѿ�����Ϊ���ˣ�\n");
		}
		break;
	case 2:        //���Ƴ���    �������޸�  1���ҵ��±� 2������+10 3������-10
		printf("���£���Ҫ���Ƶ������ǣ�\n");
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
		printf("���Դ��룺�鿴��ǰ������״̬\n");
		printf("%-12s����\t�øж�\n","����");
		for(i = 0;i < count; i++)
		{
			printf("%-12s%s\t%d\n",names[i],level[levels[i]],loves[i]);
		}
		printf("\n**********************************\n");
		//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$

		break;
	case 3:        //�����乬    1������  2�����渲��ǰ��  3������-1  4���޸���������״̬
		printf("����������Ҫ�����乬�����ӣ�\n");
		scanf("%s",tempname);
		for(i = 0;i < count; i++)
		{
			if(strcmp(tempname,names[i]) == 0)
			{
				tempindex = i;     //��¼Ҫ���ҵ��±�
				break;
			}
			else
			{
				tempindex = -1;
				break;
			}
		}
		if(-1 == tempindex)        //�ж��Ƿ��ҵ� ��Ϊ-1 ��û�ҵ�
		{
			printf("�龪һ�����������乬\n");
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
		printf("���Դ��룺�鿴��ǰ������״̬\n");
		printf("%-12s����\t�øж�\n","����");
		for(i = 0;i < count; i++)
		{
			printf("%-12s%s\t%d\n",names[i],level[levels[i]],loves[i]);
		}
		printf("\n**********************************\n");
		//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$

		break;
	case 4:      //�����ټ�����    1������  2���޸�״̬
		printf("����Ҫ�����ټ��ĸ������أ�\n");
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
		printf("���Դ��룺�鿴��ǰ������״̬\n");
		printf("%-12s����\t�øж�\n","����");
		for(i = 0;i < count; i++)
		{
			printf("%-12s%s\t%d\n",names[i],level[levels[i]],loves[i]);
		}
		printf("\n**********************************\n");
		//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$

		break;
	default:
		printf("����Ϸ�ԣ�������ٴ�ѡ��:\n");

	} 



	return 0;
}