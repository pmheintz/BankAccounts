/* Paul Heintz heintzpm@gmatc.matc.edu
* ITDEV-154 Downtown
* Info source
* January 16, 2017 */

#include "info.h"

info::info() //Default constructor
{
	name = "Paul Heintz";
	assignName = "Undefined";
	assignNum = NULL;
}

info::info(string myName, int assignmentNum, string assignmentName) //overloaded constructor
{
	name = myName;
	assignNum = assignmentNum;
	assignName = assignmentName;
}

info::~info()
{
}

void info::displayInfo()
{
	cout << "*******************************************************************************" << endl;
	cout << "* Programmer:      " << name << endl;
	cout << "* Course:          ITDEV154 - Data Structures" << endl;
	cout << "* Instructor:      Judith Ligocki" << endl;
	cout << "* Assignment:      " << assignNum << " - " << assignName << endl;
	cout << "* Compile Date:    " << __DATE__ << " " << __TIME__ << endl;
	cout << "*******************************************************************************" << endl;
}
// getters and setters
void info::setName(string myName)
{
	name = myName;
}

string info::getName()
{
	return name;
}

void info::setAssignName(string assignmentName)
{
	assignName = assignmentName;
}

string info::getAssignName()
{
	return assignName;
}

void info::setAssignNum(int assignmentNum)
{
	assignNum = assignmentNum;
}

int info::getAssignNum()
{
	return assignNum;
}
