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
        void GetEmployee(); //���� ����������
        void DeleteEmployee(int num); // ���������� ����������
        void ShowEmployee(int num) const; // ��������� ����������
        void ShowEmployees() const; // ���������� � ���� ����� �����������
        int GetStaffOfEmployeesSize() { return(StaffOfEmployees.size()); }; // ��������� ���������� ����������
        Employee* ReturnEmployee(ui num); // ���������� ��������� �� ����������
        void ShowThis();// ���������������� ���������� �����
};

