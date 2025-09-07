#pragma once
#include "Employee.h"
class Admin :
    public Employee
{
    double Salary;

public:
    Admin() :Employee() {

    };
    Admin(string name, string password, int id, double salary) 
        :Employee(name, password, id,salary) {

    }

};

