#pragma once
#include <vector>
#include <string>
#include "Client.h"
#include "Employee.h"
#include "Admin.h"
#include <fstream>
using namespace std;
class FilesHelper
{
public:
	static void saveLast(string fileName, int id) {
		ofstream last_id(fileName, ios::out);
		last_id << id;
		last_id.close();
	};

	static int getLast(string fileName) {
		ifstream get_last_id;
		get_last_id.open(fileName);

		int last_id;
		get_last_id >> last_id;
		get_last_id.close();
		return last_id;
	};

	static void saveClient(Client c) {
		ofstream add_Client("Clients.txt",ios::app);
		string client_Data =  to_string(c.get_ID()) + '&' + c.get_name() + '&' + c.get_password() + '&' + to_string(c.get_balance());
		add_Client << client_Data << '\n';
		add_Client.close();
		saveLast("Last_Client_Id.txt", c.get_ID());
	};

	static void saveEmployee(string fileName, string lastIdFile, Employee e) {
		ofstream add_Employee(fileName, ios::app);
		string Employee_Data = to_string(e.get_ID()) + '&' + e.get_name() + '&' + e.get_password() + '&' + to_string(e.get_salary());
		add_Employee << Employee_Data << '\n';
		add_Employee.close();
		saveLast(lastIdFile, e.get_ID());
	};

	static void getClients() {
		ifstream get_line;
		get_line.open("Clients.txt"); 
		string line ;
		while (getline(get_line, line)) {
			if (!line.empty())
			{
				Client c = Parser::parseTo_Client(line);
				c.Display();
				cout << "\n--------------------\n";
			}
		}
		get_line.close();
	}

	static void getEmployees() {
		ifstream get_Employee;
		get_Employee.open("Employees.txt");
		string line;
		while (getline(get_Employee,line)) {
			if (!line.empty())
			{
				Employee e = Parser::parseTo_Employee(line);
				e.Display();
				cout << "\n-----------------------\n";
			}
		}
		get_Employee.close();
	}

	static void getAdmins(){
		ifstream get_Admins;
		get_Admins.open("Admin.txt");
		string line;
		while (getline(get_Admins,line)) {
			if (!line.empty())
			{
				Admin a = Parser::parseTo_Admin(line);
				a.Display();
				cout << "\n-----------------------\n";
			}
		}
		get_Admins.close();
	}

	static void clearFile(string fileName, string lastIdFile) {
		ofstream (fileName,ios::trunc).close();  // shortcut instead of creating objects and opening files. 
		ofstream (lastIdFile,ios::trunc).close();
	}

};

