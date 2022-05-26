#pragma once
#include <iostream>
#include "Employee.h"

using std::invalid_argument;
using std::cerr;

class Driver :
    public Employee
{
    private:
        vector <char> DriversLicense{'A','B','C','D'};
        vector <string> TransportList;
    public:
        friend class Bookkeeper;
        friend class Secretary;
        Driver(const string& FullName = "Nullbody", ui Salary = 0);
        void GetTransport();
        void ShowTransportList();
        void ShowDriversLicenseList();
        void DeleteTransport();
        void ShowThis();
};

