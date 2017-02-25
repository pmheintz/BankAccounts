/* Paul Heintz heintzpm@gmatc.matc.edu
* ITDEV-154 Downtown
* Bank account user interface header
* February 5, 2017 */

#ifndef BANKACCOUNTUI_H
#define BANKACCOUNTUI_H
#include <iostream>
#include <string>
#include <iomanip>
#include "bankAccount.h"
#include "checkingAccount.h"
#include "savingsAccount.h"
using namespace std;

class BankAccountUI
{
private:
	string acctNum;
	double startBal;
	double intRate;
	double minBalance;
	double srvCharge;
public:
	BankAccountUI();
	~BankAccountUI();
	void displayWelcome();
	void mainMenu();
	void checkingAccountMenu();
	void savingsAccountMenu();
	void createChkAcct();
	void createSavAcct();
	double getDouble();
	void displayChkMenu();
	void displaySavMenu();
};

#endif