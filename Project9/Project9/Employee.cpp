#include <iostream>
#include "Employee.h"

using std::string;
using std::cout;

Employee::Employee(const string& FullName, ui Salary = 0) :Initials(FullName), Money(Salary)
{
	
}

Employee::~Employee() 
{
}