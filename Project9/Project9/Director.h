#pragma once
#include <iostream>
#include <vector>
#include "Employee.h"
#include "SysAdm.h"
#include "Driver.h"
#include "Bookkeeper.h"
//#include "Secretary.h"

using std::vector;
using std::string;
using std::invalid_argument;
using std::cerr;

class Director :
    public Employee
{
    private:
        vector <Employee*> StaffOfEmployees;
        
    public:
        friend class Bookkeeper;
        friend class Secretary;
        Director(const string& FullName = "Nullbody", ui Salary = 0);
        void GetEmployee(); //найм сотрудника
        void DeleteEmployee(int num); // увольнение сотрудника
        void ShowEmployee(int num) const; // инфорация сотрудника
        void ShowEmployees() const; // информация о всем штате сотрудников
        int GetStaffOfEmployeesSize() { return(StaffOfEmployees.size()); }; // получение количества сотруднков
        Employee* ReturnEmployee(ui num); // возвращает указатель на сотрудника
        void ShowThis();// переопределенный абтрактный метод
};

