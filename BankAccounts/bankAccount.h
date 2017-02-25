/* Paul Heintz heintzpm@gmatc.matc.edu
* ITDEV-154 Downtown
* Bank account base class header
* February 5, 2017 */

#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H
#include <iostream>
#include <string>
using namespace std;

class bankAccount
{
protected:
	string accountNumber;
	double balance;

public:
	bankAccount();
	bankAccount(string acctNum, double startBal);
	~bankAccount();
	double deposit(double depositAmt);
	string getAccountNumber();
	double getBalance();
	void print();
	void setAccountNumber(string acctNum);
	double withdraw(double withdrawalAmt);
};

#endif // !BANKACCOUNT_H