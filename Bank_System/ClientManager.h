#pragma once
using namespace std;
#include<iostream>
#include "Person.h"
#include "Client.h"
#include "Employee.h"
class ClientManager
{
	static Client* search_Client(int id) {
		for (C_itr = all_Clients.begin(); C_itr != all_Clients.end(); C_itr++)
		{
			if (C_itr->get_ID() == id ) {
				return &(*C_itr);
			}
		}
		return nullptr;
	}


public:
	static void PrintClientMenu() {
		cout << "Choose Number Of Operation\n\n--------------------------\n\n";
		cout << "	 1  ---> Deposit \n";
		cout << "	 2  ---> Withdraw\n";
		cout << "	 3  ---> Transfer To \n";
		cout << "	 4  ---> Check Balance \n";
		cout << "	 5  ---> Display Info \n";
		cout << "	 6  ---> Update Password \n";
		cout << "	 7  ---> Close program\n";
		//cout << "	 8  ---> Back To Login screen\n";
	}

	static void Update_Password(Person* person) {
		string new_pass;
		cout << "Enter New Password: ";
		cin >> new_pass;
		while (!Validation::validate_Password(new_pass)) {
			cout << "Invalid Password. Try again: ";
			cin >> new_pass;
		}
		person->set_password(new_pass);
		cout << "Password updated successfully.\n";
	}


	static Client* Login(int id , string password) {
		for (C_itr = all_Clients.begin(); C_itr != all_Clients.end(); C_itr++)
		{
			if (C_itr->get_ID() == id && C_itr->get_password() == password) {
				return &(*C_itr);
			}
		}
		return nullptr;
	}

	static void Client_Options(Client* client) {
		bool flag = true;
		while (flag) {
			PrintClientMenu();
			int option;
			cout << "\nEnter Number of operation: ";
			cin >> option;
			system("cls");
			switch (option)
			{
			case 1:{
				double amount;
				cout << "Enter deposit amount: ";
				cin >> amount;
				client->deposit(amount);
				break;
			}
			case 2:{
				double amount;
				cout << "Enter the amount of money: ";
				cin >> amount;
				client->withdraw(amount);
				break;
			}
			case 3:
				double money;
				int id;
				cout << "Enter the amount of money: ";
				cin >> money;
				cout << "Enter the ID of the person that you want transfer to: ";
				cin >> id;
				while (true) {
					Client* c = search_Client(id);
					if (c != nullptr)
					{
						client->transferTo(money, *c);
						break;
					}
					else {
						cout << "Invalid ID , Please enter correct one: ";
						cin >> id;
					}
				}
				break;
			case 4:
				client->checkBalance();
				break;
			case 5:
				client->Display();
				break;
			case 6:
				Update_Password(client);
				break;
			case 7:
				flag = false;
				break;
			default:
				cout << "Invalid choice. Please enter 1–7.\n";
			}
		}
	}
};

