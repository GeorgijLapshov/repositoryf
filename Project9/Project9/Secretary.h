#pragma once
#include "Director.h"
#include "SysAdm.h"
#include "Driver.h"
#include "Employee.h"

class Secretary :
    public Employee
{
    public:
    vector<Driver*> DriversM;
    Secretary(const string& FullName = "Nullbody", ui Salary = 0);
    void ShowStaffD(Director* D);
    void ShowEquipmentAdm(SysAdm*);
    void ShowThis();
    void ShowDrivers(vector <Driver*> Drv);
    void GetDriversMas(vector <Director*> vD );
 
};