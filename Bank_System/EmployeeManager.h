#pragma once
#include"Employee.h"
#include "Client.h"
class EmployeeManager
{
public:
	static void printEmployeeMenu() {
		cout << "   Choose Number of Operation: \n";
		cout << " 1  ---> Add New Client \n";
		cout << " 2  ---> search For Client\n";
		cout << " 3  ---> Edit Client \n";
		cout << " 4  ---> Display All Clients \n";
		//cout << " 5  ---> Back To Main Screen \n";
		cout << " 6  ---> Display Info \n";
		cout << " 7  ---> Close Program \n";
	}

	static void newClient(Employee* employee) {
		int id;
		string name;
		string password;
		double balance;
		cout << "New Client ID: ";
		cin >> id;
		cin.ignore();
		cout << "New Client Name: ";
		getline(cin, name);
		while (!Validation::validate_Name(name)) {
			cout << "Invalid Name, Please enter correct name..!\n";
			getline(cin, name);
		}
		cout << "New Client Password: ";
		cin >> password;
		while (!Validation::validate_Password(password)) {
			cout << "Invalid password, It must be at least 8 chars..!\n";
			cin >> password;
		}
		cout << "New Client Balance: ";
		cin >> balance;
		while (!Validation::validate_Balance(balance)) {
			cout << "Invalid Balance , It must be at least 1500..!\n";
			cin >> balance;
		}
		Client c(name, password, id, balance);
		employee->add_New_Client(c);
		cout << "New Client Added ";
	}

	static void listAllClients(Employee* employee) {
		employee->list_Client();
	}


	static void searchForClient(Employee* employee) {
		int id;
		cout << "Enter The Client ID: ";
		cin >> id;
		Client* is_found = employee->search_Client(id);
		if (is_found != nullptr )
		{
			cout << "This Client Is Already Exist ";
		}
		else
		{
			cout << "This Client Is Not Exist: ";
		}
	}

	static void editClientInfo(Employee* employee) {
		int id;
		string name;
		string password;
		double balance;
		cout << "Client ID: ";
		cin >> id;
		cin.ignore();
		cout << "Client Name: ";
		getline(cin, name);
		while (!Validation::validate_Name(name)) {
			cout << "Invalid Name, Please enter correct name..!\n";
			getline(cin, name);
		}
		cout << "Client Password: ";
		cin >> password;
		while (!Validation::validate_Password(password)) {
			cout << "Invalid password, It must be at least 8 chars..!\n";
			cin >> password;
		}
		cout << "Client Balance: ";
		cin >> balance;
		while (!Validation::validate_Balance(balance)) {
			cout << "Invalid Balance , It must be at least 1500..!\n";
			cin >> balance;
		}
		if (employee->search_Client(id) != nullptr)
		{
			employee->edit_Client(id, name, password, balance);
			cout << "You Edit Client Info Successfully..!";
		}
		else
		{
			cout << "Client with ID " << id << " not found!\n";
		}
	}


	static Employee* login(int id, string password) {
		for (E_itr = all_Employees.begin(); E_itr != all_Employees.end(); E_itr++)
		{
			if (E_itr->get_ID() == id && E_itr->get_password() == password) {
				return &(*E_itr);
			}
		}
		return nullptr;
	}


	static bool employeeOptions(Employee* employee) {
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
				newClient(employee);
				break;
			case 2:
				searchForClient(employee);
				break;
			case 3:
				editClientInfo(employee);
				break;
			case 4:
				listAllClients(employee);
				break;
			case 6:
				employee->Display();
				break;
			case 7:
				cout << "Closing program. Thank you!";
				flag = false;
				break;
			default:
				cout << "Invalid choice. Please enter 1–7.\n";
			}
		}
		return false;
	}

};

