#pragma once
#include<iostream>
#include "admin.h"
#include "Employee.h"
#include "Client.h"
#include "AdminManager.h"
#include "ClientManager.h"
#include "EmployeeManager.h"
#include "FileManager.h"
using namespace std;

class Screen
{

	static void Bank_name() {
		cout << "\t\t	  ######  ######  ########		########	  #####		###		 ##	 ##	    ## \n";
		cout << "\t\t	##          ##    ##     ##		##     ##	##	   ##	## ##    ##	 ##	  ##\n";
		cout << "\t\t ##	        ##    ##    ##		##    ##	##	   ##	##	##	 ##	 ##	 ##	\n";
		cout << "\t\t ##		    ##	  ######		######		#########	##	 ##	 ##	 ### \n";
		cout << "\t\t ##		    ##    ##    ##		##    ##	##	   ##	##	  ## ##	 ##	##\n";
		cout << "\t\t	##		    ##    ##     ##		##     ##	##	   ##	##	   ####	 ##	 ## \n";
		cout << "\t\t	 ######	  ######  ########		########	##	   ##	##		###	 ##	   ##\n";
	}


	static void welcome() {
		cout << "##       ##   ########	 ##			    #####	 #####   ###     ###  ########\n";
		cout << "##       ##   ##		 ##			  ##		##	 ##	 ## ## ## ##  ##\n";
		cout << "##   #   ##   ##		 ##			 ##			##	 ##	 ##  ###  ##  ##\n";
		cout << "##   #   ##   ######	 ##		    ##			## 	 ##	 ##   #   ##  ######\n";
		cout << "##  ###  ##   ##		 ##			 ##			##	 ##	 ##   #   ##  ##\n";
		cout << "## ## ## ##   ##		 ##		      ##		##	 ##  ##       ##  ##\n";
		cout << "###     ###   ########	 ######## 	    #####	 #####	 ##       ##  ########\n";
		Bank_name();
		_sleep(4000);
		system("cls");
		system("color 01");
	}


	static void loginOptions() {
		cout << "  1 ---> Admin  \n";
		cout << "  2 ---> Employee\n";
		cout << "  3 ---> Client \n";
	}


	static int loginAs() {
		int as;
		while (true) {
			loginOptions();
			cout << "Login as: ";
			cin >> as;
			if (as > 0 && as <= 3)
			{
				system("cls");
				return as;
			}
			else
			{
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
		int id;
		string pass;
		cout << "Enter ID: ";
		cin >> id;
		cout << "Enter Password";
		cin >> pass;
		switch (c)
		{
		case 1:
			Admin * a = AdminManager::login(id, pass);
			if (a != nullptr)
			{
				AdminManager::AdminOptions(a);
				logout();
			}
			else
				invalid(1);
			break;
		case 2:
			Employee * e = EmployeeManager::login(id, pass);
			if (e != nullptr)
			{
				EmployeeManager::employeeOptions(e);
				logout();
			}
			else
				invalid(2);
			break;
		case 3:
			Client * c = ClientManager::Login(id, pass);
			if (c!=nullptr)
			{
				ClientManager::Client_Options(c);
				logout();
			}
			else
				invalid(3);
			break;
		default:
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

