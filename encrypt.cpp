#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define USER_NAME "admin"		//��¼��
#define PASSWORD "admin"		//��¼����
#define KEY 5					//��Կ ���ܽ���ʹ��

int length(char[]);				//���ַ�������
void strings(char[],int);		//��װfgets
int login(char[],char[]);		//��¼ϵͳ
char * encrypt(char[]);			//�ַ����ļ���
char * unencrypt(char[]);		//�ַ����Ľ���


int length(char str[])
{
	int count = 0;
	while(str[count] != '\0')
	{
		if(str[count] == '\n')
		{
			str[count] = '\0';  //�滻
			break;
		}
		count++;
	}
	return count;
}

void strings(char str[],int count)
{
	fgets(str,count,stdin);
	char * find = strchr(str,'\n');
	if(find)
		*find = '\0';
}

int login(char username[],char password[])
{
	int result = 0;
	if(strcmp(USER_NAME,username) == 0)
	{
		if(strcmp(PASSWORD,password) == 0)
			result = 1;
	}

	return result;
}

/**
*����ԭ���ַ����е�ÿһ���ַ����������ַ����е�λ�ú�һ��ƫ��������Կ���˴�Ϊ5
*����1��Ҫ���ܵ��ַ���
*����ֵ�����ؼ��ܺ���ַ���
*/
char * encrypt(char password[])
{
	int i = 0;
	int count = strlen(password);
	for(;i < count; i++)
	{
		//����ԭ��ÿһ���ַ�ʵ�ּ���
		password[i] = password[i] + i + KEY;
	}
	return password;
}

char * unencrypt(char password[])
{
	int i = 0;
	int count = strlen(password);
	for(;i < count; i++)
	{
		//����ԭ��ÿһ���ַ�ʵ�ֽ���
		password[i] = password[i] - i - KEY;
	}
	return password;
}






int main()
{



	char password[20] = "��������";
	encrypt(password);
	printf("���ܺ���ַ����ǣ�%s\n",password);
	unencrypt(password);
	printf("���ܺ���ַ����ǣ�%s\n",password);






/*  //��¼ϵͳ
	char username[50],password[50];
	int i = 0;
	while(login(username,password) == 0)
	{
		i++;
		printf("�������û�����");
		gets(username);
		printf("���������룺");
		gets(password);
		if(login(username,password) == 0)
		{
			printf("�û�������������������������룬����%d�λ��ᣡ\n",3 - i);
		}else
		{
			printf("��ϲ����¼�ɹ���\n");
		}
		if(i >= 3)
			break;
	}
*/










/*
	int i;
	char names[10];
	fgets(names,10,stdin);
	//strings(names,10);
	//int len = length(names);
	//printf("�ַ�������Ϊ��%d\n",len);
	for(i = 0;i < 10; i++)
		printf("%c\n",names[i]);
*/

	return 0;
}