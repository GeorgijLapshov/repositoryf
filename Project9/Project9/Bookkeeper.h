#pragma once
#include "Employee.h"
#include "Director.h"

using std::invalid_argument;
using std::cerr;

class Bookkeeper :
    public Employee
{
private:
    ui minDiretor = 7500;
    ui minBookkeeper = 4500;
    ui minSysAdm = 4000;
    ui minDriver = 2500;
    ui minSecretary = 3500;
public:
    Bookkeeper(const string& FullName = "Nullbody", ui Salary = 0);
    void SetSalary(Employee* E);
    void SetMin();
    void ShowThis();
};