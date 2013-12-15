#ifndef P_H
#define P_H

#include<iostream>
#include<string>
#include<cmath>
using namespace std;

class saveAccount
{
public:
saveAccount(float); //Constructor
void Transaction(float); //Procedure
float Total(float,int); //Savings Procedure
float TotalRecursive(float=0,int=0);
void toString(); //Output Properties
private:
float Withdraw(float); //Utility Procedure
float Deposit(float); //Utility Procedure
float balance; //Property
int FreqWithDraw; //Property
int FreqDeposit; //Property
};
//Balance
saveAccount::saveAccount(float num)
{
if(num>0)
balance=num;
else
balance=0;
FreqDeposit=FreqWithDraw=0;
}


//Transactions
void saveAccount::Transaction(float num)
{
if(num >0)
Deposit(num);
else
Withdraw(num);
}

//Deposited
float saveAccount::Deposit(float num)
{
balance=balance+num;
FreqDeposit++;
return balance;
}
float saveAccount::Withdraw(float num)
{
if((balance - num) >=0)
{
balance=balance-num;
FreqWithDraw++;
}
else
cout<<"the withdraw ammount is more than what you have"<<endl;
return balance;
}

void saveAccount::toString()
{
cout<<"the balance in your account is "<<balance<<endl;
cout<<"the Frequancy WithDraw is made ="<<FreqWithDraw<<endl;
cout<<"the Frequancy Deposit is made ="<<FreqDeposit<<endl;
}

float saveAccount::Total(float savint = 0, int time = 0)
{
float tot=0;
for(int i=1;i<=time;i++)
tot=tot+(balance*(1+savint));

return tot ;
}

#endif