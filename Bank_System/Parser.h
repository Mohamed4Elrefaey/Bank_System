#pragma once
#include <vector>
#include <string>
#include <sstream>
#include "Client.h"
#include "Employee.h"
#include "admin.h"

using namespace std;

class Parser
{
	static vector<string> split(string line) {
		vector<string> outComes{};
		stringstream parts_of_line(line);

		string part;
		for (int i = 0; i < 4 ; i++)
		{
			if (i == 3)
			{
				getline(parts_of_line, part);
				outComes.push_back(part);
				break;
			}
			getline(parts_of_line, part, '&');
			outComes.push_back(part);
		}
		return outComes;
	};

public:
	static Client parseTo_Client(string line) {
		vector<string> Parts = split(line);
		int id = stoi(Parts[0]);
		string name = Parts[1];
		string password = Parts[2];
		double balance = stod(Parts[3]);
		return Client(name, password, id, balance);
	};

	static Employee parseTo_Employee(string line) {
		vector<string> Parts = split(line);
		int id = stoi(Parts[0]);
		string name = Parts[1];
		string password = Parts[2];
		double salary = stod(Parts[3]);
		return Employee(name, password, id, salary);

	};

	static Admin parseTo_Admin(string line) {
		vector<string> Parts = split(line);
		int id = stoi(Parts[0]);
		string name = Parts[1];
		string password = Parts[2];
		double salary = stod(Parts[3]);
		return Admin(name, password, id, salary);

	};


};

