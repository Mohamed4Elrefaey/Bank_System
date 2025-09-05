#pragma once
#include "Person.h"
class Employee :
    public Person
{
    double Salary;

public:

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

};

