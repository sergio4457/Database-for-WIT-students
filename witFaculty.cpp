//// Object Oriented Programming Final Project
// Group: Sergio Pina, Patrick Yepmo, Rafael Barbosa
#include "stdafx.h"
#include <string>
#include <iostream>
using namespace std;
#include "witFaculty.h"

WITFaculty::WITFaculty(void) 
{
	name = "";
	address = "";
	wNum = "";
	role = "Faculty";
}

WITFaculty::WITFaculty(string name, string add, string num) 
{
	WITPerson::name = name;
	WITPerson::address = add;
	WITPerson::wNum = num;
	WITPerson::role = "Faculty";
	cout << "Please Enter The Faculty Income: " << endl;
	cin >> pay;
	hours_worked = 1; 
}
WITFaculty::WITFaculty(string name, string add, string num, string salary) 
{
	WITPerson::name = name;
	WITPerson::address = add;
	WITPerson::wNum = num;
	WITPerson::role = "Faculty";
	WITPerson::pay = salary;
	hours_worked = 1;
}
WITFaculty::~WITFaculty(void) 
{	cout << "Destructor\n ";   }

string WITFaculty::payMe(void)
{	return ("Name: " + this->name + " Income: $" + pay);   }

WITFaculty & WITFaculty::operator=(const WITFaculty & Obj) 
{
	name = Obj.name;
	address = Obj.address;
	wNum = Obj.wNum;
	role = Obj.role;
	return *this;
}


