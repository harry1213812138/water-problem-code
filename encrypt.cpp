#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define USER_NAME "admin"		//登录名
#define PASSWORD "admin"		//登录密码
#define KEY 5					//密钥 加密解密使用

int length(char[]);				//量字符串长度
void strings(char[],int);		//封装fgets
int login(char[],char[]);		//登录系统
char * encrypt(char[]);			//字符串的加密
char * unencrypt(char[]);		//字符串的解密


int length(char str[])
{
	int count = 0;
	while(str[count] != '\0')
	{
		if(str[count] == '\n')
		{
			str[count] = '\0';  //替换
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
*加密原理将字符串中的每一个字符加上他在字符串中的位置和一个偏移量即密钥，此处为5
*参数1：要加密的字符串
*返回值：返回加密后的字符串
*/
char * encrypt(char password[])
{
	int i = 0;
	int count = strlen(password);
	for(;i < count; i++)
	{
		//根据原理将每一个字符实现加密
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
		//根据原理将每一个字符实现解密
		password[i] = password[i] - i - KEY;
	}
	return password;
}






int main()
{



	char password[20] = "哈哈哈哈";
	encrypt(password);
	printf("加密后的字符串是：%s\n",password);
	unencrypt(password);
	printf("解密后的字符串是：%s\n",password);






/*  //登录系统
	char username[50],password[50];
	int i = 0;
	while(login(username,password) == 0)
	{
		i++;
		printf("请输入用户名：");
		gets(username);
		printf("请输入密码：");
		gets(password);
		if(login(username,password) == 0)
		{
			printf("用户名或密码输入错误，请重新输入，还有%d次机会！\n",3 - i);
		}else
		{
			printf("恭喜，登录成功！\n");
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
	//printf("字符串长度为：%d\n",len);
	for(i = 0;i < 10; i++)
		printf("%c\n",names[i]);
*/

	return 0;
}