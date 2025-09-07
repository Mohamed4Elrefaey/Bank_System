


#include <iostream>
#include <sstream>
#include "Parser.h"
#include<vector>
#include "Client.h"
#include "Employee.h"
#include "FilesHelper.h"
#include "Admin.h"
using namespace std;


	
		
	


int main()
{
	Client a;
	a.set_id(3);
	a.set_Name("Ali");
	a.set_password("1m4j348fs");
	a.set_balance(4500);

	Employee e("Mohamed Hamed", "jnb2794fg", 1, 8000);
	FilesHelper::saveEmployee("Employees.txt",)

	//FilesHelper::getClients();


	/*a.Display();
	cout << "\n------------------\n";
	string line = "12&Mohamed Hamed&mh018743&5000";


	Client c =  Parser::parseTo_Client(line);

	c.Display();*/


	// ------------ for test split function 
	//vector<string> Parts = Parser::split(line);
	vector<string>::iterator itr;
	/*for ( itr  = Parts.begin(); itr != Parts.end(); itr++)
	{
		cout << *itr << endl;
	}*/

	//cout << Parts[3];


	// ------------  string stream  ------------
	// 
	//stringstream  ss(line);
	//string id; 
	//string name1 ; 
	//string pass;
	//string salary;

	//getline(ss, id, '&');   
	//getline(ss, name1, '&');
	//getline(ss, pass, '&');
	//getline(ss, salary);


	//cout << "ID: " << id << endl;
	//cout << "Name: " << name1  << endl;
	//cout << "Password: " << pass << endl;
	//cout << "Salary: " << salary << endl;


	//Client a("Mohamed Hamed", "387h8t23", 23, 8000);
	//Client b("Ahmed Ali", "387h8t23", 3, 8000);
	//b.transferTo(3000,a);
	//b.Display();
	//cout << endl;
	//cout << endl;
	//a.Display();

	//cout << endl;
	//cout << endl;
	//Employee d("Ali Mohamed", "lieu4378", 26, 5600);
	//d.Display();


	//// ------------- Errors -------------
	//d.set_password("324vf");
	//d.set_Name("vdjk3");
	//d.set_salary(12);
	//a.set_balance(12);

}

