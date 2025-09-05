


#include <iostream>
#include<vector>
#include "Client.h"
#include "Employee.h"
#include "Admin.h"
using namespace std;


	
		
	


int main()
{


	Client a("Mohamed Hamed", "387h8t23", 23, 8000);
	Client b("Ahmed Ali", "387h8t23", 3, 8000);
	b.transferTo(3000,a);
	b.Display();
	cout << endl;
	cout << endl;
	a.Display();

	cout << endl;
	cout << endl;
	Employee d("Ali Mohamed", "lieu4378", 26, 5600);
	d.Display();


	// ------------- Errors -------------
	d.set_password("324vf");
	d.set_Name("vdjk3");
	d.set_salary(12);
	a.set_balance(12);

}

