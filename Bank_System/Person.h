#pragma once
#include <string>
#include<iostream>
#include"Validation.h"
using namespace std;


class Person
{
	int id ;
	string name;
	string password;

public:
	Person() {
	};
	Person(string name, string password, int id ):id(id) {
		set_id(id);
		if (Validation::validate_Name(name))
		{
			this->name = name;
		}
		else
		{
			cout << "Wrong Name , it must be alphabetic \n";
		}

		if (Validation::validate_Password(password) )
		{
			this->password = password;
		}
		else {
			cout << "Wrong Password , it must be at least 8 characters \n" ;
		}

	}
	void set_Name(string name) {
		if (Validation::validate_Name(name))
		{
			this->name = name;
		}
		else {
			cout << "Wrong Name , it must be alphabetic \n";
		}
	}
	void set_password(string password) {
		if (Validation::validate_Password(password))
		{
			this->password = password;
		}
		else {
			cout << "Wrong Password , it must be at least 8 characters \n";
		}
	}
	void set_id(int id) {
		this->id = id;
	}
	int get_ID() {
		return id;
	}
	string get_name() {
		return name;
	}
	string get_password() {
	/*	string pass;
		
		for (int i = 0; i < password.size(); i++)
		{
			if (i < 3)
			{
				pass += password[i];
			}
			else {
				pass += '*';
			}
		}*/

		return password;
	}
	virtual void Display() {
		cout << "Name: " << get_name() << endl;
		cout << "Password: " << get_password() << endl;
		cout << "ID: " << get_ID() << endl;
	};

};

