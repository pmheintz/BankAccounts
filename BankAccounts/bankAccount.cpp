/* Paul Heintz heintzpm@gmatc.matc.edu
* ITDEV-154 Downtown
* Bank account base class
* February 5, 2017 */

#include "bankAccount.h"

bankAccount::bankAccount()
{
}

bankAccount::bankAccount(string acctNum, double startBal)
{
	accountNumber = acctNum;
	balance = startBal;
}


bankAccount::~bankAccount()
{
}

double bankAccount::deposit(double depositAmt)
{
	balance += depositAmt;
	return balance;
}

string bankAccount::getAccountNumber()
{
	return accountNumber;
}

double bankAccount::getBalance()
{
	return balance;
}

void bankAccount::print()
{
	cout << "Your account Number:   " << getAccountNumber() << endl;
	cout << "Your current balance:  $" << getBalance() << endl;
}

void bankAccount::setAccountNumber(string acctNum)
{
	accountNumber = acctNum;
}

double bankAccount::withdraw(double withdrawalAmt)
{
	balance -= withdrawalAmt;
	return balance;
}
