#pragma once
#include<iostream>
#include "admin.h"
#include "Employee.h"
#include "Client.h"
#include "AdminManager.h"
#include "ClientManager.h"
#include "EmployeeManager.h"
#include "FileManager.h"
#include <windows.h>

using namespace std;

class Screen
{

	static void Bank_name() {
		cout << "\n   In CIB  BANK  ";
	}


	static void welcome() {
		cout << "\n  Welcome To You ";
		Bank_name();
		Sleep(3000); 
		system("cls");
		system("color 01"); // Blue
	}


	static void loginOptions() {
		cout << "  1 ---> Admin  \n";
		cout << "  2 ---> Employee\n";
		cout << "  3 ---> Client \n";
		cout << "  4 ---> Close APP \n";
	}

	static int loginAs() {
		int as;
		while (true) {
			loginOptions();
			cout << "Login as: ";
			cin >> as;
			if (as > 0 && as <= 4)
			{
				system("cls");
				return as;
			}
			else
			{
				system("cls");
				cout << "This number out of options..!\n";
			}
		}
	}

	static void logout() {
		system("cls");
		loginAs();
	}

	static void invalid(int c) {
		system("cls");
		cout << "Incorrect Id or Password..!\n";
		loginScreen(c);
	}

	static void loginScreen(int c) {
		if (c > 3 || c < 1)
		{
			system("cls");
			cout << "\nThank You For Dealing With Us , CIB Bank\n";
			Sleep(1000);
			system("cls");
			return;
		}
		int id;
		string pass;
		cout << "Enter ID: ";
		cin >> id;
		cout << "Enter Password: ";
		cin >> pass;
		switch (c)
		{
		case 1:{
			Admin * a = AdminManager::login(id, pass);
			if (a != nullptr)
			{
				system("cls");
				cout << "\nYou have logged in successfully\n";
				AdminManager::AdminOptions(a);
				logout();
			}
			else
				invalid(1);
			break;
		}
		case 2:{
			Employee * e = EmployeeManager::login(id, pass);
			if (e != nullptr)
			{
				system("cls");
				cout << "\nYou have logged in successfully\n";
				EmployeeManager::employeeOptions(e);
				logout();
			}
			else
				invalid(2);
			break;
		}
		case 3: {
			Client* c = ClientManager::Login(id, pass);
			if (c != nullptr)
			{
				system("cls");
				cout << "\nYou have logged in successfully\n";
				ClientManager::Client_Options(c);
				logout();
			}
			else
				invalid(3);
			break;
		}
		default:
			system("cls");
			cout << "\nThank You For Dealing With Us , CIB Bank\n";
			Sleep(1000);
			system("cls");
		}

	}



	public:
	static void runApp() {
		FileManager::get_All_Data();  // all Clients  --- all Employees -- all Admins
		welcome();
		loginScreen(loginAs());

	}



};

