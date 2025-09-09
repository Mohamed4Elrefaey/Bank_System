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
		int id = getLast("Last_Client_Id.txt");
		string client_Data =  to_string(id + 1) + '&' + c.get_name() + '&' + c.get_password() + '&' + to_string(c.get_balance());
		add_Client << client_Data << '\n';
		add_Client.close();
		saveLast("Last_Client_Id.txt", id + 1);
	};

	static void saveEmployee(string fileName, string lastIdFile, Employee e) {
		ofstream add_Employee(fileName, ios::app);
		int id = getLast(lastIdFile);
		string Employee_Data = to_string(id+1) + '&' + e.get_name() + '&' + e.get_password() + '&' + to_string(e.get_salary());
		add_Employee << Employee_Data << '\n';
		add_Employee.close();
		saveLast(lastIdFile, id+1);
	};

	static void getClients() {
		ifstream get_line;
		get_line.open("Clients.txt"); 
		string line ;
		while (getline(get_line, line)) {
			if (!line.empty())
			{
				Client c = Parser::parseTo_Client(line);
				all_Clients.push_back(c);
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
				all_Employees.push_back(e);
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
				all_Admins.push_back(a);
			}
		}
		get_Admins.close();
	}

	static void clearFile(string fileName, string lastIdFile) {
		ofstream (fileName,ios::trunc).close();  // shortcut instead of creating objects and opening files. 
		ofstream Id_File;
		Id_File.open(lastIdFile, ios::out);  // here we use out mode to delete last id and write new one . 
		Id_File << 0;   // to handle first id to be 1 
		Id_File.close();
	}

};

