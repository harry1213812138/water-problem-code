/**��Ϸ˼·
*��Ʒ�ṹ-���ơ����ۡ���桢����
*�����ṹ-��Ӧ��ұ�š����ơ���Ʒ[10]�������������������
*��ҽṹ-��š����ơ����롢��Ǯ������
*/

#include <stdio.h>
#include <stdlib.h>

int propscount = 0;
int playerscount = 0;
void input();
void showprops();
void showplayers();

struct Prop					//��Ʒ�����߽ṹ
{
	int id;					//���
	char name[50];			//����
	double price;			//�۸�
	int stock;				//���
	char desc[200];			//����
};

struct Bag					//����
{
	int playerid;			//������ұ��
	int count;				//��ǰ�����е�������
	int max;				//��������������
	struct Prop props[8];	//���е���
};

struct Player				//��ҽṹ
{
	int id;					//��ұ��
	char name[50];			//�������
	char pass[20];			//��¼����
	struct Bag bag;			//�����ṹ
	double gold;			//�������
	double sysee;			//Ԫ������
};
struct Prop *prop;					//�趨����ָ��
struct Player *player;



int main()
{
	//1����ʼ����Ϸ����
	input();
	//2����ӡ��Щ����
	showprops();
	



	return 0;
}


void input()
{
	//1����ʼ������
	static struct Prop props[] = {
		{1,"ħ��֮ѥ",1000,10,"��������˫�������٣�˲���ܹ����ˣ�"},
		{2,"Զ�Ŵ󱦽�",8000,5,"һ��999�����ֵܾ������ң�"},
		{3,"����ս��",6000,10,"��ǹ���룬ˮ����"},
		{4,"���ߵıӻ�",8000,8,"����ף���������û���"},
		{5,"��̥���ǵ�",10000,3,"��������˲�䷭������ֵ��ӵ��"}
	};
	propscount = sizeof(props) / sizeof(Prop);
	prop = props;
	/*static struct Player players[] = {
		{1,"ëë��","666666", .gold = 50000},
		{2,"������","123456", .gold = 50000},
		{3,"������","654321", .gold = 50000},
		{1,"��û�","888888", .gold = 50000}
	};
	playerscount = sizeof(players) / sizeof(Player);
	player = players;*/
}
void showprops()
{
	int i;
	if(prop == NULL) return;
	printf("���\t����\t����\t���\t���Խ���\n");
	for(i = 0;i < propscount; i++)
	{
		printf("%d\t%s\t%.2lf\t%d\t%s\n",props[i].id,props[i].name,props[i].price,props[i].stock,props[i].desc);
	}
}
//void showplayers()