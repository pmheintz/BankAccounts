/* Paul Heintz heintzpm@gmatc.matc.edu
* ITDEV-154 Downtown
* Bank account user interface for testing program
* February 5, 2017 */

#include "BankAccountUI.h"

BankAccountUI::BankAccountUI()
{
}


BankAccountUI::~BankAccountUI()
{
}

void BankAccountUI::displayWelcome()
{
	cout << endl << "** NOTE - The options available do not reflect a real banking program **" << endl << endl;
	cout << "Thank you for banking with ITDEV-155 Bank!" << endl;
	cout << "Please choose an option from the menu below." << endl << endl;
}

void BankAccountUI::mainMenu()
{
	int selection = -1;
	do
	{
		cout << "Enter 1 to create a checking account." << endl;
		cout << "Enter 2 to create a savings account." << endl;
		cout << "Enter 0 to quit." << endl;
		do
		{
			cout << "Enter your selection: ";
			cin >> selection;
			if (!(cin))
			{
				cin.clear();
				cin.ignore();
				selection = -1;
			}
		} while (selection != 0 && selection != 1 && selection != 2);

		if (selection == 1)
			checkingAccountMenu();
		else if (selection == 2)
			savingsAccountMenu();
		else
			cout << "Thank you. Goodbye.";

		cin.ignore();
	} while (selection != 0);	
}

void BankAccountUI::checkingAccountMenu()
{
	cout << fixed << setprecision(2) << endl;
	createChkAcct();
	checkingAccount myChkAcct(acctNum, startBal, intRate, minBalance, srvCharge);

	int selection = 0;
			string person;
			double curBal, curMinBal, chkAmmt = 0;
	displayChkMenu();
	do
	{
		cin >> selection;
		if (!(cin))
		{
			cin.clear();
			cin.ignore();
			cout << endl << "**Invalid selection**" << endl;
			selection = 2;
		}
		switch (selection)
		{
		case 0:
			cout << endl;
			break;
		case 1:
			cout << endl << "Your balance is $" << myChkAcct.getBalance() << endl;
			displayChkMenu();
			break;
		case 2:
			cout << endl; 
			myChkAcct.print();
			cout << endl;
			displayChkMenu();
			break;
		case 3:
			cout << endl << "How much money would you like to withdraw: $";
			cout << "Your current balance is $" << myChkAcct.withdraw(getDouble()) << endl;
			displayChkMenu();
			break;
		case 4:
			cout << endl << "Enter name or account of person check is for: ";
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			std::getline(std::cin, person);
			cout << "Enter the check amount: $";
			chkAmmt = getDouble();
			myChkAcct.writeCheck(person, chkAmmt);
			displayChkMenu();
			break;
		case 5:
			curMinBal = myChkAcct.getMinimumBalance();
			curBal = myChkAcct.getBalance();
			cout << endl << "Your minimum balance is $" << curMinBal << endl;
			cout << "Your current balance is $" << curBal << endl;
			if (curBal < curMinBal)
			{
				cout << "You are below your minimum balance! Please deposit some more money." << endl;
			}
			displayChkMenu();
			break;
		case 6:
			cout << endl << "Your current balance is $" << myChkAcct.getBalance() << endl;
			cout << "You've gained $" << myChkAcct.postInterest() << " in interest!" << endl;
			cout << "Your new balance is $" << myChkAcct.getBalance() << endl;
			displayChkMenu();
			break;
		case 7:
			cout << endl << "How much money are you depositing: $";
			myChkAcct.deposit(getDouble());
			cout << "Your new balance is: $" << myChkAcct.getBalance() << endl;
			displayChkMenu();
			break;
		default:
			cout << endl << "**Invalid selection**" << endl;
			selection = 0;
			break;
		}
	} while (selection >= 1 && selection <= 7);

	//cin.ignore();
}

void BankAccountUI::savingsAccountMenu()
{
	cout << fixed << setprecision(2) << endl;
	createSavAcct();
	savingsAccount mySavAccount(acctNum, startBal, intRate);

	int selection = 0;
	string person;
	double curBal, curMinBal;
	displaySavMenu();
	do
	{
		cin >> selection;
		if (!(cin))
		{
			cin.clear();
			cin.ignore();
			cout << endl << "**Invalid selection**" << endl;
			selection = 2;
		}
		switch (selection)
		{
		case 0:
			cout << endl;
			break;
		case 1:
			cout << endl << "Your account balance is $" << mySavAccount.getBalance() << endl;
			displaySavMenu();
			break;
		case 2:
			cout << endl;
			mySavAccount.print();
			cout << endl;
			displaySavMenu();
			break;
		case 3:
			cout << endl << "How much money would you like to withdraw: $";
			cout << "Your current balance is $" << mySavAccount.withdraw(getDouble()) << endl;
			displaySavMenu();
			break;
		case 4:
			cout << endl << "How much money would you like to deposit: $";
			cout << "Your current balance is $" << mySavAccount.deposit(getDouble()) << endl;
			displaySavMenu();
			break;
		case 5:
			cout << endl << "Your current balance is $" << mySavAccount.getBalance() << endl;
			cout << "You've gained $" << mySavAccount.postInterest() << " in interest!" << endl;
			cout << "Your new balance is $" << mySavAccount.getBalance() << endl;
			displaySavMenu();
			break;
		case 6:
			cout << endl << "Enter your new interest rate %";
			mySavAccount.setInterestRate(getDouble());
			cout << endl << "Your interest rate has been set to %" << mySavAccount.getInterestRate() << endl;
			displaySavMenu();
			break;
		default:
			cout << endl << "**Invalid selection**" << endl;
			selection = 0;
			break;
		}
	} while (selection >= 1 && selection <= 6);

	//cin.ignore();
}

void BankAccountUI::createChkAcct()
{
	cout << "Enter a checking account number: ";
	cin >> acctNum;
	cout << "Enter your starting balance: $";
	startBal = getDouble();
	cout << "Enter your interest rate: %";
	intRate = getDouble();
	cout << "Enter your minimum balance: $";
	minBalance = getDouble();
	cout << "Enter your service charge: $";
	srvCharge = getDouble();
	cout << endl;
}
void BankAccountUI::createSavAcct()
{
	cout << "Enter a savings account number: ";
	cin >> acctNum;
	cout << "Enter your starting balance: $";
	startBal = getDouble();
	cout << "Enter your interest rate: %";
	intRate = getDouble();
	cout << endl;
}
// function to verify input is a double and returns that value
double BankAccountUI::getDouble()
{
	double myDouble;

	while (!(cin >> myDouble))
	{
		cin.clear();
		cin.ignore();
		cout << "*ERROR* Invalid value, try again: ";
	}
	return myDouble;
}

void BankAccountUI::displayChkMenu()
{
	cout << endl << "1) Check balance" << endl;
	cout << "2) Display account info" << endl;
	cout << "3) Withdraw money" << endl;
	cout << "4) Write a check" << endl;
	cout << "5) Check minimum balance" << endl;
	cout << "6) Post interest" << endl;
	cout << "7) Deposit money" << endl;
	cout << "0) Exit to main menu" << endl;
	cout << "Your selection: ";
}

void BankAccountUI::displaySavMenu()
{
	cout << endl << "1) Check balance" << endl;
	cout << "2) Display account info" << endl;
	cout << "3) Withdraw money" << endl;
	cout << "4) Deposit money" << endl;
	cout << "5) Post interest" << endl;
	cout << "6) Change interest rate" << endl;
	cout << "0) Exit to main menu" << endl;
	cout << "Your selection: ";
}
