/* Paul Heintz heintzpm@gmatc.matc.edu
* ITDEV-154 Downtown
* Checking account derived class header
* February 5, 2017 */

#ifndef CHECKINGACCOUNT_H
#define CHECKINGACCOUNT_H
#include "bankAccount.h"
#include <iostream>
#include <string>
using namespace std;

class checkingAccount :
	public bankAccount
{
private:
	double interestRate;
	double minimumBalance;
	double serviceCharge;
public:
	checkingAccount();
	checkingAccount(string acctNum, double startBal, double intRate, double minBalance, double srvCharge);
	~checkingAccount();
	double getInterestRate();
	double getMinimumBalance();
	double getServiceCharge();
	double postInterest();
	void print();
	void setInterestRate(double intRate);
	void setMinimumBalance(double minBalance);
	void setServiceCharge(double srvCharge);
	bool verifyMinimumBalance();
	double withdraw(double withdrawalAmt);
	void writeCheck(string recipient, double checkAmount);
};

#endif