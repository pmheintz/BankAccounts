/* Paul Heintz heintzpm@gmatc.matc.edu
* ITDEV-154 Downtown
* Checking account derived class
* February 5, 2017 */

#include "checkingAccount.h"

checkingAccount::checkingAccount()
{
}

checkingAccount::checkingAccount(string acctNum, double startBal, double intRate, double minBalance, double srvCharge)
{
	bankAccount::accountNumber = acctNum;
	bankAccount::balance = startBal;
	interestRate = intRate;
	minimumBalance = minBalance;
	serviceCharge = srvCharge;
}


checkingAccount::~checkingAccount()
{
}

double checkingAccount::getInterestRate()
{
	return interestRate;
}

double checkingAccount::getMinimumBalance()
{
	return minimumBalance;
}

double checkingAccount::getServiceCharge()
{
	return serviceCharge;
}

// Multiplies balance times interest rate (as percentage) divided by 100, adds interest to balance, 
// and returns interest gained
double checkingAccount::postInterest()
{
	if (balance <= 0)
	{
		return 0;
	}
	double interest = 0;
	interest = bankAccount::balance * (interestRate / 100);
	bankAccount::balance += interest;
	return interest;
}

void checkingAccount::print()
{
	cout << endl << "Your account Number:   " << getAccountNumber() << endl;
	cout << "Your current balance:  $" << getBalance() << endl;
	cout << "Your interest rate:    %" << getInterestRate() << endl;
	cout << "Your minimum balance:  $" << getMinimumBalance() << endl;
	cout << "Your service charge:   $" << getServiceCharge() << endl;
}

void checkingAccount::setInterestRate(double intRate)
{
	interestRate = intRate;
}

void checkingAccount::setMinimumBalance(double minBalance)
{
	minimumBalance = minBalance;
}

void checkingAccount::setServiceCharge(double srvCharge)
{
	serviceCharge = srvCharge;
}

// returns true if balance is below minimum balance
bool checkingAccount::verifyMinimumBalance()
{
	bool balanceBelow = false;

	if (bankAccount::balance < minimumBalance)
		balanceBelow = true;

	return balanceBelow;
}

double checkingAccount::withdraw(double withdrawalAmt)
{
	//check if enough balance
	if ((bankAccount::balance - withdrawalAmt) < 0)
	{
		cout << endl << "This will overdraw your account! Can not withdraw." << endl;
	}
	else
	{
		bankAccount::balance -= withdrawalAmt;
		if (verifyMinimumBalance())
		{
			balance -= getServiceCharge();
			cout << "You've dropped below your minimum balacnce!" << endl;
			cout << "You've been charged a fee of $" << getServiceCharge() << endl;
		}
	}
	return bankAccount::balance;
}

void checkingAccount::writeCheck(string recipient, double checkAmount)
{
	if ((balance - checkAmount) < 0)
	{
		cout << "Insufficient funds" << endl;
		return;
	}
	withdraw(checkAmount);
	//check min balance and charge if below min balance
	if (verifyMinimumBalance())
	{
		balance -= getServiceCharge();
		cout << "You've dropped below your minimum balacnce!" << endl;
		cout << "You've been charged a fee of $" << getServiceCharge();
	}
	cout << endl << "Check sent to " << recipient << " for $" << checkAmount << endl;
	cout << "Your current balance is $" << getBalance() << endl;
}
