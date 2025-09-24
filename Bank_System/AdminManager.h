#pragma once
#include <iostream>
#include "Employee.h"
#include "Client.h"
#include "admin.h"
#include "EmployeeManager.h"
#include "ClientManager.h"
#include "FileManager.h"
#include <windows.h>
using namespace std;
class AdminManager
{

	static void printEmployeeMenu() {
		cout << "\nChoose Number of operation: \n";
		cout << " 1  ---> Add New Employee \n";
		cout << " 2  ---> search For Employee\n";
		cout << " 3  ---> Edit Employee \n";
		cout << " 4  ---> Display All Employees\n";
		cout << " 5  ---> Display my Info \n";
		cout << " 6  ---> Add New Client \n";
		cout << " 7  ---> Search For Client \n";
		cout << " 8  ---> Display All Clients\n";
		cout << " 9 ---> Edit Client\n";
		cout << " 10 ---> Update password\n";
		cout << " 11  ---> Logout \n";
	}

	static void newEmployee(Admin* admin) {
			int id;
			string name;
			string password;
			double salary;
			cout << "New Employee ID: ";
			cin >> id;
			cin.ignore();
			cout << "New Employee Name: ";
			getline(cin, name);
			while (!Validation::validate_Name(name)) {
				cout << "Invalid Name, Please enter correct name..!\n";
				getline(cin, name);
			}
			cout << "New Employee Password: ";
			cin >> password;
			while (!Validation::validate_Password(password)) {
				cout << "Invalid password, It must be at least 8 chars..!\n";
				cin >> password;
			}
			cout << "New Employee Salary: ";
			cin >> salary;
			while (!Validation::validate_Salary(salary)) {
				cout << "Invalid salary , It must be at least 5000..!\n";
				cin >> salary;
			}
			Employee e(name, password, id, salary);
			admin->add_New_Employee(e);
			FileManager::addEmployee(e);
			system("cls");
			cout << "\n\nNew Employee Added Successfully\n\n";
	}

	static void searchForEmployee(Admin* admin) {
		int id;
		cout << "Enter The Employee ID: ";
		cin >> id;
		Employee* is_found = admin->search_Employee(id);
		if (is_found != nullptr)
		{
			Sleep(1000);
			system("cls");
			cout << "This Employee Is Already Exist \n";
		}
		else
		{
			cout << "This Employee Is Not Exist:\n ";
		}
	}

	static void listAllEmployees(Admin* admin ) {
		admin->list_Employees();
	}

	static void editEmployeeInfo(Admin* admin) {
		int id;
		string name;
		string password;
		double salary;
		cout << "Employee ID: ";
		cin >> id;
		cin.ignore();
		cout << "Employee Name: ";
		getline(cin, name);
		while (!Validation::validate_Name(name)) {
			cout << "Invalid Name, Please enter correct name..!\n";
			getline(cin, name);
		}
		cout << "Employee Password: ";
		cin >> password;
		while (!Validation::validate_Password(password)) {
			cout << "Invalid password, It must be at least 8 chars..!\n";
			cin >> password;
		}
		cout << "Employee salary: ";
		cin >> salary;
		while (!Validation::validate_Salary(salary)) {
			cout << "Invalid salary , It must be at least 5000..!\n";
			cin >> salary;
		}
		if (admin->search_Employee(id) != nullptr)
		{
			admin->edit_Employee(id, name, password, salary);
			FileManager::Last_update_for_Employees();
			cout << "You Edit Employee Info Successfully..!";
		}
		else
		{
			cout << "Employee with ID " << id << " not found!\n";
		}
	}
public:
	static Admin* login(int id, string password) {
		for (A_itr = all_Admins.begin(); A_itr != all_Admins.end(); A_itr++)
		{
			if (A_itr->get_ID() == id && A_itr->get_password() == password) {
				return &(*A_itr);
			}
		}
		return nullptr;
	}


	static void AdminOptions(Admin* admin) {
		bool flag = true;
		while (flag) {
		printEmployeeMenu();
		int option;
		cout << "\nEnter Number of operation: ";
		cin >> option;
		system("cls");
		switch (option)
		{
		case 1:
			newEmployee(admin);
			break;
		case 2:
			searchForEmployee(admin);
			break;
		case 3:
			editEmployeeInfo(admin);
			break;
		case 4:
			listAllEmployees(admin);
			break;
		case 5:
			admin->Display();
			break;
		case 6:
			EmployeeManager::newClient(admin);
			break;
		case 7:
			EmployeeManager::searchForClient(admin);
			break;
		case 8:
			EmployeeManager::listAllClients(admin);
			break;
		case 9:
			EmployeeManager::editClientInfo(admin);
			break;
		case 10:
			ClientManager::Update_Password(admin);
			FileManager::Last_update_for_Admins();
			break;
		case 11:
			flag = false;
			break;
		default:
			cout << "Invalid choice. Please enter 1–7.\n";
			 }
		 }	
	}



};

