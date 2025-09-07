#pragma once
#include "DataSourceInterface.h"
#include "FilesHelper.h"
class FileManager
{

	void addClient(Client obj) {
		FilesHelper::saveClient(obj);
	}

	void addEmployee(Employee obj) {
		FilesHelper::saveEmployee("Employees.txt","Last_Employee_Id.txt",obj);
	}

	void addAdmin(Admin obj) {
		FilesHelper::saveEmployee("Admin.txt", "Last_Admin_Id.txt", obj);
	}

	void getAllClients() {
		FilesHelper::getClients();
	}

	void getAllEmployees() {
		FilesHelper::getEmployees();
	}

	void getAllAdmins() {
		FilesHelper::getAdmins();
	}

	void removeAllClients() {
		FilesHelper::clearFile("Clients.txt", "Last_Client_Id.txt");
	}

	void removeAllEmployees() {
		FilesHelper::clearFile("Employees.txt", "Last_Employee_Id.txt");
	}

	void removeAllAdmins() {
		FilesHelper::clearFile("Admin.txt", "Last_Admin_Id.txt");
	}

};

