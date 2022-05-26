#pragma once
#include <iostream>
#include <vector>
#include "Employee.h"

using std::string;
using std::invalid_argument;
using std::cerr;

class SysAdm :
    public Employee
{
    private:
        vector <string> Equipmentlist;
    public:
        friend class Bookkeeper;
        friend class Secretary;
        SysAdm(const string& FullName = "Nullbody", ui Salary = 0);
        void GetEquipment(); // получение оборудования
        void ShowEquipmentlist(); // показ
        void DeleteEquipment(int num); // удаление
        ui GetEquipmentlistsize();// количество оборудования
        void ShowThis();// переопределенный абтрактный метод
};

