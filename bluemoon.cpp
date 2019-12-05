/**游戏思路
*商品结构-名称、单价、库存、描述
*背包结构-对应玩家编号、名称、商品[10]、道具数量、最大容量
*玩家结构-编号、名称、密码、金钱、背包
*/

#include <stdio.h>
#include <stdlib.h>

int propscount = 0;			//props数组中结构数量 
int playerscount = 0;		//players数组中结构数量 
void input();
void showplayers();

struct Prop					//商品、道具结构
{
	int id;					//编号
	char name[50];			//名称
	double price;			//价格
	int stock;				//库存
	char desc[200];			//描述
};

struct Bag					//背包
{
	int playerid;			//所属玩家编号
	int count;				//当前背包中道具数量
	int max;				//插槽总数最大容量
	struct Prop props[8];	//现有道具
};

struct Player				//玩家结构
{
	int id;					//玩家编号
	char name[50];			//玩家名称
	char pass[20];			//登录密码
	double gold;			//金币数量
	double sysee;			//元宝数量
	struct Bag bag;			//背包结构
};

struct Prop *prop;					//设定访问指针
struct Player *player;





int main()
{
	//初始化数据 
	input();
	
	return 0;
}








void input()  
{
	int i;
	//1、初始化数据
		static struct Prop props[5] = {
			{1,"魔法之靴",1000,10,"增加双倍移速，瞬间跑过别人！"},
			{2,"远古大宝剑",8000,5,"一刀999，是兄弟就来砍我！"},
			{3,"披巾战甲",6000,10,"刀枪不入，水火不侵"},
			{4,"贤者的庇护",8000,8,"复活甲，过了这村就没这店"},
			{5,"脱胎换骨丹",9000,3,"所有属性瞬间翻倍，你值得拥有"}
			};
	propscount = sizeof(props) / sizeof(Prop);
	prop = props;
	
	
	static struct Player players[4] = {
		{1,"毛毛虫","666666", 50000},
		{2,"鼓添乐","123456", 50000},
		{3,"渣渣辉","654321", 50000},
		{4,"溜得滑","888888", 50000}
	};
	playerscount = sizeof(players) / sizeof(Player);
	//player = players;

	if(prop == NULL) return;
	printf("编号\t名称\t\t单价\t\t库存\t属性介绍\n");
		for(i = 0;i < propscount; i++)
	{   
		printf("%d\t%s\t%.2lf\t\t%d\t%s\n",props[i].id,props[i].name,props[i].price,props[i].stock,props[i].desc);
	}
}










