/* Paul Heintz heintzpm@gmatc.matc.edu
* ITDEV-154 Downtown
* Savings account derived class
* February 5, 2017 */

#include "savingsAccount.h"

savingsAccount::savingsAccount()
{
}

savingsAccount::savingsAccount(string acctNum, double startBal, double intRate)
{
	accountNumber = acctNum;
	balance = startBal;
	interestRate = intRate;
}

savingsAccount::~savingsAccount()
{
}

double savingsAccount::getInterestRate()
{
	return interestRate;
}

double savingsAccount::postInterest()
{
	double interest = 0;
	interest = bankAccount::balance * (interestRate / 100);
	bankAccount::balance += interest;

	return interest;
}

void savingsAccount::print()
{
	cout << endl << "Your account Number:   " << getAccountNumber() << endl;
	cout << "Your current balance:  $" << getBalance() << endl;
	cout << "Your interest rate:    %" << getInterestRate() << endl;
}

void savingsAccount::setInterestRate(double intRate)
{
	interestRate = intRate;
}

double savingsAccount::withdraw(double withdrawalAmt)
{
	//verify there's enough money in account
	if ((bankAccount::balance - withdrawalAmt) < 0)
	{
		cout << endl << "Insufficient funds for withdrawal." << endl;
	}
	else
	{
		bankAccount::balance -= withdrawalAmt;
	}
	return bankAccount::balance;
}
