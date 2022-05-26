#include "SysAdm.h"

using std::vector;
using std::cout;
using std::cin;



SysAdm::SysAdm(const string& FullName, ui Salary) :Employee(FullName, Salary) 
{
	Post_ = "SysAdm";
	cout << "SysAdm created!\n";
}
void SysAdm::GetEquipment() 
{
	cout << "Add to Equipment : \n"
		<< "0 - exit\n"
		<< "1 - Laptop\n"
		<< "2 - Smartphone\n"
		<< "3 - Server\n"
		<< "4 - Tools\n"
		<< "5 - Patch cords and adapters\n"
		<< "6 - Medical kit \n";
	bool flag = true;
	while (flag)
	{
		int a;
		cin >> a;
		try
		{
			if ((a > 6) || (a < 0))  throw invalid_argument("Argument too large or negative.\n");
		}
		catch (invalid_argument& e)
		{
			cerr << e.what() << "\n";
			break;
		}
		if (a == 0) break;
		if (a == 1)
		{
			Equipmentlist.push_back("Laptor");
			cout << "Laptor added\n";
		}
		if (a == 2)
		{
			Equipmentlist.push_back("Smartphone");
			cout << "Smartphone added\n";
		}
		if (a == 3)
		{
			Equipmentlist.push_back("Server");
			cout << "Server added\n";
		}
		if (a == 4)
		{
			Equipmentlist.push_back("Tools");
			cout << "Tools added\n";
		}
		if (a == 5)
		{
			Equipmentlist.push_back("Patch cords and adapters");
			cout << "Patch cords and adapters added\n";
		}
		if (a == 6)
		{
			Equipmentlist.push_back("Medical kit");
			cout << "Medical kit\n";
		}
		
	}
}
int arrayy[6] = { 0 };
void SysAdm::ShowEquipmentlist()  
{
	cout << "SysAdm " << GetName()<< " \n";
	cout << "Now in the list of equipment there are: " << Equipmentlist.size() << " things:\n";
	if (Equipmentlist.size() == 0) return;
	//int array[6] = { 0 };
	for (int i = 0; i < 6; i++) 
	{
		arrayy[i] = 0;
	}
	for (int i = 0;i < Equipmentlist.size(); i++)
	{
		if (Equipmentlist[i] == "Laptor") arrayy[0]++;
		if (Equipmentlist[i] == "Smartphone") arrayy[1]++;
		if (Equipmentlist[i] == "Server") arrayy[2]++;
		if (Equipmentlist[i] == "Tools") arrayy[3]++;
		if (Equipmentlist[i] == "Patch cords and adapters") arrayy[4]++;
		if (Equipmentlist[i] == "Medical kit") arrayy[5]++;
	}
	cout.width(35);
	cout.fill('*');
	cout << "Laptor(" << arrayy[0] << ")\n";
	cout.width(35);
	cout.fill('*');
	cout << "Smartphone(" << arrayy[1] << ")\n";
	cout.width(35);
	cout.fill('*');
	cout << "Server(" << arrayy[2] << ")\n";
	cout.width(35);
	cout.fill('*');
	cout << "Tools(" << arrayy[3] << ")\n";
	cout.width(35);
	cout.fill('*');
	cout << "Patch cords and adapters(" << arrayy[4] << ")\n";
	cout.width(35);
	cout.fill('*');
	cout<< "Medical kit(" << arrayy[5] << ")\n";
}

void SysAdm::DeleteEquipment(int num) 
{
	try
	{
		if ((num > 6) || (num < 0))  throw invalid_argument("Argument too large or negative.\n");
	}
	catch (invalid_argument& e)
	{
		cerr << e.what() << "\n";
		return;
	}
	string Eq;
	int pos;
	bool flag = false;
	if (GetEquipmentlistsize() == 0||(arrayy[num-1]==0))
	{
		cout << "No equipment\n!";
		return;
	}
	else
	{
		if (num == 1)
		{
			Eq = "Laptor";
		}
		if (num == 2)
		{
			Eq = "Smartphone";
		}
		if (num == 3)
		{
			Eq = "Server";
		}
		if (num == 4)
		{
			Eq = "Tools";
		}
		if (num == 5)
		{
			Eq = "Patch cords and adapters";
		}
		if (num == 6)
		{
			Eq = "Medical kit";
		}
	}
	for (int i = 0; i < Equipmentlist.size(); i++) 
	{
		if (Equipmentlist[i] == Eq) 
		{
			flag = true;
			pos = i;
		}
	}
	if (flag)
	{
		cout << "Equipment " << num << " deleted\n";
		Equipmentlist.erase(Equipmentlist.begin() + pos, Equipmentlist.begin() + pos + 1);
	}
	else 
	{
		cout << "Equipment not found\n";
	}
}
ui SysAdm::GetEquipmentlistsize() 
{
	return Equipmentlist.size();
}
void SysAdm::ShowThis()
{
	cout << "Post: " << Post_ << "\n";
	cout << "Name: " << GetName() << "\n";
	cout << "Salary: " << GetSalary() << "\n";
}