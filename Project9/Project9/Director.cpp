#include <iostream>
#include "Director.h"
#include "Secretary.h"


using std::vector;
using std::string;
using std::cout;
using std::cin;


Director::Director(const string& FullName, ui Salary) : Employee(FullName, Salary)
{
	Post_ = "Diretor";
}

void Director::GetEmployee()
{
	cout << " Add an employee: \n";
	string FullName;
	cout << "Enter Name:";
	cin.get();
	getline(cin, FullName);
	ui Salary;
	cout << "Enter Salary:";
	cin >> Salary;
	cin.get();
	cout << "\n  0 - SysAdm / 1 - Bookkeeper / 2 - Driver/ 3 - Secretary: \n";
	ui a;
	try
	{
		cin >> a;
		if ((a < 0) || (a > 3)) throw invalid_argument("Argument too large or negative.\n");
	}
	catch (invalid_argument& e)
	{
		cerr << e.what() <<"\n";
		return;
	}
	if (a == 0) 
	{
		SysAdm* newEmployee = new SysAdm(FullName, Salary);
		StaffOfEmployees.push_back(newEmployee);
	}
	if (a == 1)
	{
		Bookkeeper* newEmployee = new Bookkeeper(FullName, Salary);
		StaffOfEmployees.push_back(newEmployee);
	}
	if (a == 2) 
	{
		Driver* newEmployee = new Driver(FullName, Salary);
		StaffOfEmployees.push_back(newEmployee);
	}
	if (a == 3)
	{
		Secretary* newEmployee = new Secretary(FullName, Salary);
		StaffOfEmployees.push_back(newEmployee);
	}
}

void Director::ShowEmployees() const 
{
	cout << "\n" << "Director: " << GetName() << " \n\n";
	cout << "Now the staff consists of " << StaffOfEmployees.size() << " Employees: \n";
	for (int i = 0, j = 1; i < StaffOfEmployees.size(); i++, j++)
	{
		cout << j;
		cout.width(26);
		cout.fill('-');
		cout<<StaffOfEmployees[i]->GetName() << "\t";
		cout.width(25);
		cout.fill('-');
		cout << StaffOfEmployees[i]->GetPost() << "\t";
		cout.width(25);
		cout.fill('-');
		cout<< " Salary: " << StaffOfEmployees[i]->GetSalary() <<"$"<<"\n";
	}
}
void Director::DeleteEmployee(int num)
{
	delete StaffOfEmployees[num - 1];
	StaffOfEmployees.erase(StaffOfEmployees.begin() + num - 1, StaffOfEmployees.begin() + num);
}

void Director::ShowEmployee(int num) const
{
	try
	{
		if ((num > StaffOfEmployees.size()) || (num < 1))  throw invalid_argument("Argument too large or negative.\n");
	}
	catch (invalid_argument& e)
	{
		cerr << e.what() << "\n";
		return;
	}
	cout << "Employee number " << num << " is ";
	cout << StaffOfEmployees[num-1]->GetName();
	cout << " His salary is: " << StaffOfEmployees[num-1]->GetSalary() << "$" << "\n";
}

void Director::ShowThis() 
{
	cout << "Post: " << Post_ << "\n";
	cout << "Name: " << GetName() << "\n";
	cout << "Salary: " << GetSalary() << "\n";
}

Employee* Director::ReturnEmployee(ui num) 
{
	return (StaffOfEmployees[num - 1]);
}
