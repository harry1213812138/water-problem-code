#include <stdio.h>

struct martials
{
	int id;
	char name[50];
	int members;
	char monitor[50];
};

typedef struct player					//�ṹ��ļ򻯰�ʹ��  ������define�궨��      typedef
{
	int id;
	char name[50];
	char pass[20];
	char sex[10];
	struct martials martial;
	int hp;
}player1;



/*
struct hero
{
	int id;
	char name[50];
	double hp;
	double mp;
	char skill[50];

};
*/


int main()
{
	player player1 = {1,"��ɮ","123456","male",{1,"�ҷ�ȱ�",500,"����"},100};
	struct player player2 = {2,"����","123456","female",{2,"��Ҳ��֪��",100,"��ʴ��"},10000};
	struct player * ptr_1 = &player1;
	struct player * ptr_2 = &player2;

//	printf("%d\t%s\t%s\t%s\t%d\t%s\t%d\n",player1.id,player1.name,player1.sex,player1.martial.name,player1.martial.members,player1.martial.monitor,player1.hp);
	printf("%d\t%s\n",(*ptr_1).id,(*ptr_1).name);
	printf("%d\t%s\n",(*ptr_2).id,(*ptr_2).name);
	printf("%d\t%s\n",ptr_1 -> id,ptr_1 -> name);
	printf("%d\t%s\n",ptr_2 -> id,ptr_2 -> name);




/*
	struct hero hero1 = {1,"��������֮��",100,20,"�󱦽�"};
	printf("%d\t%s\t%.2lf\t%.2lf\t%s\n",hero1.id,hero1.name,hero1.hp,hero1.mp,hero1.skill);
*/

	return 0;
}