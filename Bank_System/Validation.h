#pragma once
#include<string>
using namespace std;
class Validation
{

public:

	static bool validate_Name(string name) {
		if (name.size() < 3 || name.size() > 20 || name.empty())
		{
			return false;
		}
		for (int i = 0; i < name.size(); i++)
		{
			if (!(isalpha(name[i]) || name[i] == ' ')) {
				return false;
			}
		}
		return true;
	}

	static bool validate_Password(string pass) {
		if (pass.size() < 8 || pass.size() > 20 || pass.empty())
		{
			return false;
		}
		for (int i = 0; i < pass.size(); i++)
		{
			if (pass[i] == ' ') {
				return false;
			}
		}
		return true;
	}

	static bool validate_Balance(double balance) {
		return balance >= 1500;
	}

	static bool validate_Salary(double salary) {
		return salary >= 5000;
	}

};

