#pragma once
#include "Employee.h"
class Admin :
    public Employee
{
    double Salary ;
public:
    Admin() :Employee() {
        Salary = 0.0;
    };

    Admin(string name, string password, int id, double salary) 
        :Employee(name, password, id,salary) {
    }

    void add_New_Employee(Employee& e) {
        all_Employees.push_back(e);
    }

    Employee* search_Employee(int id) {
        for (E_itr = all_Employees.begin(); E_itr != all_Employees.end(); C_itr++)
        {
            if (E_itr->get_ID() == id) {
                return &(*E_itr);
            }
        }
        return nullptr;
    }

    void list_Employees() {
        for (E_itr = all_Employees.begin(); E_itr != all_Employees.end(); C_itr++)
        {
            E_itr->Display();
            cout << "\n --------------------- \n";
        }
    }

    void edit_Employee(int id, string name, string password, double salary) {
        Employee* search = search_Employee(id);  // this function return address or nullptr;
        if (search != nullptr)
        {
            search->set_Name(name);
            search->set_salary(salary);
            search->set_password(password);
        }
    }

};

static vector<Admin> all_Admins;
static vector<Admin>::iterator A_itr;