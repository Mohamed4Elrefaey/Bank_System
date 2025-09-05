#pragma once
#include "Person.h"
class Client :
    public Person
{

    double balance;

public:
    Client(string name, string password, int id, double balance):Person(name,password,id) {
        if (Validation::validate_Balance(balance) == true)
        {
            this->balance = balance;
        }
        else {
            cout << "Invalid balance, it must be at least 1500 \n ";
        }
    }

    void set_balance(double balance) {
        if (Validation::validate_Balance(balance) == true)
        {
            this->balance = balance;
        }
        else {
            cout << "Invalid Balance, it must be at least 1500 \n";
        }
    }

    double get_balance() {
        return balance;
    }

    void deposit(double balance) {
        this->balance = balance;
    }

    void withdraw(double amount) {
        if (amount <= 0)
        {
            return;
        }
        if (balance >= amount)
        {
            balance -= amount;
        }
        else {
            return;
        }
    }

    void transferTo(double amount, Client& obj) {
        if (amount <= 0)
        {
            return;
        }
        if (balance >= amount)
        {
            balance -= amount;
            obj.balance += amount;
        }
    }

    void checkBalance() {
        cout << "Balance: " << this->balance;
    }

    void Display() {
        Person::Display();
        cout << "Balance: " << balance << endl;
    }

};

