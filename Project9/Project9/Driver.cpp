#include "Driver.h"

using std:: cout;
using std:: cin;

Driver::Driver(const string& FullName, ui Salary) : Employee(FullName, Salary)
{
	Post_ = "Driver";
	cout << "Driver created!\n";
}
void Driver::ShowTransportList()
{
	cout << "Driver has " << TransportList.size() << " transport units:\n";
	for (int i = 0; i < TransportList.size(); i++)
	{
		cout << TransportList[i] << " ";
	}
	cout << "\n";
}
void Driver::ShowDriversLicenseList() 
{
	for (int i = 0; i <DriversLicense.size(); i++)
	{
		cout << DriversLicense[i] << "\n";
	}
}

void Driver::GetTransport() 
{
	if (TransportList.size() == 3)
	{
		cout << "Garage is full\n";
		return;
	}
	ui key;
	cout << "Get Transport:\n"
		<< " or Exit Back:\n"
		<< "0 - Break\n"
		<< "1 - Truck\n"
		<< "2 - Car\n"
		<< "3 - Bike\n";
	try
	{
		cin >> key;
		if ((key < 0) || (key > 3)) throw invalid_argument("Argument too large or negative.\n");
	}
	catch (invalid_argument& e)
	{
		cerr << e.what() << "\n";
		return;
	}
	if (key == 0) return;
	if (key == 1) 
	{
		for (int i = 0; i < TransportList.size(); i++) 
		{
			if (TransportList[i] == "Truck") 
			{
				cout << "Truck is already there\n";
				return;
			}
		}
		TransportList.push_back("Truck");
		cout << "Truck Added\n";
	}
	if (key == 2)
	{
		for (int i = 0; i < TransportList.size(); i++)
		{
			if (TransportList[i] == "Car")
			{
				cout << "Car is already there\n";
				return;
			}
		}
		TransportList.push_back("Car");
		cout << "Car Added\n";
	}
	if (key == 3)
	{
		for (int i = 0; i < TransportList.size(); i++)
		{
			if (TransportList[i] == "Bike")
			{
				cout << "Bike is already there\n";
				return;
			}
		}
		TransportList.push_back("Bike");
		cout << "Bike Added\n";
	}

}

void Driver::DeleteTransport() 
{
	ui key;
	cout << "Delete Transport:\n"
		<< " or Exit Back:\n"
		<< "0 - Break\n"
		<< "1 - Truck\n"
		<< "2 - Car\n"
		<< "3 - Bike\n";
	try
	{
		cin >> key;
		if ((key < 0) || (key > 3)) throw invalid_argument("Argument too large or negative.\n");
	}
	catch (invalid_argument& e)
	{
		cerr << e.what() << "\n";
		return;
	}
	if (key == 0) return;
	if (key == 1)
	{
		for (int i = 0; i < TransportList.size(); i++)
		{
			if (TransportList[i] == "Truck")
			{
				TransportList.erase(TransportList.begin() + i, TransportList.begin() + i + 1);
				cout << "Truck deleted!\n";
			}
		}
	}
	if (key == 2)
	{
		for (int i = 0; i < TransportList.size(); i++)
		{
			if (TransportList[i] == "Car")
			{
				TransportList.erase(TransportList.begin() + i, TransportList.begin() + i + 1);
				cout << "Car deleted!\n";
			}
		}
	}
	if (key == 3)
	{
		for (int i = 0; i < TransportList.size(); i++)
		{
			if (TransportList[i] == "Bike")
			{
				TransportList.erase(TransportList.begin() + i, TransportList.begin() + i + 1);
				cout << "Bike deleted!\n";
			}
		}
	}
}

void Driver::ShowThis() 
{
		cout << "Post: " << Post_ << "\n";
		cout << "Name: " << GetName() << "\n";
		cout << "Salary: " << GetSalary() << "\n";
}