#include "Secretary.h"

using std::cout;

void Secretary::ShowStaffD(Director* D) 
{
	cout << "Director's " << D->GetName() << "Staff: \n";
	for (int i = 0; i < D->StaffOfEmployees.size(); i++)
	{
		cout << "SySAdm:\n";
		if (D->StaffOfEmployees[i]->GetPost() == "SysAdm")
		{
			cout.width(25);
			cout.fill('-');
			cout << D->StaffOfEmployees[i]->GetName() << " \n";
		}
	}
	cout << "\n";
	for (int i = 0; i < D->StaffOfEmployees.size(); i++)
	{
		cout << "Secretary:\n";
		if (D->StaffOfEmployees[i]->GetPost() == "Secretary")
		{
			cout.width(25);
			cout.fill('-');
			cout << D->StaffOfEmployees[i]->GetName() << " \n";
		}
	}
	cout << "\n";
	for (int i = 0; i < D->StaffOfEmployees.size(); i++)
	{
		cout << "Bookkeeper:\n";
		if (D->StaffOfEmployees[i]->GetPost() == "Bookkeeper")
		{
			cout.width(25);
			cout.fill('-');
			cout << D->StaffOfEmployees[i]->GetName() << " \n";
		}
	}
	cout << "\n";
}

Secretary::Secretary(const string& FullName, ui Salary) : Employee(FullName, Salary)
{
	Post_ = "Secretary";
	cout << "Secretary created!\n";
}
void Secretary::ShowEquipmentAdm(SysAdm* A) 
{
	A->ShowEquipmentlist();
}
void Secretary::ShowThis()
{
	cout <<"Post: "<<Post_ << "\n";
	cout <<"Name: "<<GetName() << "\n";
	cout <<"Salary: "<<GetSalary() << "\n";
}
void Secretary::GetDriversMas(vector<Director*> vd)
{
	for (int i = 0; i < vd.size(); i++) 
	{
		for (int j = 0; j < vd[i]->GetStaffOfEmployeesSize(); j++) 
		{
			if (vd[i]->StaffOfEmployees[j]->GetPost() == "Driver") 
			{
				DriversM.push_back(dynamic_cast<Driver*>(vd[i]->StaffOfEmployees[j]));
			}
		}
	}
}

void Secretary::ShowDrivers(vector <Driver*>Drv)
{
	cout << "Drivers:\n";
	for (int i = 0; i < Drv.size(); i++)
	{
		cout.width(25);
		cout.fill('-');
		cout << Drv[i]->GetName() << "\n";
	}
}