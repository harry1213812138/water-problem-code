#include <stdio.h>
#include <stdlib.h>


struct Account
{
	char *bankname;
	char *username;
	double limit;		//�û����
	double bill;		//�����˵�
};

double repayment(Account account)
{
	return account.limit - account.bill;
}





int main()
{
	Account account = {"��������","�ܿ�",30000,18000};
	double result = repayment(account);
	printf("����Ӧ�����%.2lf\n",result);


	return 0;
}