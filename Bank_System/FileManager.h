#pragma once
#include "DataSourceInterface.h"
#include "FilesHelper.h"
class FileManager
{
public:
	static void addClient(Client obj) {
		FilesHelper::saveClient(obj);
	}

	static void addEmployee(Employee obj) {
		FilesHelper::saveEmployee("Employees.txt","Last_Employee_Id.txt",obj);
	}

	static void addAdmin(Admin obj) {
		FilesHelper::saveEmployee("Admin.txt", "Last_Admin_Id.txt", obj);
	}

	static void getAllClients() {
		FilesHelper::getClients();
	}

	static void getAllEmployees() {
		FilesHelper::getEmployees();
	}

	static void getAllAdmins() {
		FilesHelper::getAdmins();
	}

	static void removeAllClients() {
		FilesHelper::clearFile("Clients.txt", "Last_Client_Id.txt");
	}

	static void removeAllEmployees() {
		FilesHelper::clearFile("Employees.txt", "Last_Employee_Id.txt");
	}

	static void removeAllAdmins() {
		FilesHelper::clearFile("Admin.txt", "Last_Admin_Id.txt");
	}

	static void Last_update_for_Clients() {  // incase i update specific client 
		removeAllClients();
		for (C_itr = all_Clients.begin(); C_itr != all_Clients.end(); C_itr++)
		{
			addClient(*C_itr);
		}
	}

	static void get_All_Data() {
		getAllClients();
		getAllEmployees();
		getAllAdmins();
	}

	static void Last_update_for_Employees() {
		removeAllEmployees();
		for (E_itr = all_Employees.begin(); E_itr != all_Employees.end(); E_itr++)
		{
			addEmployee(*E_itr);
		}
	}

	static void Last_update_for_Admins() {
		removeAllAdmins();
		for (A_itr = all_Admins.begin(); A_itr != all_Admins.end(); A_itr++)
		{
			addAdmin(*A_itr);
		}
	}



};

