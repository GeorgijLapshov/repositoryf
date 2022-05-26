#include <iostream>
#include <vector>
#include "Employee.h"
#include "Director.h"
#include "Bookkeeper.h"
#include "Secretary.h"

using namespace std;

string s1 = "Oleg";
string s2 = "Ilya";
class DeathDiamond : public Driver, public SysAdm
{
public:
	DeathDiamond() :
		Driver(s1), SysAdm(s2)
	{
		cout << "\tDiamond created\n";
	}
	void GetPost() {
		cout << "GetPost for Driver: " << Driver::GetPost() << '\n';
		cout << "GetPost for SysAdm: " << SysAdm::GetPost() << '\n';
	}
};

void ShowDirectors(vector<Director*> &vec);

Director* FuncAddD();

int main()
{
	vector <Director*> D;
	ui key;
	while (true)
	{
		ShowDirectors(D);
		cout << " Or press 0< or > " <<D.size()<<" and go to the SysAdm & Driver DeathDiamond!...\n";
		try
		{
			cin >> key;
			cin.get();
			if ((key > D.size()) || (key < 0))  throw invalid_argument("Argument too large or negative.\n");
		}
		catch (invalid_argument& e)
		{
			cerr << e.what() << endl;
			break;
		}
			if (key == 0)
			{
				D.push_back(FuncAddD());
				//cin.get();
			}
			else
			{
				ui key1;
				for (;;)
				{
					cout << "what do you want to do?\n"
						<< " 0 - Exit Back\n"
						<< " 1 - Add Employee\n"
						<< " 2 - Show Employee\n"
						<< " 3 - Show Employees\n"
						<< " 4 - Get Name\n"
						<< " 5 - Get Post\n"
						<< " 6 - Get Salary\n"
						<< " 7 - Delete Employee\n"
						<< " 8 - Show This" << endl;
					try 
					{
						cin >> key1;
						if ((key1 > 8) || (key1 < 0))  throw invalid_argument("Argument too large or negative.\n");
					}
					catch (invalid_argument& e)
					{
						cerr << e.what() << endl;
						break;
					}
						if (key1 == 0) break;
						if (key1 == 1) D[key - 1]->GetEmployee();
						if (key1 == 2)
						{
							cout << " Enter employee nymber: ";
							int c;
							cin >> c;
							cin.get();
							if (c > D[key - 1]->GetStaffOfEmployeesSize())
							{
								cout << "No such Employee! \n";
							}
							else
							{
								D[key - 1]->ShowEmployee(c);
							}
						}
						if (key1 == 3) D[key - 1]->ShowEmployees();
						if (key1 == 4) cout << D[key - 1]->GetName() << endl;
						if (key1 == 5) cout << D[key - 1]->GetPost() << endl;
						if (key1 == 6) cout << D[key - 1]->GetSalary() << endl;
						if (key1 == 7)
						{
							cout << " Enter employee nymber: ";
							int c;
							cin >> c;
							if (c > D[key - 1]->GetStaffOfEmployeesSize() || (c < 0))
							{
								cout << "No such Employee! \n";
							}
							else
							{
								D[key - 1]->DeleteEmployee(c);
							}
						}
						if (key1 == 8) D[key - 1]->ShowThis();
						//если сотрудники добавлены :
						if (D[key - 1]->GetStaffOfEmployeesSize() == 0) continue;
						else
						{
							// показать список
							if (key1 != 3) D[key - 1]->ShowEmployees();
							ui number;
							cout << "Enter, number to continue, or 0 to break: ";
							cin >> number;
							cin.get();
							if (number == 0) continue;
							else
							{
								if (D[key - 1]->ReturnEmployee(number)->GetPost() == "SysAdm")
								{
									//меню SysAdm
									for (;;)
									{
										ui keey;
										cout << "what do you want to do?\n"
											<< " 0 - Exit Back\n"
											<< " 1 - Get Equipment\n"
											<< " 2 - Show EuipmentList\n"
											<< " 3 - Delete Equipment\n"
											<< " 4 - Show This" << endl;
										cin >> keey;
										cin.get();
										if ((keey == 0) || keey > 4)
										{
											break;
										}
										if (keey == 1)
										{
											dynamic_cast<SysAdm*>(D[key - 1]->ReturnEmployee(number))->GetEquipment();
										}
										if (keey == 2)
										{
											dynamic_cast<SysAdm*>(D[key - 1]->ReturnEmployee(number))->ShowEquipmentlist();
										}
										if (keey == 3)
										{
											ui EquipmentNumber;
											cout << "Enter the Equipment's number to delete: ";
											cin >> EquipmentNumber;
											dynamic_cast<SysAdm*>(D[key - 1]->ReturnEmployee(number))->DeleteEquipment(EquipmentNumber);
										}
										if (keey == 4)
										{
											dynamic_cast<SysAdm*>(D[key - 1]->ReturnEmployee(number))->ShowThis();
										}
									}
								}
								if (D[key - 1]->ReturnEmployee(number)->GetPost() == "Driver")
								{
									//меню Driver
									for (;;)
									{
										ui keey;
										cout << "what do you want to do?\n"
											<< " 0 - Exit Back\n"
											<< " 1 - Get Transport\n"
											<< " 2 - Show Transport\n"
											<< " 3 - Show DriversLicense\n"
											<< " 4 - Delete Transport\n"
											<< " 5 - Show This\n";
										cin >> keey;
										cin.get();
										if ((keey == 0) || keey > 5)
										{
											break;
										}
										if (keey == 1)
										{
											dynamic_cast<Driver*>(D[key - 1]->ReturnEmployee(number))->GetTransport();
										}
										if (keey == 2)
										{
											dynamic_cast<Driver*>(D[key - 1]->ReturnEmployee(number))->ShowTransportList();
										}
										if (keey == 3)
										{
											dynamic_cast<Driver*>(D[key - 1]->ReturnEmployee(number))->ShowDriversLicenseList();
										}
										if (keey == 4)
										{
											dynamic_cast<Driver*>(D[key - 1]->ReturnEmployee(number))->DeleteTransport();
										}
										if (keey == 5)
										{
											dynamic_cast<Driver*>(D[key - 1]->ReturnEmployee(number))->ShowThis();
										}
									}
								}
								if (D[key - 1]->ReturnEmployee(number)->GetPost() == "Bookkeeper")
								{
									for (;;)
									{
										ui keey;
										cout << "what do you want to do?\n"
											<< " 0 - Exit Back\n"
											<< " 1 - Set Minimum\n"
											<< " 2 - SetSalary\n"
											<< " 3 - Show This\n";
										try
										{
											cin >> keey;
											if ((keey > 3) || (keey < 0))  throw invalid_argument("Argument too large or negative.\n");
										}
										catch (invalid_argument& e)
										{
											cerr << e.what() << endl;
											break;
										}
										if (keey == 0)
										{
											break;
										}
										if (keey == 1)
										{
											dynamic_cast<Bookkeeper*>(D[key - 1]->ReturnEmployee(number))->SetMin();
										}
										if (keey == 2)
										{
											cout << "Select Director, Employee\n ";
											cout << "Select Director:\n";
											for (int i = 0; i < D.size(); i++)
											{
												cout << "Select for\nDiretor - 0/ Employee - 1/\n2 - next\n";
												ui keeey;
												cin >> keeey;
												if (keeey == 2) continue;
												if (keeey == 0)
												{
													cout << "This? - 0 - no/ 1 - yes\n";
													cout << D[i]->GetName() << "\n";
													ui keyD;
													cin >> keyD;
													if (keyD == 1)
													{
														dynamic_cast<Bookkeeper*>(D[key - 1]->ReturnEmployee(number))
															->SetSalary(D[i]);
														break;
													}
													if (keyD == 0) continue;
												}
												if (keeey == 1)
												{
													if (D[i]->GetStaffOfEmployeesSize() == 0)
													{
														cout << "No Employees\n";
														break;
													}
													cout << "Select Employee:\n";
													for (int j = 0; j < D[i]->GetStaffOfEmployeesSize(); j++)
													{
														cout << "This? - 0 - no/ 1 - yes\n";
														cout << "Diretor: " << D[i]->GetName() << endl;
														cout << "Employee: ";
														cout << D[i]->ReturnEmployee(j + 1)->GetName() << "\n";
														ui keyE;
														cin >> keyE;
														if (keyE == 0) continue;
														if (keyE == 1)
														{
															dynamic_cast<Bookkeeper*>(D[key - 1]->ReturnEmployee(number))
																->SetSalary(D[i]->ReturnEmployee(j + 1));
															break;
														}
													}
												}
											}

										}
										if (keey == 3) 
										{
											dynamic_cast<Bookkeeper*>(D[key - 1]->ReturnEmployee(number))->ShowThis();
										}
									}
								}
								if (D[key - 1]->ReturnEmployee(number)->GetPost() == "Secretary")
								{
									// меню Secretary
									for (;;)
									{
										ui keey;
										cout << "what do you want to do?\n"
											<< " 0 - Exit Back\n"
											<< " 1 - ShowEquipmentSysAdm\n"
											<< " 2 - Show Director's Staff\n"
											<< " 3 - Show This\n"
											<< " 4 - Show Drivers" << endl;
										try
										{
											cin >> keey;
											if ((keey > 4) || (keey < 0))  throw invalid_argument("Argument too large or negative.\n");
										}
										catch (invalid_argument& e)
										{
											cerr << e.what() << endl;
											break;
										}
										if (keey == 0) break;
										if (keey == 1)
										{
											cout << "Select SysAdm: \n";
											for (int k = 0; k < D.size(); k++)
											{
												for (int k1 = 1; k1 <= D[k]->GetStaffOfEmployeesSize(); k1++)
												{
													if (D[k]->ReturnEmployee(k1)->GetPost() == "SysAdm")
													{
														D[k]->ReturnEmployee(k1)->ShowThis();
														cout << "This?: 0 - No / 1 - Yes\n";
														int kkey;
														cin >> kkey;
														if (kkey == 0) continue;
														else
														{
															dynamic_cast<Secretary*>(D[key - 1]->ReturnEmployee(number))->
																ShowEquipmentAdm(dynamic_cast<SysAdm*>(D[k]->ReturnEmployee(k1)));
														}
													}
												}
											}
										}
										if (keey == 2)
										{
											cout << "Press 0 to exit\nor select Director: \n";
											for (int i = 0, j = 1; i < D.size(); i++, j++)
											{
												cout << j;
												cout.width(25);
												cout.fill('-');
												cout << D[i]->GetName() << "\n";
											}
											int keeey;
											cin >> keeey;
											if (keeey == 0) continue;
											if (keeey > D.size())
											{
												cout << "No such Director:";
												continue;
											}
											else
											{
												dynamic_cast<Secretary*>(D[key - 1]->ReturnEmployee(number))->ShowStaffD(D[keeey - 1]);
											}
										}
										if (keey == 3)
										{
											dynamic_cast<Secretary*>(D[key - 1]->ReturnEmployee(number))->ShowThis();
										}
										if (keey == 4)
										{
											dynamic_cast<Secretary*>(D[key - 1]->ReturnEmployee(number))->GetDriversMas(D);
											dynamic_cast<Secretary*>(D[key - 1]->ReturnEmployee(number))->
												ShowDrivers((dynamic_cast<Secretary*>(D[key - 1]->ReturnEmployee(number))->DriversM));

										}
									}
								}
							}
						}
				}
			}
	}

	for (int i = 0; i < D.size(); i++)
	{
		delete D[i];
	}

	cout << "\n Diamond>> \n";
	DeathDiamond dd;
	dd.GetPost();
	system("pause");
	system("cls");

	return 0;
} 


Director* FuncAddD()
{
	string Name;
	ui S;
	cout << "Enter Name: ";
	getline(cin, Name);
	cout << "Enter Salary: ";
	cin >> S;
	cin.get();
	Director* NewDirector = new Director(Name, S);
	return NewDirector;
}

void ShowDirectors(vector <Director*> &vec)
{
	cout << "Now you have " << vec.size() << " Diretor's \n Enter the director's number to continue \n Or add a new director:\n ";
	cout << "0)Add a new director\n";
	for (int i = 0, j = 1; i < vec.size(); i++)
		cout << j++ << ")" << vec[i]->GetName() << endl;
};
