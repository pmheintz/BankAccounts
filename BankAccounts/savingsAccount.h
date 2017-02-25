/* Paul Heintz heintzpm@gmatc.matc.edu
* ITDEV-154 Downtown
* Savings account derived class header
* February 5, 2017 */

#ifndef SAVINGSACCOUNT_H
#define SAVINGSACCOUNT_H
#include <iostream>
#include <string>
#include "bankAccount.h"
using namespace std;

class savingsAccount :
	public bankAccount
{
private:
	double interestRate;
public:
	savingsAccount();
	savingsAccount(string acctNum, double startBal, double intRate);
	~savingsAccount();
	double getInterestRate();
	double postInterest();
	void print();
	void setInterestRate(double intRate);
	double withdraw(double withdrawalAmt);
};

#endif