/* Paul Heintz heintzpm@gmatc.matc.edu
* ITDEV-154 Downtown
* Bank account program with inheritance
* February 5, 2017 */

#include <iostream>
#include "info.h"
#include "BankAccountUI.h"

using namespace std;

void main()
{
	info myInfo("Paul Heintz", 2, "Inheritance");
	myInfo.displayInfo();

	BankAccountUI theUI;
	theUI.displayWelcome();
	theUI.mainMenu();

	cin.ignore();
}