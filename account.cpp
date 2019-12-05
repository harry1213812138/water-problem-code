#include <stdio.h>
#include <stdlib.h>


struct Account
{
	char *bankname;
	char *username;
	double limit;		//用户额度
	double bill;		//当月账单
};

double repayment(Account account)
{
	return account.limit - account.bill;
}





int main()
{
	Account account = {"招商银行","杰克",30000,18000};
	double result = repayment(account);
	printf("当月应还款金额：%.2lf\n",result);


	return 0;
}