#include "Bookkeeper.h"

using std::cout;
using std::cin;


Bookkeeper::Bookkeeper(const string& FullName, ui Salary):Employee(FullName, Salary)
{
	Post_="Bookkeeper";
}


void Bookkeeper::SetSalary(Employee* E)
{
	cout << "Salary establishment\n";
	if (E->GetPost() == "Diretor") 
	{
		if (Salary_ == 0)
		{
			E->Salary_ = minDiretor;
			return;
		}
		if (E->Salary_ < minDiretor) 
		{
			Salary_ = minDiretor + 2500;
			return;
		}
		cout << "Salary establishment\n";
	}
	if (E->GetPost() == "Bookkeeper")
	{
		if (Salary_ == 0)
		{
			E->Salary_ = minBookkeeper;
			return;
		}
		if (E->Salary_ < minBookkeeper)
		{
			E->Salary_ = minBookkeeper + 2500;
			return;
		}
		cout << "Salary establishment\n";
	}
	if (E->GetPost() == "SysAdm")
	{
		if (Salary_ == 0)
		{
			E->Salary_ = minSysAdm;
			return;
		}
		if (E->Salary_ < minSysAdm)
		{
			E->Salary_ = minSysAdm + 1500;
			return;
		}
		cout << "Salary establishment\n";
	}
	if (E->GetPost() == "Driver")
	{
		if (Salary_ == 0)
		{
			E->Salary_ = minDriver;
			return;
		}
		if (E->Salary_ < minDriver)
		{
			E->Salary_ = minDriver + 1500;
			return;
		}
	}
	if (E->GetPost() == "Secretary")
	{
		if (Salary_ == 0)
		{
			E->Salary_ = minSecretary;
			return;
		}
		if (E->Salary_ < minSecretary)
		{
			E->Salary_ = minSecretary + 2000;
			return;
		}
		cout << "Salary establishment\n";
	}
}	

void Bookkeeper::SetMin() 
{
	cout << "Set Min or Exit:\n"
		<< " 0 - Exit Back\n"
		<< " 1 - minDiretor\n"
		<< " 2 - minBookkeeper\n"
		<< " 3 - minSysAdm\n"
		<< " 4 - minDriver\n"
		<< " 5 - minSecretary\n";
	ui key;
	cin >> key;
	try
	{
		if ((key > 5) || (key < 0))  throw invalid_argument("Argument too large or negative.\n");
	}
	catch (invalid_argument& e)
	{
		cerr << e.what() << "\n";
		return;
	}
	if (key == 0)return;
	if (key == 1) 
	{
		cout << "for Director:";
		cin >> minDiretor;
	}
	if (key == 2)
	{
		cout << "for Bookkeeper:";
		cin >> minBookkeeper;
	}
	if (key == 3)
	{
		cout << "for SysAdm:";
		cin >> minSysAdm;
	}
	if (key == 4)
	{
		cout << "for Driver:";
		cin >> minDriver;
	}
	if (key == 5)
	{
		cout << "for Secretary:";
		cin >> minSecretary;
	}
}

void Bookkeeper::ShowThis() 
{
	cout << "Post: " << Post_ << "\n";
	cout << "Name: " << GetName() << "\n";
	cout << "Salary: " << GetSalary() << "\n";
}