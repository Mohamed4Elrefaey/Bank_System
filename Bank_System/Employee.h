#pragma once
#include "Person.h"
#include <vector>
using namespace std;
class Employee :
    public Person
{
    double Salary;

public:
    Employee() :Person() {
        Salary = 0.0;
    }
    Employee(string name, string password, int id, double salary) :Person(name, password, id) {
        if (Validation::validate_Salary(salary))
        {
            this->Salary = salary;
        }
    }

    void set_salary(double salary) {
        if (Validation::validate_Salary(salary) )
        {
            this->Salary = salary;
        }
        else {
            cout << "Invalid salary, it must be 5000 at least \n";
            return;
        }
    }
    double get_salary() {
        return Salary;
    }
    void Display() {
        Person::Display();
        cout << "Salary: " << Salary << endl;
    }

    void add_New_Client(Client& c) {
        all_Clients.push_back(c);
    }

    Client* search_Client(int id) {
        for (C_itr = all_Clients.begin() ; C_itr != all_Clients.end() ; C_itr++)
        {
            if (C_itr->get_ID() == id) {
                return &(*C_itr);
            }
        }
        return nullptr;
    }

    void list_Client() {
        for (C_itr = all_Clients.begin(); C_itr != all_Clients.end(); C_itr++)
        {
            C_itr->Display();
            cout << "\n\n --------------------- \n\n";
        }
    }

    void edit_Client(int id, string name, string password, double balance) {
        Client* search = search_Client(id);  // this function return address or nullptr;
        if (search != nullptr)
        {
            search->set_Name(name);
            search->set_balance(balance);
            search->set_password(password);
        }
    }

};


static vector<Employee> all_Employees;
static vector<Employee>::iterator E_itr;
